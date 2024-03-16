.globl _start

.text

_start:

	li t0, 2
	li t1, 4
	
	sub t0, t0, t1
	blt t0, zero, ELSE
	beq zero,zero, ENDIF
	
	ELSE: 
	li t0, 0
    	ENDIF:

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
