#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

#include "../libft/libft.h"

static int stopped = 0;

void stop_ping(int sig)
{
	(void) sig;
	stopped = 1;
}

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

	char payload[0];
};

void transmit(int sock)
{
	(void) sock;
	// TODO Send packet
}

int receive(int sock, const char *host, const uint8_t *addr)
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

	// TODO Check package correctness

	size_t payload_size = 0; // TODO
	size_t icmp_seq = 0; // TODO
	uint16_t ttl = 0; // TODO
	float time = 0.; // TODO

	printf("%zu bytes from %s (%d.%d.%d.%d): icmp_seq=%zu ttl=%u time=%f ms\n",
		payload_size, host, addr[0], addr[1], addr[2], addr[3], icmp_seq, ttl, time);

	return 1;
}

void ping(const char *host, const uint8_t *addr)
{
	size_t size0 = 0;
	size_t size1 = 0;
	printf("PING %s (%d.%d.%d.%d) %zu(%zu) bytes of data.\n", host, addr[0],
		addr[1], addr[2], addr[3], size0, size1);

	signal(SIGINT, stop_ping);

	int sock = socket(AF_INET, SOCK_RAW, 0);

	size_t transmitted = 0;
	size_t received = 0;

	uint64_t start_timestamp = 0; // TODO

	while (!stopped)
	{
		transmit(sock);
		while (receive(sock, host, addr))
			;

		++transmitted;
	}

	uint64_t elapsed = 0 - start_timestamp; // TODO

	size_t lost_count = transmitted - received;
	unsigned lost_percent = 100 * lost_count / transmitted;
	printf("\n--- %s ping statistics ---\n", host);
	printf("%zu packets transmitted, %zu received, %u%% packet loss, time %lums\n",
		transmitted, received, lost_percent, elapsed);
	printf("rtt min/avg/max/mdev = 0.022/0.022/0.022/0.000 ms\n"); // TODO
}
