.globl _start
.data
    size:   .word  5                 # size of the array        
    array:  .dword 1,1,1,1,1    # array of long integers
    result: .word  -1                 # store the result
    
.text
_start:
# CONTROLLARE SE L'ARRAY E' ORDINATO
#NOTA BENE: USANDO LE DOUBLE-WORD, OFFSET DIVENTA 8
la t1, size     #carico e salvo size
lw t0, 0(t1)    #size
# il ciclo deve essere eseguito size-1 volte
addi t0, t0, -1 
la t3, array    #carizo indirizzo array
li t5, 1        # risultato = 1 di default

ble t0, zero, FINECICLO #se size =< 0 -> exit

CICLO:
    lw t2, 0(t3)    #carico un elem.
    lw t4, 8(t3)    #carico elem. successivo
    
    bgt t2, t4, NON_ORDINATO	#se t1>t2 non ordinato
    addi t0, t0, -1 #decremento size
    addi t3, t3, 8
    bne t0, zero, CICLO
    j FINECICLO
    
    NON_ORDINATO:
    add t5, zero, zero #result = 0
    j FINECICLO

FINECICLO:
la t6, result
sw t5, 0(t6)