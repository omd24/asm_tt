.code
; extern "C" int signed_min_v1 (int a, int b, int c);
; returns:  min(a, b, c)
signed_min_v1 proc
    mov eax, ecx
    cmp eax, edx
    jle @F
    mov eax, edx
@@: cmp eax, r8d
    jle @F
    mov eax, r8d
@@: ret
signed_min_v1 endp

;extern "C" int signed_max_v1 (int a, int b, int c);
; returns:  max(a, b, c)
signed_max_v1 proc
    mov eax, ecx
    cmp eax, edx
    jge @F
    mov eax, edx
@@: cmp eax, r8d
    jge @F
    mov eax, r8d
@@: ret
signed_max_v1 endp

;extern "C" int signed_min_v2 (int a, int b, int c);
; returns:  min(a, b, c)
signed_min_v2 proc
    cmp ecx, edx
    cmovg ecx, edx
    cmp ecx, r8d
    cmovg ecx, r8d
    mov eax, ecx
    ret
signed_min_v2 endp

;extern "C" int signed_max_v2 (int a, int b, int c);
; returns:  max(a, b, c)
signed_max_v2 proc
    cmp ecx, edx
    cmovl ecx, edx
    cmp ecx, r8d
    cmovl ecx, r8d
    mov eax, ecx
    ret
signed_max_v2 endp

end
