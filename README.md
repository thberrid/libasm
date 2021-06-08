# libasm

[some ressources / intro](https://software.intel.com/content/dam/develop/external/us/en/documents/introduction-to-x64-assembly-181178.pdf)

***some registers***

[List of registers (page 21)](https://uclibc.org/docs/psABI-x86_64.pdf)

```
RBP		base pointer : address of previous stack
RSP		stack pointer : points to the bottom of current stack frame

RFLAGS		Flags (CF, PF, ZF, ...)

RAX		fn's return value
		also passed to syscall, so
		MOV RAX, 4	; setting syscall for write, NB that 1 is for exit
		SYSCALL		; interrupting, we will call RAX syscode

RDI		P1
RSI		P2
RDX		P3 + 2nd return register
RCX		P4
R8		P5
R9		P6

```

[8-bits registers](https://stackoverflow.com/questions/20637569/assembly-registers-in-64-bit-architecture/20637866#20637866)

```
RAX----------------------   64b	
            EAX----------   32b
                    AX---   16b
                    AH|AL   8b|8b
```
---

***stack***

Stack goes from MAX to 0
```
MAX                         0	
[STACK>_____|_____<HEAP|DATA]
```
so
```
SUB RSP, 4 	; means we allocated 4 bytes on the stack	
ADD RSP, 4	; deallocation  
```

You can deferre a register using `[]`

---

***instructions codes***

```
MOV 	A, B			; copy B -> A
LEA	A, B
ADD	A, B
SUB	A, B

PUSH	value|register		; SUB RSP, 8
				; MOV [RSP], qword nValue
				
POP 	register		; MOV RAX, qword [RSP]
				; ADD RSP, 8

JMP	RAX			; MOV RIP, RAX

CALL	_label			; PUSH	RIP
				; JUMP	_label

RET				; POP 	RIP
				; JUMP	RSP

ENTER				; PUSH RBP
				; MOV RBP, RSP

LEAVE				; MOV RSP, RBP
				; POP RBP
```

***directive de donnees x86***
```
b	1 byte	8bits
w	1 word 	16bits
d	2w		32bits
q	4w		64bits	
```

***debbuging***
```
gdb --args test arg1 arg2 ...
break ft_fn
run
next
info register rax	; i r for all
x/s 0xaddr
set $rax = 0
```
***NB*** 

`gcc -S file.s`

list syscalls # `ausyscall --dump` (auditd packages)
