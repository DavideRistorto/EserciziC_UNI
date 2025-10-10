insert :: Int -> [Int] -> [Int]
insert x [] = [x] -- Caso di lista vuota
insert x (y : ys) | x <= y = x : y : ys
                  | otherwise = y : insert x ys

-- (y : ys) significa che la lista ha almeno un elemento: y è il primo elemento, ys è il resto della lista
-- Se x è minore o uguale al primo elemento della lista (y), allora x viene messo davanti a y e al resto della lista
-- Se x è maggiore di y, si lascia y al suo posto e si prova a inserire x nel resto della lista (ys), chiamando la funzione ricorsivamente


insertSort :: [Int] -> [Int]
insertSort [] = []
insertSort (x : xs) = insert x (insertSort xs)



-- MERGE SORT

split :: [Int] -> ([Int], [Int])
split [] = ([], [])
split [x] = ([x], [])
split (x : y : list) = (x : xList, y : yList)
    where --serve a definire variabili locali
        (xList, yList) = split list

merge :: [Int] -> [Int] -> [Int]
merge []       ys = ys
merge xs       [] = xs
merge (x : xs) (y : ys) | x <= y    = x : merge xs (y : ys)
                        | otherwise = y : merge (x : xs) ys

mergeSort :: [Int] -> [Int]
mergeSort []  = []
mergeSort [x] = [x]
mergeSort xs  = merge (mergeSort ys) (mergeSort zs)
  where
    (ys, zs) = split xs