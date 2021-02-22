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

registers

RBP		base pointer : adresse de retour de la procedure n-1
RSP		stack pointer : address of current stack 
		points to the bottom of current fn stack frame
		local variables are accessed relative to it.
RIP		instruction pointer : current instruction. changed by JMP

RFLAGS	Flags

RAX		fn's return value
		also passed to syscall, so
		MOV RAX, 4	; setting syscall for write, NB that 1 is for exit
		SYSCALL		; interrupting, we will call RAX syscode
RBX		?
RDI		P1
RSI		P2
RDX		P3 + 2nd return register
RCX		P4
R8		P5
R9		P6
R10		? passing static chain pointer

XMM0-15	floating values

RAX----------------------	64b	
			EAX----------	32b
					AX---	16b
					AH|AL	8b|8b

Stack goes from MAX to 0
MAX				0	
[STACK **** | **** HEAP|DATA]
so
SUB RSP, 4 	; means we allocated 4 bytes on the stack	
ADD RSP, 4	; deallocation  

instructions code

MOV 	A, B	; copy B -> A
LEA
ADD		A, B
SUB		A, B

PUSH	value	; SUB RSP, 8
				; MOV [RSP], qword nValue
POP 	RAX		; MOV RAX, qword [RSP]
				; ADD RSP, 8
JMP		RAX		; MOV RIP, RAX

CALL	_label	; PUSH	RIP
				; JUMP	_label
RET				; POP 	RIP
				; JUMP	RSP

ENTER			; PUSH RBP
				; MOV RBP, RSP
				; SUB RSP, size
LEAVE			; MOV RSP, RBP
				; POP RBP


directive de donnees
x86
b	1 byte	8bits
w	1 word 	16bits
d	2w		32bits
q	4w		64bits	


