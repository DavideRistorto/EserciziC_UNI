--Definire una funzione f :: Ord a => [a] -> [a] -> Bool che, applicata a due liste xs e ys, restituisca True se ogni elemento di ys è più piccolo dell’elemento corrispondente in xs e False altrimenti. Ad esempio:
--f [0, 1, 2] [] = True
--f [] [1] = False
--f [1, 2, 3] [1, 2] = False
--f [2, 3, 3] [1, 2] = True

--È vietato fare uso di list comprehension e di funzioni della libreria standard ad eccezione di quelle che hanno un nome simbolico, come ++, ., ecc.

f :: Ord a => [a] -> [a] -> Bool
f [] [] = True
f _ [] = True
f [] _ = False
f (x:xs) (y:ys) = (y < x) && f xs ys

-- Modo 3: Usando zip e all con and (CORRETTO)
f3 :: Ord a => [a] -> [a] -> Bool
f3 xs ys = length ys <= length xs && all (uncurry (<)) (zip ys xs)