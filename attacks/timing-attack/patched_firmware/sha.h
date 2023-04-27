#include <stdint.h>

typedef struct SHAContext {
    bool start;
    uint32_t total_input_bits[4];
} SHA_CTX;

enum SHA_TYPE {
    SHA1 = 0,
    SHA2_256,
    SHA2_384,
    SHA2_512,


    SHA_INVALID = -1,
};


typedef enum {
    ETS_OK     = 0, /**< return successful in ets*/
    ETS_FAILED = 1, /**< return failed in ets*/
    ETS_PENDING = 2,
    ETS_BUSY = 3,
    ETS_CANCEL = 4,
} ETS_STATUS;

typedef ETS_STATUS ets_status_t;


/* Do not use these function in multi core mode due to
 * inside they have no safe implementation (without DPORT workaround).
*/

#define ets_sha_init ((ets_status_t (*)(SHA_CTX *ctx, enum SHA_TYPE type)) 0x40000650)
//void ets_sha_init(SHA_CTX *ctx); 

#define ets_sha_enable ((void (*)(void)) 0x40000644)
//void ets_sha_enable(void); 0x40000644

#define ets_sha_disable ((void (*)(void)) 0x40000648)
//void ets_sha_disable(void); 0x40000648

#define ets_sha_update ((void (*)(SHA_CTX *ctx,  const unsigned char *input, size_t input_bits, int update_ctx)) 0x4000065c)
//void ets_sha_update(SHA_CTX *ctx, enum SHA_TYPE type, const uint8_t *input, size_t input_bits); 0x4000065c

#define ets_sha_finish ((void (*)(SHA_CTX *ctx, unsigned char *output)) 0x40000660)
//void ets_sha_finish(SHA_CTX *ctx, enum SHA_TYPE type, uint8_t *output); 0x40000660