.globl _start
.data
    numstr: .string  "1234"
.text
_start:
    # call isnumber
    la   a0, numstr
    jal  ra, isnumber

    #exit
    li   a7, 10
    ecall

#*******************************************************************************
# digit
# a0 - char
# return 1 if char is a digit, 0 otherwise
#*******************************************************************************
digit:
    li t0, 48
    li t1, 57
    blt a0, t0, return_0
    bgt a0, t1, return_0
    li a0, 1
    ret
return_0:
    li a0, 0
    ret

#****************************************************
# completare la funzione isnumber nel campo di sotto
isnumber:
    addi sp,sp, -24
    sd ra, 0(sp)
    sd s1, 8(sp)
    sd s2, 16(sp)
    mv s1, a0
    li s2, 1    #result = 1 di default
    
loop:
    lbu a0, 0(s1)   #carico carattere
    beq a0, zero, end_loop  #se char[i] = '\0' exit
    jal ra, digit
    bne a0, zero, continue
    #return = 0 -> exit
    li s2, 0
    j end_loop
    continue:
    addi s1, s1, 1
    j loop

end_loop:
    mv a0, s2   #carico il risultato in a0
    ld ra, 0(sp)
    ld s1, 8(sp)
    ld s2, 16(sp)
    addi sp, sp, 24
    ret