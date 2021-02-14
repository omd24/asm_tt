; int integer_mul_div_(int a, int b, int * out_prod, int * out quo, int * out_rem);
; Returns: 0 = error, 1 = success

.code
integer_mul_div_ proc

; divisor validation
    mov eax, edx
    or eax, eax
    jz InvalidDivisor

    imul eax, ecx
    mov [r8], eax   ; save product

    mov r10d, edx   ; r10d = divisor, (need edx for dividend)
    mov eax, ecx
    cdq
    idiv r10d

    mov [r9], eax   ; save quotient
    mov rax, [rsp + 40]
    mov [rax], edx  ; save remainder

    mov eax, 1      ; success code
InvalidDivisor:
    ret

integer_mul_div_ endp
end

