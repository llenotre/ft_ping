#include <signal.h>
#include <stddef.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "../libft/libft.h"
#include "ping.h"

__attribute__((packed))
struct ipv4_datagram
{
	uint8_t version;
	uint8_t tos;
	uint16_t length;

	uint16_t identification;
	uint16_t flags_offset;

	uint8_t ttl;
	uint8_t protocol;
	uint16_t hdr_checksum;

	uint8_t src[4];
	uint8_t dst[4];
};

__attribute__((packed))
struct icmp_packet
{
	struct ipv4_datagram ip_hdr;

	uint8_t type;
	uint8_t code;
	uint16_t checksum;

	uint16_t identifier;
	uint16_t sequence_number;

	char payload[32]; // TODO Check size
};

struct global
{
	int sock;
	const uint8_t *dst;
	size_t transmitted;
	uint64_t last_timestamp;

	int stopped;
};

static struct global state;

static void stop_ping(int sig)
{
	(void) sig;
	state.stopped = 1;
}

static void transmit(int sig)
{
	(void) sig;
	struct icmp_packet p;

	p.type = 8;
	p.code = 0;
	p.checksum = 0;
	p.identifier = getpid();
	p.sequence_number = state.transmitted;
	for (size_t i = 0; i < sizeof(p.payload); ++i)
		p.payload[i] = 'a' + i;
	p.checksum = compute_checksum(&p, sizeof(p));

	p.ip_hdr.version = 1; // TODO Check
	p.ip_hdr.tos = 0;
	p.ip_hdr.length = sizeof(struct icmp_packet) - sizeof(struct ipv4_datagram);
	p.ip_hdr.identification = 0; // TODO
	p.ip_hdr.flags_offset = 0; // TODO
	p.ip_hdr.ttl = 1;
	p.ip_hdr.protocol = 1; // ICMP
	p.ip_hdr.hdr_checksum = 0; // TODO

	for (size_t i = 0; i < 4; ++i)
		p.ip_hdr.src[i] = 0;
	for (size_t i = 0; i < 4; ++i)
		p.ip_hdr.dst[i] = state.dst[i];

	struct addrinfo hints;
	struct addrinfo *result;
	ft_memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_flags = AI_ADDRCONFIG;
	hints.ai_socktype = SOCK_RAW;

	int err = getaddrinfo(addr, NULL, &hints, &result);
	if (err)
	{
		// TODO
	}

	if (result)
		sendto(state.sock, &p, sizeof(p), MSG_NOSIGNAL, result->ai_addr, result->ai_addrlen);
	freeaddrinfo(result);

	++state.transmitted;
	state.last_timestamp = get_timestamp();
	alarm(1);
}

static int receive(int sock, const char *host, const uint8_t *addr, int verbose)
{
	struct msghdr m;

	if (recvmsg(sock, &m, 0) <= 0)
		return 0;

	size_t pkg_len = 0;
	for (size_t i = 0; i < m.msg_iovlen; ++i)
		pkg_len += m.msg_iov[i].iov_len;
	if (pkg_len < sizeof(struct icmp_packet))
		return 0;
	
	struct icmp_packet *p;
	if (!(p = malloc(pkg_len)))
		return 0;
	size_t off = 0;
	for (size_t i = 0; i < m.msg_iovlen; ++i)
	{
		ft_memcpy(&((char *) p)[off], m.msg_iov[i].iov_base, m.msg_iov[i].iov_len);
		off += m.msg_iov[i].iov_len;
	}

	(void) verbose;

	// TODO Check package correctness

	size_t payload_size = 0; // TODO
	uint16_t icmp_seq = 0; // TODO
	uint16_t ttl = 0; // TODO
	float time = 0.; // TODO

	printf("%zu bytes from %s (%d.%d.%d.%d): icmp_seq=%u ttl=%u time=%f ms\n",
		payload_size, host, addr[0], addr[1], addr[2], addr[3], icmp_seq, ttl, time);

	return 1;
}

void ping(const char *host, const uint8_t *addr, int verbose)
{
	size_t size0 = 0; // TODO
	size_t size1 = 0; // TODO
	printf("PING %s (%d.%d.%d.%d) %zu(%zu) bytes of data.\n", host, addr[0],
		addr[1], addr[2], addr[3], size0, size1);

	signal(SIGINT, stop_ping);
	signal(SIGALRM, transmit);

	int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

	uint64_t start_timestamp = get_timestamp();
	uint64_t min = 0;
	uint64_t sum = 0;
	uint64_t sqr_sum = 0;
	uint64_t max = 0;

	state.sock = sock;
	state.dst = addr;
	state.transmitted = 0;
	state.stopped = 0;

	size_t received = 0;

	alarm(1);
	while (!state.stopped)
	{
		while (!state.stopped && !receive(sock, host, addr, verbose))
			;
		if (state.stopped)
			break;
		++received;

		if (state.stopped)
			break;

		uint64_t delta = get_timestamp() - state.last_timestamp;
		if (received == 1 || delta < min)
			min = delta;
		sum += delta;
		sqr_sum += delta * delta;
		if (delta > max)
			max = delta;
	}


	uint64_t elapsed = get_timestamp() - start_timestamp;

	size_t lost_count = state.transmitted - received;
	unsigned lost_percent = 0;
	if (state.transmitted > 0)
		lost_percent = 100 * lost_count / state.transmitted;

	printf("\n--- %s ping statistics ---\n", host);
	printf("%zu packets transmitted, %zu received, %u%% packet loss, time %fms\n",
		state.transmitted, received, lost_percent, (float) elapsed / 1000.);

	if (received > 0)
	{
		float avg = (float) sum / (float) received;
		float mdev = ((float) sqr_sum / (float) received) - avg;

		printf("rtt min/avg/max/mdev = %f/%f/%f/%f ms\n",
			(float) min / 1000., avg / 1000., (float) max / 1000., mdev / 1000.);
	}

	close(sock);
}
