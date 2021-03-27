section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor rbx, rbx
loop:
	mov al, byte [rdi]
	mov bl, byte [rsi]
;	sub rax, rbx
	cmp rax, rbx
	jg	set_one
	jl	set_minus_one
	cmp byte [rdi], 0
	je 	end
	add rdi, 1
	add rsi, 1
	jmp loop
set_one:
	mov rax, 1
	jmp end
set_minus_one
	mov rax, -1
	jmp end
end:
	ret
