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