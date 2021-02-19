section .text
	global ft_strlen
	
ft_strlen:
	xor	rax, rax
loop:
	cmp byte [rdi], 0
	je	ending
	add rax, 1
	add	rdi, 1
	jmp loop
ending:
	ret


