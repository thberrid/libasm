section .text
	extern __errno_location
	extern malloc
	extern ft_strcpy
	extern ft_strlen
	global ft_strdup

ft_strdup:
	
	push 	rbp
	mov		rbp, rsp

	push	rdi						; save src on stack
	
	call	ft_strlen				

	add		rax, 1					; +1 for \0
	mov		rdi, rax				; len become P1 for malloc
	push	rax						; save len on stack
	call	malloc		wrt ..plt

	cmp		rax, 0					; quit if malloc return == 0
	je		end

	pop		rbx						; retrieve len 
	sub		rbx, 1					; for correct offset to end of dst
	add		rax, rbx				; rax points now to the end of dst
	mov		byte [rax], 0			; add \0 
	sub		rax, rbx				; reset rax to dst

	cmp		rbx, 0					; if len == 0, no need to strcpy
	je		end

	mov		rdi, rax				; dst become P1 for strcpy
	pop		rsi						; retrieve src, become P2
	push	rax						; save dst on stack
	call	ft_strcpy				

	pop		rax						; retrieve dst, is RAX

	mov		rsp, rbp
	pop		rbp

end:
	ret
