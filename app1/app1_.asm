; extern "C" int asm_add(int a, int b, int c, int d);

        .code
asm_add proc

; Calculate a + b + c - d
        mov eax,ecx                         ;eax = a
        add eax,edx                         ;eax = a + b
        add eax,r8d                         ;eax = a + b + c
        sub eax,r9d                         ;eax = a + b + c - d

        ret                                 ;return result to caller
asm_add endp
        end
