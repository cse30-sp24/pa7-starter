#include "Version.h"

#ifndef MYRDBUF_S
    .section .note.GNU-stack,"",%progbits
    .end
#else

    // version 1.1 05/08/2024
    .arch   armv6
    .arm
    .fpu    vfp
    .syntax unified

    // global constants
    #include "cipher.h"

    .extern fread
    .text

    //////////////////////////////////////////////////////
    // int rdbuf(FILE *in, FILE *book, int cnt, unsigned char *inbuf,
    //          unsigned char *bookbuf)
    // returns number of bytes read RETRN_FAIL otherwise
    // OBSERVE this has 5 arguments!
    //////////////////////////////////////////////////////

    .type   rdbuf, %function
    .global rdbuf
    // determine how many registers to save and set FP_OFF
    //.equ    FP_OFF, ??
 
rdbuf:
    // set up stack frame

    // fread()

    // fread()

.Ldone:
    // remove stack frame

    bx      lr

    .size   rdbuf, (. - rdbuf)
    .section .note.GNU-stack,"",%progbits
.end
#endif
