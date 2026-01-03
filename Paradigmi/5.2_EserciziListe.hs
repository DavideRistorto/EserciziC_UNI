--1) Definire una funzione ricorsiva che, applicata a una lista non vuota di numeri 
--   restituisca True se l’ultimo elemento è uguale alla somma di quelli che lo precedono
sommaUltimo :: (Num a, Eq a) => [a] -> Bool
sommaUltimo xs = aux xs 0
    where
        aux [x] somma = x == somma
        aux (x:xs) somma = aux xs (somma+x)

sommaUltimo_v2 :: (Num a, Eq a) => [a] -> Bool
sommaUltimo_v2 xs = head ys == sum (tail ys)
    where
        ys = reverse xs

sottoListe :: [a] -> [[a]]
sottoListe [] = [[]]
sottoListe (x : xs) = xss ++ map (x :) xss
  where
    xss = sottoListe xs