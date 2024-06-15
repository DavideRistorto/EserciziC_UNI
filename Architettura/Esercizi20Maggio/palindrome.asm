    .globl _start
    .data
        array: .word 1,2,3,4,5,4,3,2,1
        size:  .word 9
        
    .text
    _start:
        # chiama palindrome
        la   a0, array
        la   a1, size
        lw   a1, 0(a1)
        jal  ra, palindrome
        
        #exit
        li   a7, 10
        ecall
#*********************************************************
# completare la funzione palindrome nel campo di sotto
palindrome:
	addi sp, sp, -40
	sd ra, 0(sp)
	sd a0, 8(sp)		#salvo l' array
	sd s1, 16(sp)	#indice i
	sd s2, 24(sp)	#indice j
	sd s3, 32(sp)	#result
	
	li s1, 0			# i = 0
	addi s2, a1, -1	# j  =size *1
	li s3, 1			# result = 1
	
loop:
	bge s1, s2, end_loop
	beq s3, zero, end_loop	#se result = 0 -> end
	ld a0, 8(sp)		#carico l' array
	mv a1, s1		#carico i in a1
	mv a2, s2		#carico j in a2
	jal ra, equal
	and s3, s3, a0		# s3 = s3 && a0
	addi s1, s1, 1
	addi s2, s2, -1
	j loop
	
#ripristino frame pointer
end_loop:
	mv a0, s3
	ld ra, 0(sp)
	ld s1, 16(sp)	
	ld s2, 24(sp)	
	ld s3, 32(sp)
	addi sp, sp, 40
	ret

#*********************************************************
equal:
    li t0, 4        #registro di appoggio per fare le moltiplicazioni con 4
    mul t1, t0,a1   #valore di x*4
    add t1, t1, a0  #carico [x] indirizzo
    mul t2, t0, a2  #valore di y*4
    add t2, t2, a0  #carico [y] indirizzo
    
    lw t3, 0(t1)    #t3 = array[x]
    lw t4, 0(t2)    #t4 = array[y]
    
    bne t3, t4, NO_UGUALI
    li a0, 1    #se sono qua allora sono uguali e ritorno 1
    ret
    
NO_UGUALI:
    li a0, 0    #se sono qua allora NON sono uguali e ritorno 0
    ret