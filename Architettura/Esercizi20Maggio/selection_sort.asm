  .globl _start
  .data
    size:  .word  8
    array: .word  1,5,3,7,2,6,4,8
  
  .text
  _start:
      # chiama selection_sort
      la   a0, array
      la   a1, size
      lw   a1, 0(a1)
      jal  ra, selection_sort
      
      #exit
      li   a7, 10
      ecall   
#***************************************************
minarray:
	li t0, 0  			# indice del minimo
	lw t1, 0(a0)   	#valore minimo
	li t2, 1  			# indice attuale dell' array
	addi a0, a0, 4	#carico il secondo elemento
	
for:
	lw t3, 0(a0)    # carico l elemento successivo
	beq t2, a1, end_for
		bge t3, t1, skip
			mv t1, t3    # aggiorno val minimo
			mv t0, t2    # aggiorno indice minimo
						
skip:
	addi a0, a0, 4     # scorro array
	addi t2, t2, 1   # aggiorno indice corrente
	j for
	
end_for:
	mv a0, t0
	ret
#****************************************************
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

#****************************************************
# completare la funzione selection_sort nel campo di sotto

selection_sort:
	li t0, 1
	bgt a1, t0, selection_sort_rec
	ret 

selection_sort_rec:
	addi sp, sp, -24
	sd ra, 0(sp)
	sd s1, 8(sp)
	sd a0, 16(sp)
	
	mv s1, a1	#salvo la size in s1
	jal ra, minarray
	mv a2, a0
	li a1, 0
	ld a0, 16(sp)	#ricarico array
	jal ra, swap
	addi a1, s1, -1	#size - 1
	addi a0, a0, 4
	jal ra, selection_sort
	
	ld ra, 0(sp)
	ld s1, 8(sp)
	addi sp, sp, 24
	ret