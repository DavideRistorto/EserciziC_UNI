#Sia X una variabile aleatoria distribuita come una Normale di media 0 e varianza 4:
#Determinare:

#La probabilità che X sia minore di 1.5
pnorm(1.5, mean = 0, sd = 2)

#La probabilità che X sia maggiore di 3
pnorm(3, mean = 0, sd = 2, lower.tail = FALSE)

#La probabilità che X sia maggiore di 3 sapendo che X è minore di 6
(pnorm(6,0,2) - pnorm(3,0,2)) / pnorm(6,0,2) # formula della Probabilità Condizionata



# Sia X una variabile aleatoria distribuita come una Normale di media 2 e varianza 4.
# Sia Y una variabile aleatoria distribuita come una Normale standard, indipendente da X
#Determinare:

#La probabilità che X sia maggiore di 3
pnorm(3, mean = 2, sd = 2, lower.tail = FALSE)

#La probabilità che entrambe le variabili aleatorie siano maggiori di 3
pnorm(3, mean = 2, sd = 2, lower.tail = FALSE) * pnorm(3, mean = 0, sd = 1, lower.tail = FALSE)

#La probabilità che X sia minore di 7 sapendo che X è maggiore di 6
(pnorm(7, 2, 2)- pnorm(6, 2, 2)) / pnorm(6, 2, 2, lower.tail = FALSE)



#Sia X una variabile aleatoria distribuita come una Normale di media 0 e varianza 4
#Determinare

#La probabilità che X sia minore di 1.5
pnorm(1.5, 0, 2)

#La probabilità che X sia maggiore di 3
pnorm(3, 0, 2, lower.tail = FALSE)

#La probabilità che X sia compresa fra -2 e 1: --> -2 < X < 1
pnorm(1, 0, 2) - pnorm(-2, 0, 2)


#La probabilità che X sia maggiore di 3 sapendo che X è minore di 6: 3 < X < 6
(pnorm(6, 0, 2) - pnorm(3, 0, 2)) / pnorm(6, 0, 2)



#Sia X una variabile aleatoria distribuita come una Normale di media 10 e varianza 16
#Determinare:

#La probabilità che X sia maggiore di 13
pnorm(13, 10, 4, lower.tail = FALSE)

#La probabilità che X sia compresa fra 8.5 e 12
pnorm(12, 10, 4) - pnorm(8.5, 10, 4)

#La probabilità che X sia minore di 7 sapendo che X è maggiore di 6
(pnorm(7, 10, 4) - pnorm(6, 10, 4)) / pnorm(6, 10, 4, lower.tail = FALSE)

# La probabilità che X sia minore di 8.5 oppure maggiore di 12 sapendo che X è maggiore di 8
# Questo si traduce come x < 8.5 | x > 12 sapendo che x > 8  ---> (P1 + P2) / P3
(pnorm(8.5, 10, 4) - pnorm(8, 10, 4) + pnorm(12, 10, 4, lower.tail = FALSE)) / pnorm(8, 10, 4, lower.tail = FALSE)



# Sia X una variabile aleatoria distribuita come una Normale di media 2 e varianza 4
# Sia Y una variabile aleatoria distribuita come una Normale standard, indipendente da X
# Determinare:

# La probabilità che X sia maggiore di 3
pnorm(3, 2, 2, lower.tail = FALSE)

# La probabilità che entrambe le variabili aleatorie siano maggiori di 3
pnorm(3, 2, 2, lower.tail = FALSE) * pnorm(3, 0, 1, lower.tail = FALSE)

# La probabilità che X sia compresa fra 1.5 e 2 sapendo che Y è maggiore di 7
# X e Y sono indipendenti quindi Y > 7 non mi serve
pnorm(2, 2, 2) - pnorm(1.5, 2, 2)

# La probabilità che X sia minore di 7 sapendo che X è maggiore di 6
(pnorm(7, 2, 2) - pnorm(6, 2, 2)) / pnorm(6, 2, 2, lower.tail = FALSE)



#Sia X una variabile aleatoria distribuita come una Normale di parametri μ=3 e σ2=1
# Sia Y una variabile aleatoria distribuita come una Normale standard, indipendente da X
#Determinare:

#La probabilità che entrambe le variabili aleatorie siano maggiori della propria media
pnorm(3, 3, 1, lower.tail = FALSE) * pnorm(0, 0, 1, lower.tail = FALSE)

#La probabilità che X sia compresa fra -1 e 0 sapendo che Y è maggiore di 7
pnorm(0, 3, 1) - pnorm(-1, 3, 1)

#La probabilità che X sia minore di 2.5 oppure che Y sia maggiore di -1, sapendo che Y è maggiore di -2
# X < 2.5 | Y > -1 Sapendo che Y > -2
(px <- pnorm(2.5, 3, 1)) + (pnorm(-1, 0, 1, lower.tail = FALSE) - pnorm(-1, 0, 1, lower.tail = FALSE) * pnorm(2.5, 3, 1)) / pnorm(-2, 0, 1, lower.tail = FALSE)

#La probabilità che X sia minore di 7 sapendo che (X+1) è maggiore di 6
(pnorm(7,3,1) - pnorm(5,3,1)) /  pnorm(5,3,1, lower.tail = FALSE)







  

