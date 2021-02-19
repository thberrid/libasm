structure

section .data
hello:
		.string db "ok", 10 		; 10 is for \n
		.len equ $ - hello.string	; the len is the diff between "here" and the previous address
section .text
		global _start
		global main

start:
	call _main
	ret

push	rbp
mov		rbp, rsp
sub		rsp, 16
mov		RDI, 

registers

EBP		base : adresse de retour de la procedure n-1
ESP		pile : address of current stack 

EIP		current instruction
	changed by JMP

EF		Flags

RAX		fn's return value, set before sys call INT
		for example :
		MOV EAX 4	; setting syscall for write, NB that 1 is for exit
		syscall	; interrupting, we will call EAX syscode
EBX		P1
ECX		P2
EDX		P3

Stack goes from MAX to 0, so 
	PUSH nValue 
	is like 
	SUB ESP, 4
	MOV [ESP], dword nValue
Also
	POP EAX
	equal to
	MOV EAX, dword [ESP]
	ADD ESP, 4
Also also
	SUB ESP, 4 	; means we allocated 4 bytes on the stack	

instructions code

MOV 	A, B	; copy B -> A
ADD		A, B
SUB		A, B

PUSH	value	; increment ESP, then copy value at (*ESP)
POP 	EAX		; copy (*ESP) to EAX, then decrement ESP


CALL	_fn		; PUSH EIP to stack, then JUMP
RET				; is equal to
					POP 	EAX
					JUMP	EAX

