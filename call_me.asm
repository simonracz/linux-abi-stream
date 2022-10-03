global write_in_asm
global exit_in_asm

section .text
write_in_asm: ; (int fd, char * mem, int size) (rdi, rsi, rdx)
        mov rax, 1              ; 1 == write syscall
        syscall
	ret

exit_in_asm: ; (int) (rdi)
        mov rax, 60             ; 60 == exit syscall
        syscall
	ret

; Syscall number : rax
; up to 6 arguments
; rdi, rsi, rdx, r10, r8, r9
; Return value: rax
; clobbers : rcx, r11

; Function calls
; First 6 arguments : 
; rdi, rsi, rdx, rcx, r8, r9
; Rest of the arguments go to stack
; Return value : rax ( optionally rdx )
; Calle saved registers:
; rbx, rbp, rsp, r12, r13, r14, r15 
; ret
