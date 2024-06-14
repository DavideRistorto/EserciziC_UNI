.globl _start
.data
    str: .string "ciao miglio gay 123"

.text
_start:
    # call charAt
    la  a0, str
    jal ra, struptr

    #exit
    li   a7, 10
    ecall

#********************************************************
# completare la struptr qua sotto (rende maiuscolo tutte i caratteri)

struptr:
	li t1, 97			# 'a'
	li t2, 122			#'z'
	
WHILE:
	lb t0, 0(a0)		#carico inizio stringa in t0
	beq t0, zero, END_WHILE
	#controllare se è una lettera
	blt t0, t1, NO_MINUSCOLA
	bgt t0, t2, NO_MINUSCOLA
	addi t0, t0, -32	#decremento il valore ascii
	sb t0, 0(a0)
	
	NO_MINUSCOLA:
	addi a0, a0, 1
	j WHILE
	
END_WHILE:	
	ret