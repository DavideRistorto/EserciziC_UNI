massimo :: Int -> Int -> Int
massimo x y | x >= y = x
            | otherwise = y

minimo :: Int -> Int -> Int
minimo x y | x <= y = x
            | otherwise = y

potenza:: Int -> Int -> Int
potenza m 0 = 1
potenza m n = m * potenza m (n - 1)           