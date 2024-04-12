.globl _start
.data
    str:  .string "my long string"
    c:    .byte 'g'
.text
_start:
    # call strchridx
    la   a0, str
    la   a1, c
    lb   a1, 0(a1)
    jal  ra, strchridx

    #exit
    li   a7, 10
    ecall

#****************************************************
# completare la funzione strchr nel campo di sotto
strchridx:
li t0, -1   #risultato defaul
li t1, 0    #contatore indice
li t3, 0    #carattere '/0'

CICLO:
    lb t2, 0(a0)            #carico char della stringa
    beq t2, a1, TROVATO     #se il char corrisponde esco
    beq t2, t3, FINESTRINGA #se la stringa finisce esco con esito negativo
    addi t1, t1, 1          #incremento contatore
    addi a0, a0, 1          #incremento riferimento stringa
    j CICLO
    
TROVATO:
    mv t0, t1   #se trovato allora setto come result = contatore
    
FINESTRINGA:
    mv a0, t0
    jr ra
    