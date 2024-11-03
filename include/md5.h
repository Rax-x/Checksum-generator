#ifndef _MD5_H_
#define _MD5_H_

#include <stddef.h> // size_t
#include <stdint.h>

typedef struct {
    uint64_t size;
    uint32_t buffer[4];
    uint8_t input[64];
    uint8_t digest[16];
} MD5Context;

void md5Finalize(MD5Context *ctx);
void md5Init(MD5Context *ctx);
void md5Step(uint32_t *buffer, uint32_t *input);
void md5Update(MD5Context *ctx, const uint8_t* inputBuffer, size_t inputLen);

#endif
