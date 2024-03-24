.globl _start

.text

_start:

	li t0, 2
	li t1, 1
	
    addi t0, t0, -2
    add t0, t0, t1
    bge t0, t1, ELSE
    	addi t0, t0, 1
    j ENDIF
    ELSE:
    	addi t1, t1, 1
    ENDIF:

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
