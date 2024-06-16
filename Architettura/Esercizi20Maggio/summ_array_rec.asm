.globl _start
.data
    array: .word  1,2,3,4,5,6,7,8,9,10
    size:  .word  10
    
.text
_start:
    # chiama sumarray
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)
    jal  ra, sumarray
    
    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione sumarray nel campo di sotto
sumarray:
	bne a1, zero, summaray_rec
	li a0, 0
	ret

summaray_rec:
	addi sp, sp, -16
	sd ra, 0(sp)
	sd s1, 8(sp)
	
	lw s1, 0(a0)		#s1 = salvo array[i]
	addi a0, a0, 4		#passo all' elemento successivo
	addi a1, a1, -1		#decremento il contatore
	jal ra, sumarray	#chiamata ricorsiva
	add a0, a0, s1
	
	ld ra, 0(sp)
	ld s1, 8(sp)
	addi sp, sp, 16
	ret
