#include <memory.h>

#include "../include/hash.h"
#include "../include/md5.h"
#include "../include/sha256.h"

void md5(char input[], char *hash, unsigned int len) {
    MD5Context ctx;

    md5Init(&ctx);
    md5Update(&ctx, (uint8_t *)input, len);
    md5Finalize(&ctx);

    memcpy(hash, ctx.digest, 16);
    return;
}

void sha256(char input[], char *hash, unsigned int len) {
    SHA256Context ctx;

    sha256Init(&ctx);
	sha256Update(&ctx, input, len);
	sha256Finalize(&ctx, hash);
    return;
}