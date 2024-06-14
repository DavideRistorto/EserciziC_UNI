.globl _start

.text

_start:
	li t0,  0xFFFFFFFFFFFFFFFF
	li t1,  0x0000000000000001
	add t2, t0, t1
	
    

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
