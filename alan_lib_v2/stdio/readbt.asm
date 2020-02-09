; unsigned char readByte ();
; --------------------
; This function reads a byte from the standard input.
; An integer is read by a call to readInteger, and its
; 8 LSB are returned.


INTSIZE       equ 2

              section .text
              global _readByte
              extern _readInteger

_readByte     push  rbp
              mov   rbp, rsp

              call  _readInteger

              xor ah, ah

              mov   rsp, rbp
              pop   rbp
              ret
