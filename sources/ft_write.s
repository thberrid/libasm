section .text
    %define SYS_WRITE 1
    extern __errno_location
    global ft_write

ft_write:
    mov rax, SYS_WRITE
    syscall
    cmp rax, 0
    jge end
    neg rax
    push rax
    call __errno_location wrt ..plt
    pop  qword [rax]
    mov rax, -1
end:
    ret
