.globl _start
.data
    size:  .word 4
    array: .word 1,2,3,4
.text
_start:
    # chiama invert
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)        
    jal  ra, invert
    
    #exit
    li   a7, 10
    ecall

#***************************************************
# completare la funzione invert nel campo di sotto
invert:
	addi sp, sp, -32
	sd ra, 0(sp)
	sd a0, 8(sp)
	sd s1, 16(sp)   
    sd s2, 24(sp)
    
    li s1, 0	#primo indice
    addi s2, a1, -1 #ultimo elemento = size -1 
   
loop:
	beq s1, s2, end_loop
	ld a0, 8(sp)		#carico il riferimento all' array
	mv a1, s1		#carico x = s1
	mv a2, s2		#carico y = s2
	jal ra, swap
	addi s1, s1, 1
	addi s2, s2, -1
	j loop
    
    
end_loop:
	#ripristino fram pointer
	ld ra, 0(sp)
	ld s1, 16(sp)   
    ld s2, 24(sp)
	addi sp, sp, 32
	ret

#***************************************************
swap:
	li t0, 4			#4 d' appoggio
	mul t1, t0, a1	#indice x
	mul t2, t0, a2	#indice y
	add t1, t1, a0	#aggiorno il riferimento
	add t2, t2, a0	#aggiorno il riferimento
	lw t3, 0(t1)		#array[x]
	lw t4, 0(t2)		#array[y]
	sw t4, 0(t1)		#array[x] = y
	sw t3, 0(t2)		#array[y] = x
	
ret
