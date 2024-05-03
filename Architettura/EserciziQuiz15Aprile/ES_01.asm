.globl _start
.section .data
    buffer: .string  "test string"
    low:    .byte  'A'
    high:   .byte  'Z'

.text
_start:
    # call contains
    la   a0, buffer
    la   a1, low
    la   a2, high
    lbu  a1, 0(a1)
    lbu  a2, 0(a2)
    jal  ra, contains

    # exit
    li   a7, 10
    ecall

#******************************************
# completare la funzione contains qua sotto

contains:
    li t0, 0     #valore di ritorno
    
CICLO:
    lbu t1, 0(a0)  #carico  char
    #se char<low or char>max allora non compreso
    beq t1, zero, FINECICLO 
    blt t1, a1, NULLA
    bgt t1, a2, NULLA
    li t0, 1    #se arrivo qua vuol dire che char è compreso negli estremi
    j FINECICLO #exit
NULLA:    
    addi a0, a0, 1  #passo al char successivo
    j CICLO
    
FINECICLO:      #carico risultato
    mv a0, t0
    ret