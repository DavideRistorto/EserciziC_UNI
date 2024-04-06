.globl _start
.data
  size:   .word 16
  array:  .dword 12, 2, 1, 3, 5, 1, 7, 1, -1, 4, -2, -3, 1, 9, -6, 10
newline:  .string " "

.text
_start:

la t0, size
lw t0, 0(t0)				#size	
li t1, 8					#temp 8
mul t1, t1,t0			#t1 = 8*size
addi t1, t1, -8			#t1 = (size*8) - 8 per avere l' ultimo indice
la t2, array				#t2 = indirizzo array
mv t4, t2				#t4 sarà l'indice iniziale
add t2, t2, t1			#t2 sarà l'indice finale
srai t0, t0, 1

beq t0, zero, FINE_CICLO

CICLO:
	lw t5, 0(t4)			#carico primo elem array
	lw t3, 0(t2)			#carico ultimo elem array
	add t6, zero, t5	# t6->temp = primo
	sw t3, 0(t4)			#array[primo] = ultimo
	sw t6, 0(t2)			#array[ultimo]  = primo
	addi t0, t0, -1		#decremento size
	addi t4, t4, 8
	addi t2, t2, -8
	bne t0, zero, CICLO	
FINE_CICLO:	

la t0, size
lw t0, 0(t0)
la t1, array

CICLO2:
	lw t2, 0(t1)
	# stampo elemento
	li a7, 1
	mv a0, t2
	ecall
		la a0, newline        #print newline
	li a7, 4
	ecall
	addi t0, t0, -1
	addi t1, t1, 8
	bne t0, zero, CICLO2

