.globl _start
.data        
    size:   .word 16
    array:  .word 12, 2
    result: .word 0
    
.text
_start:
    #carico i dati
la t1, size  #size
add t2, x0, x0 #contatore ciclo
add t3, x0, x0 #accumulatore somma
add t4, x0, x0

INIZIO_CILO:
addi t4, t4, 4 #offset
bge t2, t1, FINE_CICLO   #i>=size
mul t5, t4, t2
lw t6, t2(t1)
add t3,t3, t6
addi t2, t2, 1


FINE_CICLO:
sw t3, 8(t1)