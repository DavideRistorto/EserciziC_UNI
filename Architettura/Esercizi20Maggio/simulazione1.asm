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
    li t0, 1        #result di default = 1
    addi a1, a1, -1 #ciclo fatto n-1 volte
    
    loop:
        beq a1, zero, end_loop
        lw t1, 0(a0)    #carico elemento a[i]
        lw t2, 4(a0)    #carico elemento a[i+1]
        ble t1, t2, continue
        li t0, 0        #result = 0
        j end_loop      #uscita anticipata dal ciclo
        continue:
        addi a1, a1, -1 #decremento indice
        addi a0, a0, 4  #incremento array
        j loop          #inizio ciclo
        
    end_loop:
    mv a0, t0
    ret
    