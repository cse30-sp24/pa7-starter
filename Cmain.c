#include "Version.h"

#if defined(MYMAIN_S)
#warning("using my main.S")
#elif !defined(MYMAIN_C)
#warning("using solution main")
#else
#warning("using my Cmain.c")

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "rdbuf.h"
#include "setup.h"
#include "cipher.h"

// version 1.2 05/24/2024

int
main(int argc, char **argv)
{
    /*
     * local vars on stack
     */
    FILE *fpbook;                   // File * to bookfile
    unsigned char inbuf[BUFSZ];     // input buffer
    unsigned char bookbuf[BUFSZ];   // output buffer
    int (*func)(unsigned char *, unsigned char *, int);
                                    // function ptr ecrypt or dcrypt
    char *argv0 = *argv;            // saved argv[0] for fprintf()
    // end of stack variables

    int cnt;            // does not need to be on stack (used as r0)

    /*
     * parse the command line arguments, set mode (encrypt or decrypt)
     * and open the book file
     */
    if (setup(argc, argv, &func, &fpbook) == RETRN_FAIL)
        return EXIT_FAILURE;

    /*
     * read the input and book file until EOF on the input file
     * Either func points at encrypt or decrypt
     * then write it out.
     */ 
    while ((cnt = rdbuf(stdin, fpbook, BUFSZ, inbuf, bookbuf)) > 0) {
        cnt = func(inbuf, bookbuf, cnt);
        if ((int)fwrite(inbuf, 1, cnt, stdout) != cnt) {
            fprintf(stderr, "%s: write failed\n", argv0);
            (void)fclose(fpbook);
            return EXIT_FAILURE; 
        }
    }

    /*
     * close the book file
     */
    (void)fclose(fpbook);
    if (cnt == RETRN_FAIL) {
        fprintf(stderr, "%s: read failed\n", argv0);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
#endif
