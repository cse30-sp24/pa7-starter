#include "Version.h"

#ifndef MYDCRYPT_S
    .section .note.GNU-stack,"",%progbits
    .end
#else

    // version 1.1 05/08/2024
    .arch armv6
    .arm
    .fpu vfp
    .syntax unified

    #include "cipher.h"

    .text     // start of text segment

    //////////////////////////////////////////////////
    // int dcrypt(unsigned char *inbuf, unsigned char *bookbuf, int cnt)
    // decrypts inbuf using bookbuf; result in inbuf
    //////////////////////////////////////////////////
    .global dcrypt
    .type   dcrypt, %function
    .equ    FP_OFF, 28

   // r0 contains char *inbuf
   // r1 contains char *bookbuf
   // r2 contains cnt
   // r3 is ok to use
   //
   // preserved register use table
   //
   // r4
   // r5
   // r6
   // r7
   // r8
   // r9

dcrypt:
    push    {r4-r9, fp, lr}
    add     fp, sp, FP_OFF


    cmp     r2, 0               // if buffer is empty we are done
    ble     .Ldone

    // your code here 

.Ldone:
   // make sure to return cnt processed

    sub     sp, fp, FP_OFF
    pop     {r4-r9, fp, lr}
    bx      lr

    .size dcrypt, (. - dcrypt)
    .section .note.GNU-stack,"",%progbits
.end
#endif
