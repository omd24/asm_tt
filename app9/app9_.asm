;   extern "C" void
;   calc_matrix_squares_ (int * y, int * x, int nrows, int ncols);

.code

calc_matrix_squares_ proc frame
push rsi
.pushreg rsi
push rdi
.pushreg rdi
.endprolog

cmp r8d, 0
jle InvalidCount
cmp r9d, 0
jle InvalidCount

mov rsi, rdx
mov rdi, rcx
xor rcx, rcx
movsxd r8, r8d
movsxd r9, r9d

Loop1:
    xor rdx, rdx
Loop2:
    mov rax, rdx
    imul rax, r9
    add rax, rcx
    mov r10d, dword ptr [rsi+rax*4]
    imul r10d, r10d

    mov rax, rcx
    imul rax, r9
    add rax, rdx
    mov dword ptr[rdi+rax*4], r10d

    inc rdx
    cmp rdx, r9
    jl  Loop2
    
    inc rcx
    cmp rcx, r8
    jl Loop1

InvalidCount:
pop rdi
pop rsi
ret
calc_matrix_squares_ endp
end

