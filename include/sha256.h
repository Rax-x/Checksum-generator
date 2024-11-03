#ifndef _SHA256_H_
#define _SHA256_H_

#include <stddef.h> // size_t
#include <stdint.h>

typedef struct {
    uint8_t data[64];
    uint32_t dataLen;
    uint64_t bitLen;
    uint32_t state[8];
} SHA256Context;

void sha256Finalize(SHA256Context* ctx, uint8_t* hash);
void sha256Init(SHA256Context* ctx);
void sha256Transform(SHA256Context* ctx, uint8_t* data);
void sha256Update(SHA256Context* ctx, const uint8_t* data, size_t len);

#endif
