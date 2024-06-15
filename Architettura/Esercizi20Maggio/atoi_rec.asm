.globl _start
.data
    numstr: .string  "123"
.text
_start:
    # chiama strlen per ottenere la lunghezza della stringa
    la   a0, numstr
    jal  ra, strlen
    
    # chiama atoi
    mv   a1, a0
    la   a0, numstr
    jal  ra, atoi

    #exit
    li   a7, 10
    ecall

#***************************
# strlen
# a0 - str
#***************************
# usare la funzione strlen sviluppata in precedenza 

strlen:
    li t0, 0 #contatore lunghezza
    li t1, 0 #carattere '\0'
ciclo:
    lbu t2, 0(a0)
    beq t2, t1, exit  # char == '\0' -> exit
    addi t0, t0 , 1   #incremento lunghezza
    addi a0, a0 , 1
    j ciclo
exit:    
    mv a0, t0
    jr ra

#******************
# unsigned long atoi(char *str, unsigned long n) {
#     if (n == 0)
#       return 0;
#     return (10*atoi(str, n-1) + str[n-1] - '0');
# }

atoi:
	bne a1, zero, atoi_rec
		li a0, 0
		ret

atoi_rec:
	addi sp, sp, -16
	sd ra, 0(sp)
	sd s1, 8(sp)    # spazio per str[n-1]
	
	addi a1, a1, -1   # n-1
	add t0, a0, a1    # str[n-1]
	lbu s1, 0(t0)     # ricavo il byte di str[n-1]
	addi s1, s1, -48  # str[n-1] - '0'
	
	jal ra, atoi      # chiamo la funzione
	
	li t1, 10         
	
	mul a0, a0, t1    # a0 = 10 * atoi(str, n-1)
	add a0, a0, s1    # a0 = a0 + str[n-1] - '0'
	
	ld ra, 0(sp)
	ld s1, 8(sp)
	addi sp, sp, 16
	ret
	
	
	

