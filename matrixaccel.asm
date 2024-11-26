section .data
constmh dd 1000.0
constms dd 3600.0 

section .text
bits 64
default rel

global getVelocity



getVelocity:
    ;xmm0 = iniVelocity, xmm1 = finVelocity, xmm2 = time
    ; ((finVelo - iniVelo) 1000.0) / 3600.0
    subss xmm1, xmm0 ;this is Km/h
    mulss xmm1, [constmh]
    divss xmm1, [constms]
    divss xmm1, xmm2
    movss xmm0, xmm1



    ret