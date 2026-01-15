--1) contenuto :: [a] -> a -> Bool el contenuto nella lista
contenutoV1 :: Eq a => [a] -> a -> Bool
contenutoV1 xs a = elem a xs

contenutoV2 :: Eq a => [a] -> a -> Bool
contenutoV2 [] _ = False
contenutoV2 (x:xs) a = (a == x) || contenutoV2 xs a


--2) primo elemento == ultimo 
primoUltimoV1 :: Eq a => [a] -> Bool
primoUltimoV1 xs = head xs == last xs

primoUltimoV2 :: Eq a => [a] -> Bool
primoUltimoV2 [] = False
primoUltimoV2 [_] = True
primoUltimoV2 (x : xs) = x == ultimo xs
  where
    ultimo [y] = y
    ultimo (y:ys) = ultimo ys

--3) crea_pari :: [a] -> [a] lista risultato con solo numeri pari
creaPariV1 :: Integral a => [a] -> [a]
creaPariV1 = filter even

creaPariV2 :: Integral a => [a] -> [a]
creaPariV2 [] = []
creaPariV2 (x:xs) = if x `mod` 2 == 0 then x : creaPariV2 xs else creaPariV2 xs

--4) crea_pari_ind :: [a] -> [a] lista risultato con solo numeri in pos pari (il primo elemento sta in pos 0 e 0 è pari)
creaPariIndV1 :: [a] -> [a]
creaPariIndV1 [] = []
creaPariIndV1 [x] = [x]
creaPariIndV1 (x : y : xs) = x : creaPariIndV1 xs

creaPariIndV2 :: [a] -> [a]
creaPariIndV2 [] = []
creaPariIndV2 [x] = [x]
creaPariIndV2 (x:xs) = x : creaPariIndV2 (drop 1 xs)

--5)crea_pari_ind1 :: [a] -> [a] lista risultato con gli indici degli elementi pari (il primo elemento sta in pos 0 e 0 è pari)
creaPariInd1V1 :: Integral a => [a] -> [a]
creaPariInd1V1 xs = map snd (filter (\(a,b) -> even b) (zip xs [0..])) -- creo lista (num, indice) -> filtro solo le coppie con indice pari -> per ogni tupla prendo il secono elemento

somma :: Integral a => [a] -> Bool
somma xs = primo xs && ultimo xs
  where
    primo (x:xs) = x == sum xs
    ultimo (xs) = last xs ==  sum (tail (reverse xs))