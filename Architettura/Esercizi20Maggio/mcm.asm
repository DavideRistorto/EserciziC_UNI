.globl _start
.data
    num1: .dword 5
    num2: .dword 6
.text
_start:
    # call MCD
    la    a0, num1
    la    a1, num2
    ld    a0, 0(a0)
    ld    a1, 0(a1)     
    jal   ra, mcm

    #exit
    li    a7, 10
    ecall

#****************************************************
# completare la funzione MCM nel campo di sotto
mcm:
	addi sp, sp, -24	#preparo record di attivazione
	sd ra, 0(sp)
	sd s1, 8(sp)
	sd s2, 16(sp)
	
	mv s1, a0	#salvo num1
	mv s2, a1	#salvo num2
	jal ra, mcd
	mul t0, s1, s2	#num1 * num2
	div a0, t0, a0	#(num1 * num2) / mcd
	
	#ripristino frame pointer
	ld ra, 0(sp)
	ld s1, 8(sp)
	ld s2, 16(sp)
	addi sp, sp, 24
	ret

#****************************************************
# MCD nel campo di sotto
mcd:
    
CICLO:
    beq a0, a1, FINECICLO   #num1==num2 exit
    ble a0, a1, ELSE
    sub a0, a0, a1
    j CICLO
ELSE:
    sub a1, a1, a0
    j CICLO
    
FINECICLO:
    mv a0, a0
    ret