void invert(int[] array, int size) {
    int i;
    for (i = 0; i < size/2; i++) {
        swap(array, i, size-i-1);
    }
}  


.globl _start
.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
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
#preparo il record di attivazione
    addi sp, sp, -32
    sd ra, 0(sp)
    sd a0, 8(sp)    #swap può modificare a0 e ci serve salvarlo per accedere all' array
    sd s1, 16(sp)   
    sd s2, 24(sp)
    
    li s1, 0    #primo indice = 0
    addi s2, a1, -1 #ultimo elemento = size -1
LOOP_INVERT:
    blt s2, s1, END_INVERT #se s2<s1 exit
    ld a0, 8(sp)    #preparo in a0 l' indirizzo dell' array
    mv a1, s1       # metto in a1 il primo indice
    mv a2, s2       #metto in a2 il secondo indice
    #dopo aver preparato i parametri posso chimare la funzione
    jal ra, swap
    addi s1, s1, 1  #incremento l' indice 1
    addi s2, s2, -1 #decremento l' indice 2
    j LOOP_INVERT
    
END_INVERT:
#ripristino il frame pointer
    ld ra, 0(sp)
    ld s1, 16(sp)  
    ld s2, 24(sp)
    addi sp,sp, 32
    ret
    