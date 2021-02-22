section .text
	global ft_strcpy
	
ft_strcpy:
	mov rax, rdi
loop:
	mov rbx, [rsi]
	mov [rdi], rbx
	add rdi, 1
	add rsi, 1
	cmp byte [rsi], 0
	jne loop
	ret


