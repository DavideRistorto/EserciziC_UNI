-- MAP
-- applica una funzione a tutti gli elementi di una lista
map' :: (a -> b) -> [a] -> [b]
map' _ []     = []
map' f (x:xs) = f x : map' f xs

-- esempio -> ritorna al quadrato tutti gli elementi di una lista
quadrati :: Num a => [a] -> [a] --Il vincolo Num a => indica che il tipo degli elementi deve appartenere alla classe dei numeri (Num)
quadrati = map (^ 2)


-- FILTER
-- filtra gli elementi di una lista in base a un predicato
filter' :: (a -> Bool) -> [a] -> [a]
filter' _ []     = []
filter' p (x:xs) = if p x then x : filter' p xs else filter' p xs

-- esempio -> ritorna solo gli elementi pari di una lista
pari :: Integral a => [a] -> [a]
pari = filter' even


-- FOLD
-- riduce una lista a un singolo valore, applicando una funzione binaria
fold' :: (b -> a -> b) -> b -> [a] -> b -- b è il tipo dell'accumulatore, a è il tipo degli elementi della lista
fold' _ acc []     = acc
fold' f acc (x:xs) = fold' f (f acc x) xs

-- esempio -> somma tutti gli elementi di una lista
somma :: Num a => [a] -> a
somma = fold' (+) 0


-- ESERCIZI
-- massimo :: Ord a => [a] -> a per calcolare il valore massimo di una lista non vuota
massimo :: Ord a => [a] -> a
massimo (x : xs) = foldr max x xs -- prendo il massimo tra tutti gli elementi della lista


-- occorrenze :: Eq a => a -> [a] -> Int per contare quante volte un elemento appare in una lista
occorrenze :: Eq a => a -> [a] -> Int
occorrenze x = length . filter ( == x)


-- membro :: Eq a => a -> [a] -> Bool per verificare se un elemento è presente in una lista
membro :: Eq a => a -> [a] -> Bool
membro x xs = elem x xs-- elem è una funzione predefinita in Haskell che verifica se un elemento è presente in una lista