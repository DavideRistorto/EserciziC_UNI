.globl _start

.text

# restituire il numero di 1 della rappresentaizion in 
# binario contenuto in t0

#idea di soluzione
# N  = 37 # number in t0
# M  = 1  # mask
# R  = 0  # result
# i  = 64 # counter
# do {
#    R = R + N&M  # maschera di bit
#    N = N >> 1   # shift logico a destra
#    i = i - 1
# } while (i > 0)  # fine del ciclo
#


_start:

	# leggo un intero da terminale e metto in t0
    li a7, 5
    ecall
    mv t0, a0

	li t1, 1   #M
	li t2, 0  #R
	li t3, 64 #i -->contatore del ciclo
	
	loop:
	and t5, t0, t1
	add t2, t2, t5
	srli t0, t0, 1   # shift lofico cosi da mettere uno 0 alla sinistra
	addi t3, t3, -1 #decremento i
	
	ble t3, zero, end1    # if i <=0 salta
	j loop
	end1:
	  
	# stampo il risultato
	li a7, 1
	mv a0, t2
	ecall
exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
