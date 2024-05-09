.globl _start
.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
    x:     .word 0
    y:     .word 1
    
.text
_start:
    # chiama swap
    la   a0, array
    la   a1, x
    lw   a1, 0(a1)
    la   a2, y
    lw   a2, 0(a2)
    jal  ra, swap
    
    #exit
    li   a7, 10
    ecall

#***************************************************
# completare la funzione swap nel campo di sotto
swap:
    slli a1, a1, 2  #converto gli indici in offset -> indice *4  
    slli a2, a2, 2  #converto gli indici in offset -> indice *4
    add t0, a0, a1  #indice x
    add t1, a0, a2  #indice y
    lw t2, 0(t0)    #carico x
    lw t3, 0(t1)    #carico y
    #temp non serve perchè non sovrascrivo direttamente i valore dentro l' array
    sw t2, 0(t1)    # temp = array[x]
    sw t3, 0(t0)    #array[x] = array[y]
    ret