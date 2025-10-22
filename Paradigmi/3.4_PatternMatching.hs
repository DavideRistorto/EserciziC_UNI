{-
Pattern Matching
==================================

In Haskell, il pattern matching permette di definire funzioni attraverso più equazioni, ciascuna associata alla forma degli argomenti.
Ogni equazione viene valutata in ordine: la prima in cui gli argomenti corrispondono al pattern viene utilizzata per calcolare il risultato.

### Pattern matching strutturale

Possiamo usare i costruttori delle liste (`[]` e `:`) per distinguere i casi principali. Ad esempio:

somma :: [Int] -> Int
somma [] = 0
somma (x : xs) = x + somma xs

La funzione `somma` restituisce 0 se la lista è vuota, altrimenti somma la testa `x` al risultato ricorsivo della coda `xs`.

### Pattern matching profondo

Il pattern matching può approfondirsi nella struttura delle liste. Ad esempio, per verificare se una lista è ordinata:

ordinata :: [Int] -> Bool
ordinata [] = True
ordinata [_] = True
ordinata (x : y : xs) = x <= y && ordinata (y : xs)

Qui `x : y : xs` rappresenta una lista con almeno due elementi, e si utilizza la ricorsione per controllare coppie consecutive.

### Pattern matching su più argomenti

È possibile eseguire il pattern matching contemporaneamente su più argomenti. Ad esempio, per verificare se due liste hanno la stessa lunghezza:

-- Versione semplice (usa length)
stessaLunghezza :: [Int] -> [Int] -> Bool
stessaLunghezza xs ys = length xs == length ys

-- Versione efficiente con pattern matching
stessaLunghezza :: [Int] -> [Int] -> Bool
stessaLunghezza [] [] = True
stessaLunghezza [] _  = False
stessaLunghezza _  [] = False
stessaLunghezza (_ : xs) (_ : ys) = stessaLunghezza xs ys

La seconda versione confronta le liste elemento per elemento, evitando di calcolare la lunghezza completa.

-}

-- Esercizi di riepilogo capitolo
-- (x : xs) significa elemento x concatenato alla lista xs -> danno una lista come richiesto. Serve per spezzare il primo elemento della lista 
somma :: [Int] -> Int
somma [] = 0
somma (x : xs) = x + somma xs

ordinata :: [Int] -> Bool
ordinata [] = True
ordinata [_] = True -- il carattere '_' è il jolly, significa che c'è un elemento
ordinata (x : y : list) = x <= y && ordinata (y : list)


-- 1) Riscrivere la lista [1, 2, 3] in tutti i modi possibili come concatenazione di due liste (usando ++).
--[] ++ [1, 2, 3]
--[1] ++ [2, 3]
--[1, 2] ++ [3]
--[1, 2, 3] ++ []

-- 4) Definire una funzione ricorsiva:
--    prodotto :: [Int] -> Int che calcoli il prodotto di tutti gli elementi nella lista (senza usare la funzione `product`).
prodotto :: [Int] -> Int
prodotto [] = 1
prodotto (x : xs) = x * prodotto xs

-- 5) Definire:
--    inverti :: [Int] -> [Int] che restituisca la lista inversa degli elementi della lista di ingresso (suggerimento: usare ++).
inverti :: [Int] -> [Int]
inverti [] = []
inverti [x] = [x]
inverti (x : xs) = inverti xs ++ [x]


-- 6) Definire:
--    sommaCongiunta :: [Int] -> [Int] -> [Int]
--    che calcoli la lista delle somme degli elementi corrispondenti di due liste,
--    con lunghezza pari alla minore tra quelle di xs e ys.
sommaCongiunta :: [Int] -> [Int] -> [Int]
sommaCongiunta [] _ = [] -- casi base ricorsivi
sommaCongiunta _ [] = []
sommaCongiunta (x : xs) (y : ys) = (x+y) : sommaCongiunta xs ys -- caso ricorsivo