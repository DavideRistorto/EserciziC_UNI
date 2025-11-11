{-
La lista infinita dei numeri primi
==================================

Questa lezione mostra come la property di "laziness" di Haskell permetta
la scrittura di programmi modulari dove sono combinate fasi di produzione 
e selezione di informazione, prendendo come caso di studio il calcolo dei primi
n numeri primi.

Soluzione iterativa/ricorsiva:
----------------------------
Il problema consiste nel calcolare i primi n numeri primi. Esistono infinite soluzioni, 
qui si mostra una versione iterativa in Java e una ricorsiva in Haskell. 
Entrambe combinano *produzione* della lista dei numeri naturali >=2 
e *selezione* dei soli primi e dei primi n.

-- Versione ricorsiva Haskell:
primi :: Int -> [Integer]
primi = aux 2 
  where
    aux _ 0 = []
    aux k n | primo k    = k : aux (k+1) (n-1)
            | otherwise  =     aux (k+1) n

-- Esempio d’uso:
primi 100

Soluzione in stile dataflow (lazy):
------------------------------------
Si può separare produzione e selezione grazie alla valutazione lazy di Haskell,
definendo una lista infinita dei naturali >=2, selezionando i primi tramite filter,
e troncando a n elementi con take.

-- enumFrom costruisce una lista (potenzialmente infinita):
enumFrom :: Enum a => a -> [a]
enumFrom n = n : enumFrom (succ n)

-- Esempi sull’uso di enumFrom (lista infinita, serve il lazy):
head (enumFrom 2)                  -- Primo elemento: 2
head (tail (enumFrom 2))           -- Secondo elemento: 3
enumFrom 2 !! 5                    -- Sesto elemento: 7
take 10 (enumFrom 2)               -- I primi 10 numeri: [2..11]

-- Esempio: evaluation infinita!
enumFrom 2                         -- (attenzione: non stampa mai!)

-- Versione lazy e modulare di primi:
primi :: Int -> [Integer]
primi n = take n (filter primo (enumFrom 2))

La funzione primi in questo modo separa nettamente:
- produzione: enumFrom 2 :: [Integer]
- selezione 1: filter primo ...
- selezione 2: take n ...

-}


-- Esercizi di riepilogo capitolo

-- Funzione che verifica se un numero è primo
primo :: Integer -> Bool
primo n = n > 1 && null [ x | x <- [2..isqrt n], n `mod` x == 0 ]

-- Calcola la radice quadrata intera di n
isqrt :: Integer -> Integer
isqrt = floor . sqrt . fromIntegral

primoMaggioreDi :: Integer -> Integer
primoMaggioreDi n =  head (filter(>n) (filter primo (enumFrom 2)))

-- 2) Definire una funzione primiGemelli :: Int -> [(Integer, Integer)] che restituisce le prime n coppie di primi gemelli (due numeri primi che differiscono di 2).
primiGemelli :: Int -> [(Integer, Integer)]
primiGemelli n = take n (filter gemelli (zip ps (tail ps)))
  where
    ps = filter primo (enumFrom 2)
    gemelli (p, q) = q == p + 2


-- 3) Che caratteristica ha la lista xs definita come segue?
xs :: [Integer]
xs = 0 : 1 : zipWith (+) xs (tail xs)
-- (Suggerimento: consultare la documentazione di zipWith e usare take per esaminare xs)
