.globl _start
.data
    str: .string "1234C"

.text
_start:
    # call charAt
    la  a0, str
    jal ra, isnumber

    #exit
    li   a7, 10
    ecall

#**************************************************************
# completare la isnumber qua sotto (controlla se una stringa è un numero)
isnumber:
	li t0, 48 	#carattere '0'
	li t1, 57	#carattere '9'
	li t3, 1	#valore true a default
	
WHILE:
	lb t2, 0(a0)		#leggo il carattere
	beq t2, zero, END_WHILE
	blt t2, t0, NO_CIFRA
	bgt t2, t1, NO_CIFRA
	addi a0, a0,1	#incremento il carattere
	j WHILE
	NO_CIFRA:		#return false
		li t3, 0
	
END_WHILE:
	mv a0, t3
	ret