.globl _start
.data
    size:  .word 8
    array: .word 5,3,7,2,6,4,8,1
    
.text
_start:
    # chiama swap
    la   a0, array
    la   a1, size
    lw  a1, 0(a1)
    jal  ra, min_array
    
    #exit
    li   a7, 10
    ecall

#*************************************************************************************
# completare la funzione min_array  nel campo di sotto (restituisce l' indice dell' elemento più piccolo)
min_array:
	li t0, 0  			# indice del minimo
	lw t1, 0(a0)   	#valore minimo
	li t2, 1  			# indice attuale dell' array
	addi a0, a0, 4	#carico il secondo elemento
	
for:
	lw t3, 0(a0)    # carico l elemento successivo
	beq t2, a1, end_for
		bge t3, t1, skip
			mv t1, t3    # aggiorno val minimo
			mv t0, t2    # aggiorno indice minimo
						
skip:
	addi a0, a0, 4     # scorro array
	addi t2, t2, 1   # aggiorno indice corrente
	j for
	
end_for:
	mv a0, t0
	ret