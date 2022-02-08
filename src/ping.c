static stopped = 0;

void stop_ping(int sig)
{
	(void) sig;
	stopped = 1;
}

__attribute__((packed))
typedef struct
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
} ipv4_datagram;

__attribute__((packed))
typedef struct {
	ipv4_datagram ip_hdr;

	uint8_t type;
	uint8_t code;
	uint16_t checksum;

	uint16_t identifier;
	uint16_t sequence_number;

	char payload[0];
} icmp_packet;

void transmit(int sock)
{
	icmp_packet p;

	// TODO Send packet
}

int receive(int sock)
{
	icmp_packet p;
	ssize_t len;

	if ((len = recvmsg(sock, &p, )) <= 0)
		return 0;

	// TODO Read
	// TODO Print
}

void ping(const char *host, const int *addr)
{
	size_t size0 = 0;
	size_t size1 = 0;
	printf("PING %s (%d.%d.%d.%d) %zu(%zu) bytes of data.", host, addr[0],
		addr[1], addr[2], addr[3], size0, size1);

	signal(SIGINT, stop_ping);

	int sock = socket(AF_INET, SOCK_RAW, 0);

	size_t transmitted = 0;
	size_t received = 0;

	while (!stopped)
	{
		transmit(sock);
		while (receive(sock))
			;

		++transmitted;
	}

	size_t lost_count = transmitted - received;
	unsigned lost_percent = 100 * lost_count / transmitted;
	printf("--- %s ping statistics ---", host);
	printf("%zu packets transmitted, %zu received, %u%% packet loss, time %ums",
		transmitted, received, lost_percent, time);
	printf("rtt min/avg/max/mdev = 0.022/0.022/0.022/0.000 ms"); // TODO
}
