section .text
bits 64
default rel

global getVelocity
global getAcceleration


getVelocity:
    ;xmm0 = iniVelocity, xmm1 = finVelocity, xmm2 = time
    subss xmm0, xmm1
    divss xmm0, xmm2 ;this is Km/h
    ret