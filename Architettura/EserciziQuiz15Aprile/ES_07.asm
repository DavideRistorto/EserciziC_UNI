int passrules(char str[]) {
    int uppercase = contains(str, 'A', 'Z');
    int numbers   = contains(str, '0', '9');
    return (uppercase && numbers);
}

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
    #record di attivazione
    addi sp, sp, -32
    sd ra, 0(sp)
    sd a0, 8(sp)    #salvo a0 per evitare venga sovrascritto dopo le chiamate a funzione
    sd s1, 16(sp)   #uppercase 
    sd s2, 24(sp)   #numbers
    li a1, 65       #parametro: A
    li a2, 90       #prametro: Z
    jal ra, contains    #(str, A,Z)
    mv s1, a0       #salvo il valore return della funzione in s1
    ld a0, 8(sp)    #ripristino il puntatore all' array
    li a1, 48       #parametro: 0
    li a2, 57       #parametro: 9
    jal ra, contains    #(str, 0, 9)
    mv s2, a0
    # ora in s1 ho il valore della prima chiamata, mentre in s2 il valore della seconda chiamata
    li a0, 0    #setto il risultato a 0
    beq s1, zero, NULLA
    beq s2, zero, NULLA
    li a0, 1    #se entrambi i valori sono 1 allora il risultato della mia funzione diventa 1
    
NULLA:

#ripristino frame pointer
    ld ra, 0(sp)
    ld s1, 16(sp)
    ld s2, 24(sp)
    addi sp, sp, 32
    ret
    