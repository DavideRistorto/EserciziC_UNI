-- ELEMENTI IN POSIZIONE PARI, NON RICORSIVA
pari_lib :: [Int] -> [Int]
pari_lib xs = map fst (filter(\(a,b) -> even b && a `mod` 2 == 0)(zip xs [0..]))  --096

-- NUMERO DI INVERSIONI, NON RICORSIVA
inversioni_lib ::  [Int] -> Int
inversioni_lib xs =  length (filter(\(a,b) -> a > b)(zip xs (tail xs)))


inversioni_ric :: [Int] -> Int
inversioni_ric [] = 0
inversioni_ric [_] = 0
inversioni_ric (x:y:xs) = if x > y then 1 + inversioni_ric (y:xs) else inversioni_ric (y:xs)

--che trovi, se c’è, l’ultimo numero pari in una lista di numeri interi. 
--È vietato fare uso esplicito della ricorsione, ma si possono usare tutte le funzioni definite nel modulo Prelude.
ultimoPari :: Integral a => [a] -> Maybe a
ultimoPari xs = if filter even xs == [] then Nothing else Just (head (filter even (reverse xs)))

ultimoPari_V2 :: Integral a => [a] -> Maybe a
ultimoPari_V2 xs = aux Nothing xs
    where
        aux ultPari [] = ultPari
        aux ultPari (x:xs) = if x `mod` 2 == 0 then aux (Just x) xs else aux ultPari xs


--applicata a due list xs e ys, determini se esiste un elemento di xs che è diverso da ogni elemento di ys
diverso_ric :: Eq a => [a] -> [a] -> Bool
diverso_ric [] _ = False
diverso_ric (x:xs) ys = aux x ys || diverso_ric xs ys
    where
        aux x [] = True
        aux x (y:ys) = x /= y && aux x ys

diverso_lib :: Eq a => [a] -> [a] -> Bool
diverso_lib xs ys = any (\x -> not (elem x ys)) xs 

-- Scrivere una funzione che trovi il primo numero negativo in una lista di numeri interi
primo_negativo_ric :: (Num a, Ord a) => [a] -> Maybe a
primo_negativo_ric [] = Nothing
primo_negativo_ric (x:xs) = if x < 0 then (Just x) else primo_negativo_ric xs 

--Scrivere una funzione che calcoli la somma alternata degli elementi di una lista (primo elemento con segno +, secondo con segno -, terzo con segno +
somma_alternata_ric :: Num a => [a] -> a
somma_alternata_ric [] = 0
somma_alternata_ric [x] = x
somma_alternata_ric (x:y:xs) = x - y + somma_alternata_ric xs

somma_alternata_lib :: Num a => [a] -> a
somma_alternata_lib xs = sum (map (\(a,b) -> if odd b then -a else a )(zip xs [0..]))

ultimo_multiplo_lib :: Integral a => a -> [a] -> a
ultimo_multiplo_lib a xs = head (filter (\x -> x `mod`  a == 0)(reverse xs))

ultimo_multiplo_ric :: Integral a => a -> [a] -> Maybe a
ultimo_multiplo_ric a xs = aux Nothing a xs
    where 
        aux ultimo _ [] = ultimo
        aux ultimo a (x:xs) = if x `mod` a == 0 then aux (Just x) a xs else aux ultimo a xs

conta_palindromi :: [String] -> Int
conta_palindromi [] = 0
conta_palindromi (str:xs) = if (str == (reverse str)) then 1 + conta_palindromi xs else conta_palindromi xs