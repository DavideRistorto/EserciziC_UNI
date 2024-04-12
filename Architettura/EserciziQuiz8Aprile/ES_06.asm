.globl _start
.data
    str: .string  "My string"
.text
_start:
    # call strlen
    la   a0, str
    jal  ra, strlen

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione strlen nel campo di sotto
strlen:
    li t0, 0 #contatore lunghezza
    li t1, 0 #carattere '\0'
CICLO:
    lbu t2, 0(a0)
    beq t2, t1, EXIT  # char == '\0' -> exit
    addi t0, t0 , 1   #incremento lunghezza
    addi a0, a0 , 1
    j CICLO
EXIT:    
    mv a0, t0
    jr ra