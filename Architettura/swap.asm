.globl _start
.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
    x:     .word 0
    y:     .word 2
    
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
	li t0, 4			#4 d' appoggio
	mul t1, t0, a1	#indice x
	mul t2, t0, a2	#indice y
	add t1, t1, a0	#aggiorno il riferimento
	add t2, t2, a0	#aggiorno il riferimento
	lw t3, 0(t1)		#array[x]
	lw t4, 0(t2)		#array[y]
	sw t4, 0(t1)		#array[x] = y
	sw t3, 0(t2)		#array[y] = x
	
ret
	
	
	


