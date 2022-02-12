#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "ping.h"
#include "../libft/libft.h"

int has(int argc, char **argv, const char *str)
{
	for (int i = 1; i < argc; ++i)
	{
		if (ft_strcmp(argv[i], str) == 0)
			return 1;
	}

	return 0;
}

char *get_host(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
		if (argv[i][0] != '-')
			return argv[i];

	return NULL;
}

int parse_addr(const char *host, uint8_t *addr)
{
	size_t i = 0;
	while (*host)
	{
		if (*host == '.')
			return 0;

		addr[i] = (uint8_t) ft_atoi(host);

		while (*host && *host != '.')
			++host;
		if (*host == '.')
		{
			++host;
			if (!*host)
				return 0;
		}

		i += 1;
	}

	return (i == 4);
}

void print_help(void)
{
	dprintf(STDERR_FILENO, "Usage\n");
	dprintf(STDERR_FILENO, "  ping [options] <destination>\n");
	dprintf(STDERR_FILENO, "\n");
	dprintf(STDERR_FILENO, "Options:\n");
	dprintf(STDERR_FILENO, "  <destination>      dns name or ip address\n");
	dprintf(STDERR_FILENO, "  -h                 print help and exit\n");
	dprintf(STDERR_FILENO, "  -v                 verbose output\n");
}

int main(int argc, char **argv)
{
	if (has(argc, argv, "-h"))
	{
		print_help();
		return 0;
	}

	int verbose = has(argc, argv, "-v");
	// TODO
	(void) verbose;

	const char *host;
	if (!(host = get_host(argc, argv)))
	{
		printf("ping: usage error: Destination address required\n");
		return 1;
	}

	// TODO Resolve domain first
	uint8_t addr[4];
	parse_addr(host, addr);

	ping(host, addr);

	return 0;
}
