


mov eax, 3
imul eax, 5
mov 4, eax

mov eax, 2
add eax, 4
mov 2, eax
mov eax,dword[ebp -4]
cmp eax, 2
setle al
movzx 1, al
cmp 1, 0
je label1


mov eax, 1
imul eax, 4
mov dword[ebp -12], eax


mov eax, dword[ebp -12]
xor edx, edx
idiv 3
mov dword[ebp -8], eax
mov eax, dword[ebp -8]
mov dword[ebp -4], eax


jmp label2
label1:


mov eax, 2
sub eax, 1
mov dword[ebp -12], eax
mov eax, dword[ebp -12]
mov 3, eax


label2:mov eax, 0
mov 3, eax
while_start
mov eax,3
cmp eax, 10
setl al
movzx 1, al
label3:
cmp 1, 0
je label4


mov eax, 1
add eax, 2
mov 4, eax



mov eax, 3
xor edx, edx
idiv 4
mov 2, eax


mov eax, 2
imul eax, 5
mov dword[ebp -4], eax

mov eax, 4
add eax, dword[ebp -4]
mov 2, eax
mov eax, 2
mov dword[ebp -4], eax


mov eax, 3
add eax, 1
mov dword[ebp -4], eax
mov eax, dword[ebp -4]
mov 3, eax
jmp label3
label4:
mov eax, 10
mov 10, eax
while_start
mov eax,10
cmp eax, 0
setg al
movzx 1, al
label5:
cmp 1, 0
je label6


mov eax, 1
add eax, 2
mov 4, eax



mov eax, 3
xor edx, edx
idiv 4
mov 2, eax


mov eax, 2
imul eax, 5
mov 3, eax

mov eax, 4
add eax, 3
mov 3, eax
mov eax, 3
mov dword[ebp -4], eax


mov eax, 3
add eax, 1
mov 3, eax
mov eax, 3
mov 3, eax


mov eax, 10
sub eax, 1
mov 1, eax
mov eax, 1
mov 10, eax
jmp label5
label6:
while_start
label7:
cmp 1, 0
je label8


mov eax, 3
add eax, 1
mov 0, eax
mov eax, 0
mov 3, eax
jmp label7
label8:
