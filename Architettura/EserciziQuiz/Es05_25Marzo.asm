.globl _start
.data
    size:   .word 8                  # size of the array        
    array:  .byte 2,1,3,2,3,-6,1,23  # the array of bytes
    result: .word 0                  # store the result
    
.text
_start:
#CONTARE IL NUMERO DI ELEMENTI DISPARI NELL' ARRAY
#NOTA BENE: TRATTANDOSI SI BYTE SI USA LA 'lb' E' UN OFFSET=1
la t1, size
lw t0, 0(t1)    #size
la t3, array    #indirizzo array
li t5, 0        #contatore dispari
li a0, 2        #divisore 2
li a1, 1        #carico 1 per confronto resto

beq t0, zero, FINECICLO
CICLO:
    lb t2, 0(t3)    #carico elem. array
    #uso remu per controllare il valore senza segno di elem (unsigned)
    remu a2, t2, a0  #resto = elem % 2
    bne a2, a1, NO_DISPARI
    addi t5, t5, 1
    NO_DISPARI:
    addi t0, t0, -1 #size-=1
    addi t3, t3, 1  #aggiorno indirizzo array
    bne t0, zero, CICLO

FINECICLO:
la t6, result
sw t5, 0(t6)