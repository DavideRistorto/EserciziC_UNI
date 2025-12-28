{-
Liste
==================================

Una lista è una sequenza omogenea di elementi, cioè tutti dello stesso tipo.

Creazione diretta di liste
----------------------------------
Le liste si creano racchiudendo gli elementi tra parentesi quadre, separati da virgole:

[]            -- lista vuota
[1]           -- lista con un solo elemento
[1,2,3]       -- lista di numeri interi
[0.5,3]       -- lista di numeri floating-point
[True, False] -- lista di valori booleani
[[], [1,2], [3]] -- lista di liste di numeri

Si possono creare intervalli di numeri:

[1..10]  -- numeri interi da 1 a 10
[1..]    -- lista infinita di numeri interi da 1 in poi

Costruttori canonici
----------------------------------
Ogni lista può essere costruita con due costruttori: `:` (cons) e `[]`.

X : L

crea una nuova lista avendo `X` come testa e `L` come coda.

Esempi:

1 : 2 : 3 : []      -- equivale a [1,2,3]
[1,2,3] == 1 : 2 : 3 : []  -- True
1 : (2 : (3 : []))  -- associativo a destra

Operatori e funzioni su liste
----------------------------------
Le principali funzioni predefinite sono:

length :: [a] -> Int         -- lunghezza di una lista
sum :: Num a => [a] -> a     -- somma degli elementi
data List a = ...
product :: Num a => [a] -> a -- prodotto degli elementi
(++) :: [a] -> [a] -> [a]    -- concatenazione di due liste

Esempi d’uso:

length [1,2,3]        -- 3
sum [1,2,3]           -- 6
product [4,5,6]       -- 120
sum []                -- 0 (elemento neutro della somma)
product []            -- 1 (elemento neutro del prodotto)
[1,2,3] ++ [4,5,6]    -- [1,2,3,4,5,6]

L’operazione ++ è associativa ma non commutativa:

[1] ++ ([2] ++ [3]) == ([1] ++ [2]) ++ [3]  -- True
[1,2] ++ [3] /= [3] ++ [1,2]                -- True
[1,2] ++ [] == [1,2]                        -- True
[] ++ [1,2] == [1,2]                        -- True

In sintesi:
----------------------------------
[]        :: [a]
(:)       :: a -> [a] -> [a]
length    :: [a] -> Int
sum       :: Num a => [a] -> a
product   :: Num a => [a] -> a
(++)      :: [a] -> [a] -> [a]

-}

-- Esercizi di riepilogo capitolo

-- 1) Scrivere la lista con i primi 10 numeri primi.
l :: [Integer]
l = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

-- 2) Verificare quali delle seguenti espressioni sono ben tipate:
-- [1, 2 + 3] TRUE
-- [True, 2 == 3] TRUE
-- [1, True] FALSE
-- [[1], []] TRUE
-- [[1], False] FALSE
-- 1 : 2  FALSE
-- [[], [[2.5, 3], 4 : 5 : []]] TRUE

-- 3) Definire una funzione non ricorsiva media :: [Int] -> Float per calcolare la media aritmetica degli elementi di una lista.
media :: [Int] -> Float
media x = fromIntegral (sum x) / fromIntegral (length x) --fromIntegral per cast esplicito a float

-- 4) Definire una funzione non ricorsiva per calcolare il fattoriale di un numero naturale.
fattoriale :: Int -> Int
fattoriale x = product [2..x] -- creo lista da 2 fino a n e calcolo il prodotto tra gli elementi

-- 5) Definire una funzione ricorsiva intervallo :: Int -> Int -> [Int]
-- che crei la lista dei numeri compresi tra m e n (estremi inclusi), restituendo la lista vuota se m > n.
intervallo :: Int -> Int -> [Int]
intervallo m n | m > n = []
               | otherwise = [m..n]

-- Scrivi una funzione che costruisce una lista dai primi n numeri naturali usando solo (:) e []
costruisciN :: Int -> [Int]
costruisciN 0 = [0]
costruisciN n = n : costruisciN (n-1)

-- Scrivi una funzione che restituisce il secondo elemento di una lista (se esiste)
secondo :: [a] -> Maybe a
secondo [] = Nothing
secondo [_] = Nothing
secondo (x:y:xs) = Just y

-- Scrivi una funzione che prende una lista di liste e restituisce solo quelle di lunghezza > n
filtraLunghezza :: Int -> [[a]] -> [[a]]
filtraLunghezza n (x:xs) = if length x > n then x : filtraLunghezza n xs else filtraLunghezza n xs

-- Calcola la somma solo degli elementi maggiori di n
sommaMaggioreN :: Int -> [Int] -> Int
sommaMaggioreN n [] = 0
sommaMaggioreN n (x:xs) = if x > n then x + sommaMaggioreN n xs else sommaMaggioreN n xs

-- Calcola il prodotto dei primi n elementi di una lista
prodottoParziale :: Int -> [Int] -> Int
prodottoParziale n (x:xs) | n == 0 = 1
                          | otherwise = x * prodottoParziale (n-1) xs


-- Data una lista di numeri, crea una nuova lista dove ogni elemento 
-- è sostituito dalla somma di tutti gli elementi precedenti (incluso se stesso)
sommeProgressive :: [Int] -> [Int]
sommeProgressive [] = []
sommeProgressive [x] = [x]
sommeProgressive (x:y:xs) = x + y : sommeProgressive xs
