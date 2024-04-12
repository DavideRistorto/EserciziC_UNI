#carico i dati
la t1, x
lw t2, 0(t1) #x
lw t3, 4(t1) #y
lw t4, 8(t1) #z

bge t2, t3, NULLA  # x>=y
mv t2, t3
NULLA:

bge t2, t4, NULLA2 #x>=z
mv t2, t4
NULLA2:
#carico il risultato
sw t2, 12(t1) 