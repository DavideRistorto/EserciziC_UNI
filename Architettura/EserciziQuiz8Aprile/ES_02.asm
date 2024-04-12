.globl _start
.data
    d: .byte '1'
.text
_start:
    # call digit
    la   a0, d
    lbu  a0, 0(a0)
    jal  ra, digit

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione digit nel campo di sotto
digit:
    li t0, 48   #valore dello 0 in ascii
    li t1, 57   #valore del 9 in ascii
    li t2, 0    #valore temporaneo di output
    # controllo: 0<= a0 <= 9, se falso exit 
    blt a0, t0, EXIT
    bgt a0, t1, EXIT
    #se la condizione è rispettata allora a0 = 1
    addi t2, zero, 1
EXIT:
    mv a0, t2
    jr ra