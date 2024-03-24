.globl _start

.text

_start:
	#trovare il max tra t1, t2, t3 e metterlo in t3
	addi t0, zero, 41
	addi t1, zero, 45
	addi t2, zero, 47
	add t3, x0, t0  #carico 41 in t3
	
	bge t3, t1, end1   #confronto se t3>=t1
		add t3, x0, t1
    end1:
    bge t3, t2, end2   #confronto se t3>=t2
    	add t3, x0, t2
    end2:
    	#t3 ha il massimo
    	
    print:
    addi a0, t3, 0
    li a7, 1
    ecall

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
