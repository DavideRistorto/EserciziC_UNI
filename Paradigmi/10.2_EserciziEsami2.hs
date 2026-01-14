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