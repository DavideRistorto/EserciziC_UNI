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