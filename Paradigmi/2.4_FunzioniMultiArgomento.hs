{-
Funzioni a più argomenti e applicazione parziale
================================================

In Haskell, ogni funzione accetta esattamente un argomento.
Funzioni che sembrano accettare più argomenti sono espresse tramite la rappresentazione detta "currying": ogni funzione a n argomenti è vista come una catena 
di n funzioni a un solo argomento. 
Così, funzioni come `addizione` hanno tipo `Int -> Int -> Int`: applicata a un intero restituisce una funzione, che applicata a un altro intero produce il risultato. 
L’associatività della freccia nei tipi è a destra: 

    Int -> Int -> Int  ≡  Int -> (Int -> Int)

mentre l’applicazione delle funzioni è associativa a sinistra:

    addizione 2 3  ≡  (addizione 2) 3

Questa struttura consente l’applicazione parziale: è possibile applicare una funzione a meno argomenti di quelli previsti, ottenendo una nuova funzione più specifica. 
Questo meccanismo favorisce il riuso e la specializzazione del codice.

Esempi notevoli:

-- Funzione a due argomenti in forma base
addizione :: Int -> Int -> Int
addizione x y = x + y

-- Primo passaggio a lambda
addizione :: Int -> Int -> Int
addizione x = \y -> x + y

-- Secondo passaggio a lambda (forma curryficata)
addizione :: Int -> Int -> Int
addizione = \x -> \y -> x + y

-- Applicazione parziale
mistero :: Int -> Int
mistero = addizione 1

-- mistero 0 == 1
-- mistero 2 == 3

La funzione `mistero` si comporta come il successore: `addizione 1` produce una funzione che somma 1 al suo argomento, ottenuta grazie all’applicazione parziale.

-}

-- Esercizi di riepilogo capitolo

addizione :: Int -> Int -> Int
addizione x y = x + y

-- 1) Definire le funzioni massimo :: Int -> Int -> Int e minimo :: Int -> Int -> Int che calcolino il massimo e il minimo dei loro argomenti.
massimo :: Int -> Int -> Int
massimo x y = if x > y then x else y -- oppure max x y più facilmente

minimo :: Int -> Int -> Int
minimo x y = min x y

-- 2) Definire una funzione potenza :: Int -> Int -> Int che calcoli m^n per n ≥ 0 senza usare ^ o **.
potenza :: Int -> Int -> Int
potenza m n | n == 0 = 1
            | otherwise = m * potenza m (n-1)