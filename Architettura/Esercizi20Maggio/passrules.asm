.globl _start
.data
      buffer: .string  "BADPass4"
.text
_start:
    # call passrules
    la   a0, buffer
    jal  ra, passrules

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione passrules nel campo di sotto
passrules:
	addi sp, sp, -24
	sd ra, 0(sp)
	sd a0, 8(sp)
	sd s1, 16(sp)	#conterrà uppercase
	
	li a1, 65			#carico 'A'
	li a2, 90			#carico 'Z'
	
	jal ra, contains
	mv s1, a0	#salvo in s1 il risultato
	
	ld a0, 8(sp)	#ricarico la stringa
	li a1, 48		#carico '0'
	li a2, 57		#carico '9'
	
	jal ra, contains
	and a0, a0, s1
	
	ld ra, 0(sp)
	ld s1, 16(sp)
	addi sp, sp, 24
	ret

#****************************************************
# contains
contains:
while:
    lbu t0, 0(a0)
    beq t0, zero, end_while
	blt t0, a1, end_if
	    bgt t0, a2, end_if
	        li a0, 1
	        ret
end_if:
    addi a0, a0, 1
    j while
  
end_while:
    li a0, 0
    ret