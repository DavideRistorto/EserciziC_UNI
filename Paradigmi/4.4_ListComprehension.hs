{- 
List comprehension
==================================

Le list comprehension in Haskell sono una notazione compatta e intuitiva per generare nuove liste a partire da altre liste.
Si basano su due principali costrutti: generatori e guardie.

Sintassi:
[ espressione | generatore1, generatore2, ..., guardia1, guardia2, ... ]

[ x^2 | x <- [1..10], even x ]  Genera i quadrati dei numeri pari da 1 a 10.

-- Generatori:
-- Un generatore consente di produrre una lista iterando su un'altra lista.
-- Ad esempio, per ottenere la lista dei quadrati da 1 a 10:

-- Esempio:
[ x ^ 2 | x <- [1..10] ]
-- Equivalente a: map (^2) [1..10]

-- Con più generatori, vengono valutate tutte le combinazioni possibili:

-- Esempio:
[ (x, y) | x <- [1..10], y <- [1..10] ]
-- Produce tutte le coppie di numeri da 1 a 10.
length [ (x, y) | x <- [1..10], y <- [1..10] ] -- Restituisce 100

-- Un generatore può dipendere da precedenti:

-- Esempio:
[ (x, y) | y <- [1..10], x <- [1..y] ]
-- Tutte le coppie (x, y) dove x <= y.

-- Guardie:
-- Le guardie filtrano gli elementi, permettendo di selezionare solo quelli che soddisfano certe condizioni.

-- Esempio:
[ (x, y) | x <- [1..10], y <- [1..10], x <= y ]
-- Seleziona solo le coppie con x <= y come nell'esempio sopra.

-}

-- Esercizi di riepilogo capitolo

-- 1) Ridefinire 'map' e 'filter' usando solo list comprehension
-- Esempio soluzione:
map :: (a -> b) -> [a] -> [b]
map f xs = [f x | x <- xs] -- Per ogni elemento di xs ovvero x lo applico alla funzione f

filter :: (a -> Bool) -> [a] -> [a]
filter f xs = [x | x <-xs, f x] -- Per ogni elemento di xs ovvero x, che soddista la funzione f, lo aggiungo alla lista

-- 2) Definire la funzione 'primo :: Integral a => a -> Bool' nel modo più compatto possibile con una list comprehension
-- Esempio soluzione:
primo :: Integral a => a -> Bool
primo n = [ d | d <- [2..n], n `mod` d == 0 ] == [n]


