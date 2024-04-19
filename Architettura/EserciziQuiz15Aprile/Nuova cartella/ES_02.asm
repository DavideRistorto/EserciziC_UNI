 .globl _start
    .data        
        array: .word 1,1,2,2,3,4,4,1
        x:     .word 0
        y:     .word 1
        
    .text
    _start:
        # chiama equal
        la   a0, array
        la   a1, x
        lw   a1, 0(a1)
        la   a2, y
        lw   a2, 0(a2)
        jal  ra, equal
        
        #exit
        li   a7, 10
        ecall
    
    #***************************************************
    # completare la funzione equal nel campo di sotto
equal:
    li t0, 4        #registro di appoggio per fare le moltiplicazioni con 4
    mul t1, t0,a1   #valore di x*4
    add t1, t1, a0  #carico [x] indirizzo
    mul t2, t0, a2  #valore di y*4
    add t2, t2, a0  #carico [y] indirizzo
    
    lw t3, 0(t1)    #t3 = array[x]
    lw t4, 0(t2)    #t4 = array[y]
    
    bne t3, t4, NO_UGUALI
    li a0, 1    #se sono qua allora sono uguali e ritorno 1
    ret
    
    
NO_UGUALI:
    li a0, 0    #se sono qua allora NON sono uguali e ritorno 0
    ret
    