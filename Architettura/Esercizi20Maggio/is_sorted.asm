.globl _start
.data
    size:  .word 3
    array: .word 1,2,3
    
.text
_start:
    # chiama is_sorted
    la   a0, array
    la   a1, size
    lw  a1, 0(a1)
    jal  ra, is_sorted
    
    #exit
    li   a7, 10
    ecall

#*************************************************************************************
# completare la funzione is_sorted  nel campo di sotto (1 se l' array è ordinato in ordine crescente, 0 altrimenti)
is_sorted:
	li t0, 1	#valore di return = 1
	addi a1, a1, -1
	
loop:
	beq a1, zero, end_loop	
	lw t1, 0(a0)
	lw t2, 4(a0)
	bgt t1, t2, false
	addi a0, a0, 4	#incremento riferimento array
	addi a1, a1, -1	#decremento contatore
	j loop
	false:
		li t0, 0	#return false
	
end_loop:
	mv a0, t0
	ret