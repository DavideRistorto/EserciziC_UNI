#Sia X una variabile aleatoria distribuita come una Normale di media 0.2e varianza 1.
#Sia Y una variabile aleatoria distribuita come una Esponenziale di parametro ('rate') pari a 1, indipendente da  X

#La probabilità che Y sia maggiore di 2
pexp(2, 1, lower.tail = FALSE)

#La probabilità che almeno una delle due variabili aleatorie sia maggiore di 2
1 - (pnorm(2, 0.2, 1) * pexp(2, 1))  # 1 - la probabilità che entrambe siano minore di 2

#La probabilità che al massimo una delle due sia maggiore di 1
1 - (pnorm(1,0.2,1, , lower.tail = FALSE) * (pexp(1,1, lower.tail = FALSE)))



#Siano X1,X2,X3 tre variabili aleatorie indipendenti e identicamente distribuite, 
#con distribuzione Normale di media 0.2 e varianza 1

# La probabilità che X2 sia maggiore di 2
pnorm(2, 0.2, 1, lower.tail = FALSE)

#La probabilità che almeno una delle tre variabili aleatorie sia maggiore di 1
1 - (pnorm(1, 0.2, 1) ^ 3)

#La probabilità che Y=2X − 0.4 sia maggiore di 1
pnorm(0.7, 0.2, 1, lower.tail = FALSE)


#Sia X una variabile aleatoria continua distribuita come una Uniforme sull'intervallo [2,10]

# La probabilità che X sia minore della sua media
punif(6, 2, 10) #La media è (10+2)/2 = 6

#La probabilità che X sia maggiore di 3
punif(3, 2, 10, lower.tail = FALSE)

#La probabilità che X sia compresa fra -2 e 3
punif(3, 2, 10) - punif(-2, 2, 10)

#La probabilità che X sia maggiore di 3 sapendo che X è minore di 6
(punif(6, 2, 10) - punif(3, 2, 10)) / punif(6, 2, 10)



