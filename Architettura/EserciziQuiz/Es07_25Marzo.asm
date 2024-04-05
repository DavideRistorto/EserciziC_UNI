.globl _start
.data
    size:   .word  8                  # size of the array        
    array:  .dword 1,2,3,4,5,6,7,8    # array of long integers

.text
_start:
    # completare con il codice assembly RISC-V nel campo sottostante
la t0, size     #size address
lw t0, 0(t0)    #size value
la t1, array    #indirizzo array

# t4 consiene l'indirizzo dell' ultimo elemento
addi a0, a0, 8  #8 di appoggio
mul t4, t0, a0 # t4 = size*8
addi t4, t4, -8 # t4 -= 8   
addi a1, a1, 2
div a1, t0, a1 #contatore del ciclo

beq t0, zero, FINE_CICLO
CICLO:
    lw t2, 0(t0)    #elem1
    lw t5, 0(t4)    #elem2
    mv t3, t2       # temp = elem1
    mv t2, t5       #elem1 = elem2
    mv t5, t3       #elem2 = elem1
    sw t2, 0(t0)    #aggiorno array
    sw t5, 0(t4)    #aggiorno array
    addi t0, t0, 8  #passo ad elem successivo
    addi t4, t4,-8  #passo ad elemento precedente
    addi t0, t0, -1
    bne t0, a1, CICLO
FINE_CICLO:

        
    