
##########################################
IMPLEMENTARE LA STRCPY COME DA CODICE:
void strcpy(char *dst, char *src) {
    unsigned long i;
    unsigned long n, m;

    n = strlen(src);    
    m = strlen(dst);

    for (i = 0; i < n; i++)
        dst[i] = src[i];
    for ( ; i < m; i++)
        dst[i] = '\0';
    return;
}
##########################################


strcpy:

# record di attivazione dato che è una funzione non foglia
    addi sp, sp, -32
    sd ra, 0(sp)	
    sd a0, 8(sp)	#serve per non sovrascrivere la prima stringa dalla funz. strlen
    sd a1, 16(sp)	
    sd s1, 24(sp)	#usiamo s1 perchè
##############################################
    jal ra, strlen 	# strlen src
    add s1, a0, zero 	# s1 = n
    ld a0, 16(sp) 	# strlen dst
    jal ra, strlen
    add t0, a0, zero 	# t0 = m -> assumendo m > n
    sub t1, t0, s1 	# t1 = m-n
    ld a0, 8(sp) 	# ricarico a0
    ld a1, 16(sp) 	# ricarico a1
STRCPY_L1:
    beq t0, zero, STRCPY_L4 # done if i == m
    ble t0, t1, STRCPY_L2 # if > m-n, copy char
    lb t2, 0(a0) # dereference str[i]
    sb t2, 0(a1) # str[i] -> dst[i]
    addi a0, a0, 1 # increment a0
    j STRCPY_L3
STRCPY_L2: # else put a \0
    sb zero, 0(a1)
STRCPY_L3:
    addi a1, a1, 1 # increment other regs
    addi t0, t0, -1
    j STRCPY_L1 # loop
STRCPY_L4:
# deallocazione e ripristino
    ld s1, 24(sp)
    ld ra, 0(sp)
    addi sp, sp, 32
 ret