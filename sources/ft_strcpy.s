section .text
	global ft_strcpy
	
ft_strcpy:
	mov rax, rdi
loop:
	mov rdi, qword [rsi]
	cmp byte [rsi], 0
	je ending
	add rsi, 1
	add	rdi, 1
	jmp loop
ending:
	ret


