.globl _start
.data
    str1: .string  "aaa"
    str2: .string  "aaa"
.text
_start:
    # call strcmp
    la   a0, str1
    la   a1, str2
    jal  ra, strcmp

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione strcmp nel campo di sotto
strcmp:
	li t0, 0	#valore di ritorno settato a TRUE
	li t4, 0	#valore 0 per definire la fine della stringa = '/0'
CICLO:
	lbu t2, 0(a0)		#carico char stringa1
	lbu t3, 0(a1)		#carico char stringa2
	beq t2, t4, FINE_STRINGA1  #controllo se la prima stringa sia finita
	bne t2, t3, FINECICLO			#se non sono uguali esco
	addi a0, a0, 1
	addi a1, a1, 1
j CICLO

#controllo se anche la seconda stringa è finita, se si alla sono uguali
FINE_STRINGA1:
beq t3, t4, EXIT

FINECICLO:	#setto result a false
	li t0, 1	

EXIT:				#finisco la procedura
	mv a0, t0
	jr ra