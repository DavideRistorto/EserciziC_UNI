{-
Funzioni ricorsive in Haskell
==================================

In Haskell, le operazioni ripetute si esprimono attraverso **funzioni ricorsive**: funzioni che si richiamano durante la loro valutazione.
 I principali concetti:

- Non si usano comandi iterativi o di assegnamento.
- La ricorsione permette di risolvere problemi dividendoli in casi base e casi generali.

Esempio: la funzione del **fattoriale** si può scrivere con le guardie oppure con più equazioni (usando pattern).

-- Definizione con guardia
fattoriale :: Int -> Int
fattoriale n
  | n == 0    = 1
  | otherwise = n * fattoriale (n-1)

-- Definizione con pattern matching
fattoriale :: Int -> Int
fattoriale 0 = 1
fattoriale n = n * fattoriale (n-1)

La scelta tra pattern e guardie consente maggiore chiarezza e modularità. L'ordine delle equazioni è critico:
il caso base deve essere elencato per primo, altrimenti non viene mai raggiunto e la funzione non termina.

**Esempio di funzione ricorsiva con più casi base: la sequenza di Fibonacci**

fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)

-- Esempi di chiamata
fibonacci 0    -- restituisce 0
fibonacci 2    -- restituisce 1
fibonacci 10   -- restituisce 55

-}

-- Esercizi di riepilogo capitolo
-- Ricorsione
fattoriale_v1 :: Int -> Int
fattoriale_v1 n | n == 0 = 1
                | otherwise = n * fattoriale_v1 (n-1)

-- Ricorsione con patter matching
fattoriale_v2 :: Int -> Int
fattoriale_v2 0 = 1
fattoriale_v2 n = n * fattoriale_v2 (n-1)

--1) Definire ricorsivamente la funzione che calcola la somma dei primi n numeri naturali.
sommaRicorsiva :: Int -> Int
sommaRicorsiva n | n == 0 = 0
                 | otherwise = n + sommaRicorsiva (n-1)

--2) Definire una funzione pow2 :: Int -> Int che calcola 2^n (n>=0), senza usare gli operatori ^ e **.
pow2 :: Int -> Int
pow2 n | n == 0 = 1
       | otherwise = 2 * pow2(n-1)

--3) Definire una funzione potenzaDi2 :: Int -> Bool che restituisce True se n è una potenza di 2, False altrimenti (n>=0).
potenzaDi2 :: Int -> Bool
potenzaDi2 n | n == 0 = False
             | n == 1 = True
             | otherwise = even n && potenzaDi2 (n `div` 2)