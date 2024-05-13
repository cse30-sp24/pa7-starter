#include "Version.h"

#if defined(MYRDBUF_S)
#warning("using rdbuf.S")
#elif !defined(MYRDBUF_C)
#warning("using solution rdbuf")
#else
#warning("using my Crdbuf.c")

#include <stdio.h>
#include "cipher.h"
#include "rdbuf.h"

// version 1.2 05/11/2024

int
rdbuf(FILE *in, FILE *book, int cnt, unsigned char *inbuf, unsigned char *bookbuf)
{
    int bytes; /* use in a register no local variables on the stack needed */
   
    /*
     * read the file
     * argument cnt should be really a size_t but on ARM32 it is an int
     */

    /*
     * now read the same number of chars from the bookfile
     * as was read from the input file
     * if bytes read from bookfile is not the same as read on the input
     * then return RETRN_FAIL;
     */

    /*
     * return the number of chars read
     */
    return bytes;
}
#endif
