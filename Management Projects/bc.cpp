#include "openssl/crypto.h"
struct block{
	unsigned char hash[SHA256_DIGEST_LENGHT];
	INT DATA;
	struct block *link;
};*head;


