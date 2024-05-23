# Sum an array in memory
.globl _start

.data
     size:   .word 16
     array:  .word 2, 1, 7, 1, 2, 2, 2, 1, 12, 1, 7, 1, 2, 2, 2, 1

.text
_start:
    la    s1, size

    # print new line
    addi  a0, zero, 0x0A
    li    a7, 11
    ecall

    # recursive sum
    la    a0, array
    lw    a1, 0(s1)
    jal   ra, sumarray

    # print the sum already in a0
    li    a7, 1
    ecall

exit:
    li    a7, 10 #call number 10 = exit
    ecall

sumarray:
    # caso base: array vuoto e ritorno 0
    bgt  a1, zero, sumarray_rec
    li   a0, 0
    ret

    # inizio la ricorsione
sumarray_rec:    
    addi  sp, sp, -16
    sd    s1, 8(sp)	#salvo s1 = 
    sd    ra, 0(sp)	#salvo ra

    # preserve the value of the first element
    lw    s1, 0(a0)		#carico l' elemento dell' array in s1 
    addi  a1, a1, -1	#decremento size
    addi  a0, a0, 4		#passo all' inidirizzo successivo
    
    jal   ra, sumarray	#richiamo la ricorsione
    add   a0, a0, s1	#salvo la somma

    ld    s1, 8(sp)
    ld    ra, 0(sp)                 	 # ripristino ra
    addi  sp, sp, 16                # rispristino stack pointer
    ret
