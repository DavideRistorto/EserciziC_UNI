.globl _start
.data        
    size:   .word 16
    array:  .word 12, 2, 1, 3, 5, 1, 7, 1, -1, 4, -2, -3, 1, 9, -6, 10
    result: .word 0
    
.text
_start:
# TROVARE IL MAX ELEMENTO DELL' ARRAY
la t4, size     #carico indirizzo size
lw t0, 0(t4)    # carico val size
la t3, array    # indirizzo array

#metto max = al primo valore dell' array
lw t2, 0(t3)
mv t1, t2

CICLO:
    lw t2, 0(t3)    #carico valore array
    bge t1, t2, NULLA   #controllo se max>=val, nel caso non faccio nulla
    mv t1, t2       #max = val
    
    NULLA:
    addi t0, t0, -1 #decremento size
    addi t3, t3, 4  #aggiorno l' indirizzo
    bne t0, zero, CICLO
FINE_CICLO:
la t5, result
sw t1, 0(t5)