#include <stddef.h>
#include <stdint.h>

uint16_t compute_checksum(const void *addr, size_t count) {
	long sum = 0;

	while (count > 1)
	{
       	sum += *(unsigned short *) addr++;
       	count -= 2;
	}

	if (count > 0)
       	sum += *(unsigned char *) addr;

	while (sum >> 16)
   		sum = (sum & 0xffff) + (sum >> 16);

	return ~sum;
}
