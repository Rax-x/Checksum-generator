#include <stdint.h>

typedef struct {
	unsigned char data[64];
	unsigned int dataLen;
	unsigned long long bitLen;
	unsigned int state[8];
} SHA256Context;

void sha256Finalize(SHA256Context *ctx, unsigned char hash[]);
void sha256Init(SHA256Context *ctx);
void sha256Transform(SHA256Context *ctx, unsigned char data[]);
void sha256Update(SHA256Context *ctx, const unsigned char data[], size_t len);