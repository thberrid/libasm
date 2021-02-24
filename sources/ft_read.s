section .text
	%define SYS_READ 0
	extern __errno_location
	global ft_read

ft_read:
	mov rax, SYS_READ
	syscall
	cmp rax, 0
	jge end
	neg rax
	push rax
	call __errno_location wrt ..plt
	pop qword [rax]
	mov rax, -1
end:
	ret
