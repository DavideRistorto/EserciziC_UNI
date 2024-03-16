.globl _start

.text

_start:
    #dati due numeri pari, farne la media 

    addi x5, x0, 8
    addi x6, x0, 2
    add x7, x5, x6
    srai x7, x7 ,1  #divisione 2

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
