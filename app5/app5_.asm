
;   int mixed_int_mul_ (
;       int8_t a, int16_t b, int32_t c, int64_t d,
;       int8_t e, int16_t f, int32_t g, int64_t h,
;       int64_t * out_prod
;   );

.code

mixed_int_mul_ proc

    ; Calculate a * b * c * d
    movsx   rax, cl        ; rax = sign_extend(a)
    movsx   rdx, dx        ; rcx = sign_extend(b)
    imul    rax, rdx       ; rax = a * b

    movsxd  rcx, r8d       ; rcx = sign_extend(c)
    imul    r9, rcx        ; r9 = c * d
    imul    rax, r9        ; rax = a * b * c * d

    ; Calculate e * f * g * h
    movsx     rcx, byte ptr [rsp + 40]      ; rcx = sign_extend(e)
    movsx     rdx, word ptr [rsp + 48]      ; rdx = sign_extend(f)
    imul    rcx, rdx                        ; rcx = e * f
    movsxd  rdx, dword ptr [rsp + 56]       ; rdx = sign_extend(g)
    imul    rdx, qword ptr [rsp + 64]     ; rdx = g * h
    imul    rcx, rdx            ; rcx = e * f * g * h

    imul    rax, rcx            ; rax = a * b * c * d * e * f * g * h

    mov     rcx, [rsp + 72]
    mov     [rcx], rax

    mov     eax, 1
    ret
mixed_int_mul_ endp

;   int mixed_int_div_ (
;       uint8_t a, uint16_t b, uint32_t c, uint64_t d,
;       uint8_t e, uint16_t f, uint32_t g, uint64_t h,
;       uint64_t * out_quo, uint64_t * out_rem
;   );

mixed_int_div_ proc

    ; Calculate a + b + c + d
    movzx   rax, cl
    movzx   rdx, dx
    add     rax, rdx
    mov     r8d, r8d        ; r8 = zero_extend(c) aka zero_extend r8d to r8
    add rax, r8
    add rax, r9
    xor     rdx, rdx        ; dividend is rdx:rax (so zero rdx to avoid dependency to previous values there)

    ; Calculate e + f + g + h
    movzx   r8, byte ptr [rsp + 40]
    movzx   r9, word ptr [rsp + 48]
    add     r8, r9
    ; There is no MOVZXD instruction
    ; Ordinary MOV operations into 32-bit subregisters automatically zero extend to 64 bits
    mov     r10d, [rsp + 56]
    add     r10, [rsp + 64]
    add     r8, r10
    
    jnz DivOk
    xor     eax, eax
    jmp Done

DivOk:
    div     r8
    mov     rcx, [rsp + 72]
    mov     [rcx], rax
    mov     rcx, [rsp + 80]
    mov     [rcx], rdx

    mov     eax, 1
Done:
    ret
mixed_int_div_ endp

end


