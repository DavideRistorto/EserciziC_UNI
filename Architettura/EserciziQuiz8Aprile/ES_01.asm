.globl _start
.data
    str: .string "Hello World!"
    n:   .word   6

.text
_start:
    # call charAt
    la  a0, str
    la  a1, n
    lw  a1, 0(a1)
    jal ra, charAt

    #exit
    li   a7, 10
    ecall

#******************************************
# completare la charAt qua sotto

charAt:
    li t0, 0            # Inizializza il contatore i = 0
    lw t2, 0(a0)        # Carica il primo carattere
CICLO:
    beq t0, a1, FINECICLO  # Se i == lunghezza, esce dal ciclo
    addi a0, a0, 1      # Passa al carattere successivo
    addi t0, t0, 1      # Incrementa il contatore i
    lw t2, 0(a0)        # Carica il carattere successivo
    j CICLO             # Ritorna all'inizio del ciclo

FINECICLO:
    mv a0, t2           # Restituisce il carattere
    jr ra               # Ritorna al chiamante
