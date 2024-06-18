.globl _start
.data
  size:  .word  10
  array: .word  1,3,5,6,7,8,9,25,30,40

.text
_start:
    # chiama issorted
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)
    jal  ra, issorted
    
    #exit
    li   a7, 10
    ecall   

#****************************************************
# completare la funzione issorted nel campo di sotto
issorted:
    addi a1, a1, -1 #il ciclo deve essere eseguito n-1 volte
    
    loop:
    beq a1, zero, end_loop
    lw t0, 0(a0)    #carico elemento i
    lw t1, 4(a0)    #carico elemento i+1
    ble t0, t1, continue    #if t0<=t1 continuo il ciclo
    #caso di uscita 
    li a0, 0
    ret
    #se l' array è ancora ordinato continuo il ciclo
    continue:
    addi a0, a0, 4
    addi a1, a1, -1
    j loop
    end_loop:  
    li a0, 1
    ret
    
