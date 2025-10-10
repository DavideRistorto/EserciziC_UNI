-- List comprehension in Haskell
-- Sono espressioni che permettono di creare liste in modo conciso e leggibile
-- La sintassi di base è [espressione | elemento <- lista, condizione]

-- Esempio 1: Creare una lista di quadrati dei numeri da 1 a 10
squares :: [Int]
squares = [x^2 | x <- [1..10]]

-- È possibile usare un numero qualsiasi di generatori, nel qual caso vengono considerati tutti gli assegnamenti possibili dei nomi definiti da tali generatori. Ad esempio
pairs :: [(Int, Int)]
pairs = [ (x, y) | x <- [1..10], y <- [1..10] ]

-- Si possono specificare guardie per filtrare gli elementi della lista da generare
filteredPairs :: [(Int, Int)]
filteredPairs = [ (x, y) | x <- [1..10], y <- [1..10], x <= y ]

-- Esercizio 1: Ridefinire map e filter usando solo list comprehension
map :: (a -> b) -> [a] -> [b]
map f xs = [f x | x <- xs]

filter :: (a -> Bool) -> [a] -> [a]
filter f xs = [x | x <- xs, f x]

primo :: Integral a => a -> Bool
primo x = length [n | n <- [2 .. x], x `mod` n == 0] == 1 -- Metto nella lista tutti i divisori di x, se ne ha solo uno (se stesso) allora è primo
