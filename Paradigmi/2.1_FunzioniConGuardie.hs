{-
Funzioni con guardie
==================================

In Haskell, spesso è necessario calcolare il valore di una funzione in modo diverso a seconda di qualche proprietà dell’argomento. 
Un esempio tipico è la funzione che calcola il valore assoluto di un numero \(n\): se \(n \geq 0\), restituisce \(n\); altrimenti, restituisce \(-n\). 
Questo comportamento si può esprimere con equazioni multiple e condizioni chiamate *guardie*.

Definizione con guardie:

assoluto :: Int -> Int
assoluto n
  | n >= 0    = n
  | n < 0     = negate n

Quando si applica una funzione con guardie, Haskell esamina le condizioni dall’alto verso il basso e usa la prima guardia che vale `True`.

Esempi di utilizzo:
assoluto 3         -- 3
assoluto (negate 3) -- 3

La guardia finale può essere `otherwise`, che vale sempre `True`. Questo corrisponde al ramo `else` di un’istruzione condizionale e rende la definizione più concisa:

assoluto :: Int -> Int
assoluto n
  | n >= 0    = n
  | otherwise = negate n

La funzione `otherwise` è sempre vera e può essere usata come ultima guardia esaustiva.
-}

-- Esercizi di riepilogo capitolo

assoluto :: Int -> Int
assoluto n | n >= 0 = n
           | n < 0  = negate n  -- oppure | otherwise = negate n 

-- 1) Definire una funzione Int -> Int che, data n, calcola il successore se n è pari e il valore assoluto se n è dispari. (Due versioni: prima con if, poi con guardie)
funzione_v1 :: Int -> Int
funzione_v1 n | even n = n + 1
              | otherwise = abs n

funzione_v2 :: Int -> Int
funzione_v2 n = if even n then n + 1 else abs n

-- 2) Definire giorni :: Int -> Int, che calcola il numero di giorni di un anno a seconda che sia bisestile o no (usando la funzione bisestile vista precedentemente).
bisestile :: Int -> Bool
bisestile n = n `mod` 4 == 0 && n `mod` 100 /= 0

giorni :: Int -> Int
giorni anno = if bisestile anno then 366 else 365