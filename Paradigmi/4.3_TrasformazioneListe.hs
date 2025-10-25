import Distribution.Simple.Glob (fileGlobMatches)
{-
Trasformazioni di liste e Quick Sort
====================================

In questa lezione si analizzano alcune trasformazioni fondamentali delle liste nei linguaggi funzionali, con particolare attenzione al polimorfismo e alle funzioni di ordine 
superiore, promuovendone riuso e generalizzazione.

Map
---
Map applica una funzione a ogni elemento di una lista, producendo una nuova lista di risultati. Permette di evitare funzioni ricorsive specifiche:

-- Arrotonda e quadrati si ottengono specializzando map:
arrotonda :: (RealFrac a, Integral b) => [a] -> [b]
arrotonda = map round

quadrati :: Num a => [a] -> [a]
quadrati = map (^ 2)

Filter
------
Filter restituisce una lista con gli elementi che soddisfano un predicato (proprietà):

-- Minori e maggiori sono specializzazioni di filter:
minori :: Ord a => a -> [a] -> [a]
minori x = filter (< x)

maggiori :: Ord a => a -> [a] -> [a]
maggiori x = filter (>= x)

Fold
----
Fold combina tutti gli elementi di una lista tramite un operatore binario. sum e product sono esempi di fold:

-- Versione generica: foldr (right fold)
-- sum e product come specializzazioni di foldr:
sum :: Num a => [a] -> a
sum = foldr (+) 0

product :: Num a => [a] -> a
product = foldr (*) 1

Il parametro “r” in foldr indica “right”, differenziandola da foldl (“left”). La scelta influisce sul modo in cui si combinano i risultati.

-}

-- Esercizi di riepilogo capitolo

-- Esempio uso MAP
-- Data una lista di numeri, ritornare tutti gli elementi moltiplicati per 3
moltiplica3 :: Num a => [a] -> [a]
moltiplica3 = map (* 3)

-- Esempio uso FILTER
-- Data una lista di numeri, ritornare solo gli elementi multipli di 3
multipli3 :: Integral a => [a] -> [a]
multipli3 = filter (\x -> x `mod` 3 == 0) -- per ogni elemento x della lista, controlla se il resto della divisione per 3 è 0

-- Esempio uso FOLD
-- Data una lista di numeri, ritornare la somma di tutti gli elementi
sum :: Num a => [a] -> a
sum = foldr (+) 0  --foldr (+) 0 [1,2,3,4] Usa un operatore e per ogni valore della lista lo combina con l'elemento specificato (Di solito l' elemento neutro dell' operatore)


-- 2) Che funzioni sono le seguenti?
-- 2.1) length . filter (>= 0)          -- calcolo il numero di elementi non negativi nella lista
-- 2.2) foldr (&&) True . map (>= 0)    --  verifica se tutti i numeri di una lista sono non negativi.
-- 2.3) foldr (+) 0 . map (const 1)
-- 2.4) foldl (\xs x -> x : xs) []      -- Inverte una lista

-- 3) Definire le seguenti funzioni della libreria standard senza usare esplicitamente la ricorsione:
-- 3.1) concat :: [[a]] -> [a] -- concatena tutti gli elementi di una lista di liste
concat :: [[a]] -> [a]
concat = foldl (++) []

-- 3.2) any :: (a -> Bool) -> [a] -> Bool -- esiste almeno un elemento che soddisfa il predicato?
any :: (a -> Bool) -> [a] -> Bool
any f xs = null (filter f xs) -- in ordine da SX a DX: controllo che la lista non sia vuota. La lista è formata da tutti gli elementi che rispettano il criterio f e la lista è xs

-- 3.3) all :: (a -> Bool) -> [a] -> Bool -- tutti gli elementi soddisfano il predicato?
all :: (a -> Bool) -> [a] -> Bool
all f xs =  length (filter f xs) == length xs

-- 4) Definire le seguenti funzioni senza usare esplicitamente la ricorsione:
-- 4.1) massimo :: Ord a => [a] -> a -- massimo di una lista non vuota
massimo :: Ord a => [a] -> a
massimo (x : xs) = foldr max x xs 

-- 4.2) occorrenze :: Eq a => a -> [a] -> Int -- numero di occorrenze di un elemento
occorrenze :: Eq a => a -> [a] -> Int
occorrenze x =  length . filter (== x )

-- 4.3) membro :: Eq a => a -> [a] -> Bool -- true se l'elemento è presente (stop immediato se trovato)
membro :: Eq a => a -> [a] -> Bool
membro x =  null . filter (== x )
