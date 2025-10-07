-- Le liste a differenza delle tuple sono omogenee

-- Definizione di una lista
myList :: [Int]
myList = [1, 2, 3, 4, 5]

-- Liste di liste
listOfLists :: [[Int]]
listOfLists = [[1, 2], [3, 4], [5]]

-- Operazioni sulle liste
lengthOfList :: Int
lengthOfList = length myList -- funzione 'length' built-in per la lunghezza

sumOfList :: Int
sumOfList = sum myList -- funzione 'sum' built-in per la somma

productOfList :: Int
productOfList = product myList -- funzione 'product' built-in per il prodotto

appendLists :: [Int]
appendLists = myList ++ [6, 7, 8] -- operatore '++' per concatenare liste

media :: [Int] -> Float
media xs = fromIntegral( sum xs) / fromIntegral(length xs)

intervallo :: Int -> Int -> [Int]
intervallo x y | x > y = []
               | otherwise = x : intervallo (x+1) y -- : concatena le liste

stessaLunghezzaEasy :: [Int] -> [Int] -> Bool
stessaLunghezzaEasy x y = length x == length y

-- Ottimizziamo la funzione col pattern matching
stessaLunghezza :: [Int] -> [Int] -> Bool
stessaLunghezza []       []       = True
stessaLunghezza []       _        = False
stessaLunghezza _        []       = False
stessaLunghezza (_ : xs) (_ : ys) = stessaLunghezza xs ys
