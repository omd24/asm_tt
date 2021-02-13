;extern "C" int int_shift_(uint32_t a, uint32_t count, uint32_t * a_shr, uint32_t * a_shl);
;Returns: 0 = error, 1 = success

.code

int_shift_ proc
    mov eax, 0
    cmp edx, 31
    ja InvalidCount
    
    xchg ecx, edx
    mov eax, edx
    shr eax, cl
    mov [r8], eax

    shl edx, cl
    mov [r9], edx
    
    mov eax, 1
InvalidCount:
    ret
int_shift_ endp

end


