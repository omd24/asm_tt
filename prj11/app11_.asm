; unsigned long long count_chars_ (char * s, char c);
; 
; Returns: number of occurences of c

.code
count_chars_ proc frame
push rsi
.pushreg rsi
.endprolog

mov rsi, rcx    ; rsi = s
mov cl, dl      ; cl = c
xor edx, edx    ; rdx = num of occurences
xor r8d, r8d    ; r8 = 0 (required for add below)

; Main Loop
@@: lodsb       ; load next char into al (then inc rsi)
    or al, al   ; check al for end-of-string
    jz @F
    cmp al, cl
    sete r8b    ; if match: r8b = 1 else 0
    add rdx, r8
    jmp @B

@@: mov rax, rdx

pop rsi
ret
count_chars_ endp
end
