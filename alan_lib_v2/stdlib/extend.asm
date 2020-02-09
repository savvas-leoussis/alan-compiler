; int extend (byte b);
; --------------------
; This function takes a byte and converts it to integer.


              section .code
              global _extend

_extend       push  rbp
              mov   rbp, rsp

              mov al, dil
              xor ah, ah

              mov   rsp, rbp
              pop   rbp
              ret
