.globl _start

.text
_start:
	li x5, 0
    	li x6, 0xFFFFFFFFFFFFFFFF
	
	#creare la maschera
	li x7, 0x3f    #0011 1111
	slli x7 ,x7, 11

	and x28, x5, x7  #in x28 mettiamo la maschera
	slli x28, x28, 15   # shiftiamo i bit
	slli x7, x7, 15
	not x7, x7
	and x6, x6, x7
	or x6, x6, x28
    

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall

