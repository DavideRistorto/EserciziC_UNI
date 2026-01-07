-- definizione di lista
data List a = Nil | Cons a (List a) deriving (Show)

-- Lunghezza di lista
lengthList :: List a -> Int
lengthList Nil = 0
lengthList (Cons _ xs) = 1 + lengthList xs 


-- Scrivi una funzione che calcola la somma di tutti gli elementi di una lista di interi definita con il tipo List.
sumList :: List Int -> Int
sumList Nil = 0
sumList (Cons x xs) = x + sumList xs

-- Scrivi una funzione che trasforma una List a in una lista standard di Haskell ([a]).
toList :: List a -> [a]
toList Nil = []
toList (Cons x xs) = x : toList xs


-- Scrivi una funzione che trasforma una lista standard di Haskell ([a]) in una List a
fromList :: [a] -> List a
fromList [] = Nil
fromList (x:xs) = Cons x (fromList xs)

-- Scrivi una funzione che, dato un valore n e una List Int, restituisce una nuova List Int contenente solo gli elementi maggiori di n.
filterGreater :: Int -> List Int -> List Int
filterGreater _ Nil = Nil
filterGreater a (Cons x xs) = if x > a then Cons x (filterGreater a xs) else filterGreater a xs

-- Scrivi una funzione che inverte una List a (reverse).
reverseList :: List a -> List a
reverseList xs = aux xs Nil
    where
        aux Nil acc = acc
        aux (Cons x xs) acc = aux xs (Cons x acc)