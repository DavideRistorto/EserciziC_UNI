li t2, 1 #change
while: 
    beq t2, zero, endwhile #uscita while  
    li t2, 0    #change = 0
    la t0, size
    lw t0, 0(t0) #size
    addi t0, t0, -1 #decremento perche il ciclo si fa size-1 volte
    la t1,array 
    for:
        ble t0, zero, endfor
        ld t3, 0(t1) #carico primo elemento
        ld t4, 8(t1) #carico elem successivo
        ble t3, t4, nulla
        mv t5, t3 #temp     add t5, zero , t3
        sd t4, 0(t1)   #array[i] = array[i+1] prima contenuto da salvare poi dove va salvato
        sd t5, 8(t1)   #array[i+1] = temp;
        li t2, 1   #change = 1
        nulla:
        addi t0, t0, -1   #decremento size
        addi t1, t1, 8    #passo all elemento successivo dell array
        j for
    endfor:
        j while
        
       
endwhile: