section .data
constmh dd 1000.0
constms dd 3600.0 

section .text
bits 64
default rel

global getAcceleration

getAcceleration:
	mov rdi, rdx	;good practice
	mov r11,r8		;good practice
	L1:	
		movss xmm5, [rdi]	; 1st element of nth car (initialspeed)
		add rdi, 4
		movss xmm6, [rdi]	; 2nd element of the nth car (final speed
		add rdi, 4	
		movss xmm7, [rdi]	; 3rd element of the nth car (time) 
		add rdi, 4
		
		subss xmm6, xmm5		; ans = finalspeed - initialspeed
		mulss xmm6, [constmh] 
		divss xmm6, [constms] 
		divss xmm6, xmm7	         ; accel = ans/time 

		
		CVTSS2SI eax, xmm6        ; convert double to int
	
		mov [r11], eax  		; add to array
		add r11, 4		; increment array
		loop L1
	ret