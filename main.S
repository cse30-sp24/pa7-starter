#include "Version.h"

#ifndef MYMAIN_S
    .section .note.GNU-stack,"",%progbits
    .end
#else

    // version 1.3 05/11/2024 //
    .arch   armv6
    .arm
    .fpu    vfp
    .syntax unified

    // imports
    #include "main.h"
    #include "rdbuf.h"
    #include "setup.h"
    #include "cipher.h"
    .extern fwrite
    .extern fprintf
    .extern fclose
    .extern stdin
    .extern stdout
    .extern stderr
    //
    // cipher [-d | -e] -b bookfile
    //
    // int main(int argc, char **argv)
    //

    .section .rodata
    // string literals for fprint
.Lrdmess:  .string "%s: read failed\n"
    .align 2
.Lwrmess:  .string "%s: write failed\n"

    .text
    .global main
    .type   main, %function
    //
    // complete the stack frame layout
    //
    .equ    FP_OFF,     32          // fp offset in main stack frame

    // use the same stack allocation order as in Cmain.c

    //
    // add your local variables here if you need them:
    //

    // NOTICE: Adjust PAD so the total size of frame (including 
    // preserved registers r4-r10, fp,lr) in bytes divides by 8 evenly
    // (8-byte aligned) keep the two buffers 8-byte aligned as well
    //.equ    PAD,             	    // Stack frame PAD
    //.equ    OARG5,           	    // output arg5 must be at bottom
    //.equ    FRMADD,OARG5-FP_OFF   // total space for locals + outarg5

    //
    // preserved register use table fill this in describing your use for each
    //
    // r4
    // r5
    // r6
    // r7
    // r8
    // r9
    // r10

main:
    push    {r4-r10, fp, lr}        // observe: odd number of regs saved
    add     fp, sp, FP_OFF          // set frame pointer to frame base

    // allocate space for locals and outgoing args below
     
    // call int setup(argc, argv, &func, &fpbook)

    // initialize the preserved registers and stack variables
    // for main loop

    //
    // top of loop
    //
    // int rdbuf(r0=stdin, r1=fpbook, r2=BUFSZ, r3=inbuf,OARG5=bookbuf)
    // cnt = rdbuf(FILE *, FILE*, int, unsigned char *, unsigned char *)
    //
    
    //
    // cnt = func(unsigned char *inbuf, unsigned char *bookbuf, int cnt)
    //

    //
    // fwrite(inbuf, 1, cnt, stdout)
    // 

    //
    // bottom of loop
    //

    //
    // error handling code
    //

    //
    // end of error handling code
    //

.Ldone:
    // set return value
    sub     sp, fp, FP_OFF
    pop     {r4-r10, fp, lr}
    bx      lr

    .size   main, (. - main)
    .section .note.GNU-stack,"",%progbits
.end
#endif
