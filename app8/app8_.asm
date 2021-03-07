
.code

calc_array_vals_ proc frame

push rsi
.pushreg rsi
push rdi
.pushreg rdi
.endprolog

xor rax, rax    ; sum=0
; check n validity
mov r11d, [rsp+56]
cmp r11d, 0
jle InvalidCount

mov rsi, rdx    ;x
mov rdi, rcx    ;y

movsxd r8,r8d   ;a
movsx r9,r9w    ;b
xor edx,edx     ;i

; repeat until done
@@:
    movsxd rcx, dword ptr[rsi+rdx*4]    ;x
    imul rcx,r8 ;ax
    add rcx,r9  ;ax + b
    mov qword ptr[rdi+rdx*8],rcx

    add rax,rcx ;update sum

    inc edx
    cmp edx,r11d
    jl @B

InvalidCount:
pop rdi
pop rsi
ret
calc_array_vals_ endp
end

