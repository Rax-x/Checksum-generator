#ifndef _HASH_H_
#define _HASH_H_

#include <stddef.h> // size_t
#include <stdint.h>

void md5(const char* input, uint8_t* hash, size_t len);
void sha256(const char* input, uint8_t* hash, size_t len);

#endif
