#ESERCIZI PROBABILITA'


# Procedi con il seguente esperimento: lanci una moneta truccata che restituisce testa con probabilità 0.3. 
# Se ottieni testa estrai con reimbussolamento 8 palline da un’urna che ne contiene 11, delle quali 4 sono bianche e 7 sono verdi. 
# Se ottieni croce estrai, con reimbussolamento dalla stessa urna, 6 palline

#Con quale probabilità ottieni 3 palline verdi
0.3 * dbinom(3, 8, 7/11) + 0.7 * dbinom(3, 6, 7/11)

#Con quale probabilità ottieni 7 palline verdi
0.3 * dbinom(7, 8, 7/11) + 0.7 * dbinom(7, 6, 7/11)

#Con quale probabilità ottieni meno di < 3 palline verdi
0.3 * (dbinom(0, 8, 7/11) + dbinom(1, 8, 7/11) + dbinom(2, 8, 7/11)) + 0.7 * (dbinom(0, 6, 7/11) + dbinom(1, 6, 7/11) + dbinom(2, 6, 7/11))

#Con quale probabilità avevi ottenuto testa se hai estratto meno di < 3 palline verdi
( ( dbinom(1,8,7/11) + dbinom(2,8,7/11) + dbinom(0,8,7/11) )*0.3 ) / ( ( dbinom(1,8,7/11) + dbinom(2,8,7/11) + dbinom(0,8,7/11) )*0.3 +  ( dbinom(1,6,7/11) + dbinom(2,6,7/11) + dbinom(0,6,7/11) )*0.7 )


#Un'urna contiene 5 palline bianche, 6 nere e 4 rosse. Si estraggono 2 palline

#Si calcoli la probabilità che le due palline estratte siano dello stesso colore con estrazione in blocco
( factorial(4)/(factorial(2)*factorial(2)) + factorial(5)/(factorial(2)*factorial(3)) + factorial(6)/(factorial(2)*factorial(4)) ) / (factorial(15) /(factorial(2) * factorial(13)))

#Si calcoli la probabilità che le due palline estratte siano dello stesso colore con reintroduzione
(4^2 + 5^2 + 6^2)/(15^2)


#L’urna A contiene 10 palline bianche e 10 nere. L’urna B contiene 5 palline bianche e 15 nere. Viene lanciata una moneta non truccata: se esce testa allora vengono fatte 
# 3 estrazioni senza reinserimento dall’urna A; se esce croce vengono fatte 5 estrazioni con reinserimento dall’urna B

#Calcolare la probabilità di estrarre esattamente 2 palline bianche sapendo di aver ottenuto testa
(choose(10, 2) * choose(10, 1)) / choose(20, 3)

#Calcolare la probabilità di estrarre esattamente 2 palline bianche sapendo di aver ottenuto croce
dbinom(2,5,5/20)


#Si hanno a disposizione 3 monete. La moneta A ha probabilità di ottenere testa pari a p
#La moneta B ha probabilità di ottenere testa pari a p/2
#La moneta C ha probabilità di ottenere testa pari a p/3
#Primo lancio: Si lancia la moneta A.
#Secondo lancio: Se al lancio precedente si è ottenuto testa allora si lancia la moneta A. Se si è avuto croce si lancia la moneta B.
#Terzo lancio: Se nel lancio precedente si è ottenuto testa allora si lancia la moneta A. Se nel primo lancio si è ottenuto testa e nel secondo lancio si è ottenuto croce, allora si lancia la moneta B. Se nel primo e nel secondo lancio si è ottenuto croce allora si lancia la moneta C



#Se p=1/4, determinare la probabilità della sequenza (Testa,Testa,Testa) 
1/4 ^ 3

# Se p=1/2 determinare la probabilità della sequenza (Croce, Croce, Croce)
1/2 * 3/4 * 5/6

#Se p=1/4, determinare la probabilità che si abbia Testa al secondo e al terzo lancio
1/4 ^ 3 + 3/4 * 1/8 * 1/4
























