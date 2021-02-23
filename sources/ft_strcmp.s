section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor rbx, rbx
loop:
	mov al, byte [rdi]
	mov bl, byte [rsi]
	sub rax, rbx
	cmp rax, 0
	jne end
	cmp byte [rdi], 0
	je 	end
	cmp byte [rsi], 0
	je 	end
	add rdi, 1
	add rsi, 1
	jmp loop
end:
	ret
