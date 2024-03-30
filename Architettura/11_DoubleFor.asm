.globl _start

.text

# for i=0; i<a
#	for j=0; j<b
#		R = 2*R+i+j

_start:

	li t0, 10 # a   uso la load per evitare lettura sporca da memoria
	li t1, 5 # b
	li t2, 0 # R
	li t3, 0 # i
	
	for1:
	bge t3, t0 endfor1
		li t4, 0 # j da ripristinare ogni volta
		for2:
		bge t4, t1, endfor2
			add t2, t2, t2 #R*2
			add t2, t2, t3 # R+i
			add t2, t2, t4 # R+j
			addi t4, t4, 1
			j for2
		endfor2:
		addi t3, t3, 1
		j for1
	endfor1:
    
    # stampo il risultato
	li a7, 1
	mv a0, t2
	ecall

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
