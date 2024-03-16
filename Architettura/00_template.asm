.globl _start

.text

_start:

    

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
