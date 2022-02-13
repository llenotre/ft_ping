#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

uint64_t get_timestamp(void) {
	struct timeval t;

	gettimeofday(&t, NULL);
	return t.tv_sec * 1000 + t.tv_usec / 1000;
}

int16_t sum(const uint16_t *b, size_t len) {
	uint16_t v = 0;

	for (size_t i = 0; i < len; ++i)
		v += b[i];

	return v;
}
