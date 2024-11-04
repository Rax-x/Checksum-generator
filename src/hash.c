#include <string.h> // memcpy
#include <stdint.h>

#include "../include/hash.h"
#include "../include/md5.h"
#include "../include/sha256.h"

void md5(const char* input, uint8_t *hash, size_t len) {
    MD5Context ctx;

    md5Init(&ctx);
    md5Update(&ctx, (uint8_t *)input, (size_t)len);
    md5Finalize(&ctx);

    memcpy(hash, ctx.digest, 16);

    return;
}

void sha256(const char* input, uint8_t *hash, size_t len) {
    SHA256Context ctx;

    sha256Init(&ctx);
    sha256Update(&ctx, (uint8_t*)input, (size_t)len);
    sha256Finalize(&ctx, hash);

    return;
}
