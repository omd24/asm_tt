;   size_t concat_strings_ (char * des, size_t des_size, char ** src, size_t src_n);
;   Returns:    -1      invalid des_size
;                n      length of concatenated string

.code
concat_strings_ proc frame
push rbx
.pushreg rbx
push rsi
.pushreg rsi
push rdi
.pushreg rdi
.endprolog

; check inputs args
mov rax, -1
test rdx, rdx
jz InvalidArg
test r9, r9
jz InvalidArg

; registers used in main loop
; rbx = des             rdx = des_size
; r8 = src              r9 = src_n
; r10 = des_index       r11 = i (loop counter)
; rcx = src[i] length
; rsi, rdi = pointers used for string instructions (scasb & movsb)

; initialization
xor r10, r10
xor r11, r11
mov rbx, rcx
mov byte ptr [rbx], 0

; main loop
Loop1:
mov rax, r8
mov rdi, [rax + r11 * 8]
mov rsi, rdi

; -- compute length of src[i]
xor eax, eax
mov rcx, -1
repne scasb
not rcx
dec rcx

; -- compute des_index + len(src[i])
mov rax, r10
add rax, rcx
cmp rax, rdx
jge Done

; -- update des_index
mov rax, r10
add r10, rcx

; -- copy src[i] to des[des_index]
inc rcx
lea rdi, [rbx + rax]
rep movsb

; -- update i
inc r11
cmp r11, r9
jl Loop1
; main loop end

Done:
mov rax, r10

InvalidArg:
pop rdi
pop rsi
pop rbx
ret
concat_strings_ endp
end



