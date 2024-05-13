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

// version 1.1 05/08/2024

int
main(int argc, char **argv)
{
    /*
     * local vars on stack
     */
    FILE *fpbook;                   // File * to bookfile
    unsigned char inbuf[BUFSZ];     // input buffer
    unsigned char bookbuf[BUFSZ];   // output buffer
    int (*func)();                  // function pointer to ecrypt or dcrypt
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
    //
    // complete the io loop
    //
    // if rdbuf() fails it returns RETRN_FAIL then
    // fprintf(stderr, "%s: read failed\n", argv0);
    // return EXIT_FAILURE;
    // 
    // if fwrite fails to write all the chars rdbuf() returns then
    // fprintf(stderr, "%s: write failed\n", argv0);
    // (void)fclose(fpbook);
    // return EXIT_FAILURE; 
    //
    //  do not forget to close the book file
    //  (void)fclose(fpbook);
    //

    return EXIT_SUCCESS;
}
#endif
