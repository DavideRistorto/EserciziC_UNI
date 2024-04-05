.globl _start
.data        
    size:   .word 16
    array:  .word 12, 2, 1, 3, 5, 1, 7, 1, -1, 4, -2, -3, 1, 9, -6, 10
    result: .word 0
    
.text
_start:
    # FARE LA SOMMA DI TUTTI GLI ELEMENTI DELL' ARRAY
    la t5, array
    la t4, size     #carico l'indirizzo di size
    lw t0, 0(t4)    #carico il valore size
    li t2, 0        # sum = 0
beq t0, zero, FINECICLO   #if size = 0 -> exit  

CICLO:
    lw t1, 0(t5)    #primo elem. vettore
    add t2, t2, t1  #sum += elem
    addi t0, t0, -1 #size -= 1
    # passo all elem. successivo incrementando l' indirizzo
    addi t5, t5, 4  
    bne t0, zero, CICLO
FINECICLO:
    la    t1, result
    sw    t2, 0(t1)