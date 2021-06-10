	.text
	.globl	bitrev
	.type	bitrev, @function

bitrev:
		mov     %rdi, %rax
		ror     $32, %rdi
		rorw    $8, %ax
		rorl 	$16, %eax
		rorw 	$8, %ax	
		rorw    $8, %di
		rorl 	$16, %edi
		rorw 	$8, %di
		shlq    $32, %rax
		or 		%rdi, %rax
		movq 	%rax, %rdi
		movq 	$0x0F0F0F0F0F0F0F0F, %r10
		shrq	$4, %rdi
		andq	%r10, %rdi
		andq 	%r10, %rax
		shlq	$4, %rax
		orq		%rdi, %rax
		movq 	%rax, %rdi	
		movq 	$0x5555555555555555, %r10
		shrq	$1, %rdi
		andq	%r10, %rdi
		andq 	%r10, %rax
		leaq    (%rdi,%rax, 2), %rdi
		movq 	%rdi, %rax
		movq 	$0x3333333333333333, %r10
		shrq	$2, %rax
		andq	%r10, %rax
		andq 	%r10, %rdi
		leaq    (%rax,%rdi, 4), %rax
	ret

	.size	bitrev, .-bitrev
