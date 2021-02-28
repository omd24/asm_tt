; simple lookup table

.const  
vals    dword   0, 1, 1, 2, 3, 5, 8, 13
        dword   21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
nvals_  dword   ($ - vals) / sizeof dword
        public  nvals_

.data
vals_sum_   dword   ?
            public  vals_sum_

; int memory_addressing_(int i, int * v1, int * v2, int * v3, int * v4);
; returns:  0 = error,  1 = success

.code
memory_addressing_ proc
; check i validity
    cmp ecx, 0
    jl InvalidIndex
    cmp ecx, [nvals_]
    jge InvalidIndex
; sign ext for memory calculations
    movsxd rcx, ecx
    mov [rsp + 8], rcx
; mode#1 base register
    mov r11, offset vals
    shl rcx, 2
    add r11, rcx
    mov eax, [r11]
    mov [rdx], eax
; mode#2 base register + index register
    mov r11, offset vals
    mov rcx, [rsp + 8]
    shl rcx, 2
    mov eax, [r11 + rcx]
    mov [r8], eax
; mode#3 base register + index register * scale factor
    mov r11, offset vals
    mov rcx, [rsp + 8]
    mov eax, [r11 + rcx*4]
    mov [r9], eax
; mode#4 base register + index register * scale factor + disp
    mov r11, offset vals - 42
    mov rcx, [rsp + 8]
    mov eax, [r11 + rcx*4 + 42]
    mov r10, [rsp + 40]
    mov [r10], eax
; rip relative
    add [vals_sum_], eax
; output
    mov eax, 1
    ret
InvalidIndex:
    xor eax , eax
    ret
memory_addressing_ endp
end

