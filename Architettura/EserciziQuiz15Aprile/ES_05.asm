mcm: 
    addi sp, sp, -16
    sd s1, 8(sp)
    sd ra, 0(sp)
    
    mul s1, a0, a1
    jal mcd
    div a0, s1, a0
    ld s1, 8(sp)
    ld ra, 0(sp)
    addi sp, sp, 16
    ret
    
    ret
