.globl _start
.data
    numstr: .string  "1234"
.text
_start:
    # call isnumber
    la   a0, numstr
    jal  ra, isnumber

    #exit
    li   a7, 10
    ecall

#*******************************************************************************
# digit
# a0 - char
# return 1 if char is a digit, 0 otherwise
#*******************************************************************************
digit:
    li t0, 48
    li t1, 57
    blt a0, t0, return_0
    bgt a0, t1, return_0
    li a0, 1
    ret
return_0:
    li a0, 0
    ret

#****************************************************
# completare la funzione isnumber nel campo di sotto
isnumber:
    #preparo frame 
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)
    
    mv s0, a0  #salvo in s0 il riferimento all' array
    
    loop:
        lbu a0, 0(s0)               #carico carattere
        beq a0, zero, exit_true     #fine stringa quindi se arrivo qua è un numero
        jal ra, digit               #chiamo digit con parametro il carattere appena caricato in a0
        beq a0, zero, exit_false    #se digit mi da zero, esco è ritorno zero
        addi s0, s0, 1              #aggiorno il riferimento per il prossimo carattere
        j loop                      #ricomincio il ciclo

exit_false:
    li a0, 0
    j exit
exit_true:
    li a0, 1
exit:
    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    ret
