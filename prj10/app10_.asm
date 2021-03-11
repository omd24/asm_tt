TestStruct struct
Val8    byte    ?
Pad8    byte    ?
Val16    word    ?
Val32    dword    ?
Val64    qword    ?
TestStruct ends

;   extern "C" int64_t
;   calc_struct_sum_ (TestStruct * ts);
;   Return: ts->val8 + ts->val16 + ts->val32 + ts->val64;

.code
calc_struct_sum_ proc

; sum the first two members
movsx eax, byte ptr [rcx + TestStruct.Val8]
movsx edx, word ptr [rcx + TestStruct.Val16]
add eax, edx

; add the third member
movsxd rax, eax
movsxd rdx, dword ptr [rcx + TestStruct.Val32]
add rax, rdx

; add forth member
add rax, [rcx + TestStruct.Val64]
ret

calc_struct_sum_ endp
end

