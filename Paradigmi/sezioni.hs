--In Haskell, si dice sezione un’espressione racchiusa tra parentesi in cui un operatore binario viene applicato a uno solo dei suoi due argomenti.
--A titolo di esempio, le espressioni

-- La prima parte è la sezione, il numero dopo è l'argomento passato all'operatore binario.
--(1 +) 2
--(1 +) 3
--(`mod` 2) 2
--(`mod` 2) 3


--ES 1:
--Scrivere due funzioni anonime che stabiliscano se un numero è pari o dispari. 
\x -> x `mod` 2 == 0 
\x -> x `mod` 2 != 0 

-- ES 2:
--Scrivere la funzione anonima “valore assoluto”
\x -> if x >= 0 then x else negate x

{-
    f.g: (f.g)(x) = f(g(x))
    ovvero il risultato prodotto da g(x) e l' input di f.
    f e g devono avere lo stesso dominio
-}
