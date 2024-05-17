#include "Version.h"

#if defined(MYECRYPT_S)
#warning("using my ecrypt.S")
#elif !defined(MYECRYPT_C)
#warning("using solution ecrypt")
#else
#warning("using my Cecrypt.c")

// version 1.1 05/08/2024
#include <stdio.h>
#include "cipher.h"

// encrypts  inbuf with bookbuf; updating inbuf
int
ecrypt(unsigned char *inbuf, unsigned char *bookbuf, int cnt)
{

    if (cnt <= 0)
        return 0;
    // your code here
    return cnt;
}
#endif
