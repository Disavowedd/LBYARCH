section .data
constmh dq 1000.0
constms dq 3600.0 

section .text
bits 64
default rel

global getAcceleration

getAcceleration:
	mov rdi, rdx	;good practice
	mov r11,r8		;good practice
	L1:	
		movsd xmm5, [rdi]	; 1st element of nth car (initialspeed)
		add rdi, 8
		movsd xmm6, [rdi]	; 2nd element of the nth car (final speed
		add rdi, 8	
		movsd xmm7, [rdi]	; 3rd element of the nth car (time) 
		add rdi, 8
		
		subsd xmm6,xmm5		; ans = finalspeed - initialspeed
		mulsd xmm6, [constmh] 
		divsd xmm6, [constms] 
		divsd xmm6, xmm7	; accel = ans/time 

		
		CVTSD2SI r10, xmm6  ; convert double to int
	
		mov [r11], r10  		; add to array
		add r11, 4			; increment array
		loop L1
	ret