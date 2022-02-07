#include <stdio.h>

int has(int argc, char **argv, const char *str)
{
	for (size_t i = 0; i < argc; ++i)
	{
		if (ft_strcmp(argv[i], str) == 0)
			return 1;
	}

	return 0;
}

char *get_host(int argc, char **argv)
{
	// TODO
}

int main(int argc, char **argv)
{
	if (has(argc, argv, "-h"))
	{
		print_help();
		return 0;
	}

	int verbose = has(argc, argv, "-v");
	const char *host = get_host(argc, argv);
	if (host == NULL)
	{
		printf("ping: usage error: Destination address required");
		return 1;
	}

	// TODO

	return 0;
}
