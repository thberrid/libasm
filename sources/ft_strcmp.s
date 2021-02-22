section .text
	global ft_strcmp

ft_strcmp:
	xor eax, eax
loop:
	mov eax, byte [rsi]
	mov ebx, byte [rdi]
	sub eax, esi
	cmp byte [eax], 0
	jne end
	cmp byte [edi], 0
	je end
	cmp byte [esi], 0
	je end
	add rdi, 1
	add rsi, 1
	jmp loop
end:
	ret
