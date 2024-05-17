#include "Version.h"

#if defined(MYDCRYPT_S)
#warning("using my dcrypt.S")
#elif !defined(MYDCRYPT_C)
#warning("using solution decrypt")
#else
#warning("using my Cdcrypt.c")

// version 1.1 05/08/2024
#include <stdio.h>
#include "cipher.h"

// decrypts inbuf with bookbuf; updating inbuf
int
dcrypt(unsigned char *inbuf, unsigned char *bookbuf, int cnt)
{

    if (cnt <= 0)
        return 0;
// your code here
    return cnt;
}
#endif
