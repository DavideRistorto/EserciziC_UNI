.globl _start
.data
    num: .dword 5
.text
_start:
    # call fib
    la    a0, num
    ld    a0, 0(a0)
    jal   ra, fib

    #exit
    li    a7, 10
    ecall
    
#int fib(int n) {
#	if (n==0)
#		return 0;
#	else if (n==1)
#		return 1;
#	else
#		return fib(n-1) + fib(n-2);
#}

#****************************************************
# completare la funzione fib nel campo di sotto
fib:
	li t0, 2
	li t1, 0
	bge a0, t0, fib_rec		#a0 >= 2 ricorsione
	beq a0, zero, end_fib	# a0 = 0 return 0
	addi t1, t1, 1			# a0 = 1 return 1
	end_fib:
	mv a0, t1
	ret
	
fib_rec:
	add sp, sp, -24
	sd ra, 0(sp)
	sd s1, 8(sp)		# salvataggio del risultato di fib(n-1)
	sd s2, 16(sp)	# salvataggio n
	
	mv s2, a0
	addi a0, s2, -1	# n= n-1
	jal ra, fib
	mv s1, a0	#salvo il return di fib(b-1)
	addi a0, s2, -2	# n = n-2
	jal ra, fib
	add a0, s1, a0
	
	ld ra, 0(sp)
	ld s1, 8(sp)
	ld s2, 16(sp)
	add sp, sp, 24
	
	ret