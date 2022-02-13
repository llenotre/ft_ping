#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

uint64_t get_timestamp(void) {
	struct timeval t;

	gettimeofday(&t, NULL);
	return (uint64_t) t.tv_sec * 1000000 + t.tv_usec;
}

int16_t sum(const uint16_t *b, size_t len) {
	uint16_t v = 0;

	for (size_t i = 0; i < len; ++i)
		v += b[i];

	return v;
}
