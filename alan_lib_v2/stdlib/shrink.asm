; byte char shrink (int i);
; -------------------------
; This function takes an integer and converts it
; to a byte by omitting the 8 most significant bits.


              section .code
              global  _shrink

_shrink       push  rbp
              mov   rbp, rsp

              mov ax, di
              xor ah, ah

              mov   rsp, rbp
              pop   rbp
              ret
