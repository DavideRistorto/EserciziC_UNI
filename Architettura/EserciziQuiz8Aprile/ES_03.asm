.globl _start
.data
    str: .string "Hello World!"

.text
_start:
    # call hash
    la  a0, str
    jal ra, hash

    #exit
    li   a7, 10
    ecall

#******************************************
# completare la funzione nel campo di sotto

hash:
li t0, 5381     #hash
li t1, 0        #i

while:
    add a2,zero, a0  # in a2 metto valore ash
    add a2, a2, t1               #str[i] 
    lb a3, 0(a2)
    
    beq a3, zero, endwhile  #se a3=0 esce
    add a4, zero, t0    #a4=temporaneo hash
    li a5, 32           #32
    mul t0, t0, a5      #shift a desrta
    add t0, t0, a4      #hash = ((hash << 5) + hash)
    add t0, t0,a3
    addi t1, t1, 1
    j while

endwhile:
add a0,zero, t0
ret