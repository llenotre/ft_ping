#ifndef PING_H
# define PING_H

uint64_t get_timestamp(void);

void ping(const char *host, const uint8_t *addr, int verbose);

uint16_t compute_checksum(const void *addr, size_t count);

#endif
