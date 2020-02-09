; void writeByte (unsigned char b);
; ---------------------------------
; This function prints a byte to the standard output.
; It uses writeInteger.


              section .code
              global _writeByte
              extern _writeInteger

_writeByte    push  rbp
              mov   rbp, rsp
              
              mov   al, dil
              xor   ah, ah
              call  _writeInteger
              
              mov   rsp, rbp
              pop   rbp
              ret
