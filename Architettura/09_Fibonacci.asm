.globl _start

.text

    #// N = 8
    #int R = 1;
    #int A = 0; int B = 1;
    #while (N > 0) {
    #    R = A + B;
    #    A = B;
    #    B = R;
    #    N = N - 1;
    #}


_start:
#i registri t sono quelli temporanei
    addi t0, zero, 8 #N
    addi t1, zero, 1 #R
    addi t2, zero, zero #A
    addi t3, zero, 1 #B
    INIZIO_CICLO:
    ble t0, zero, FINE_CICLO
    	add t1, t2, t3
    	add t2, zero, t3  #abbreviato: mv t2, t3
    	add t3, zero, t1  #abbreviato: mv t3, t1
    	addi t0, zero, -1
    j INIZIO_CICLO
    FINE_CICLO:

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
