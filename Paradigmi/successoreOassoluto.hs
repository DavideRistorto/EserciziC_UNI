successore :: Int -> Int
successore n = n+1

assoluto :: Int -> Int
assoluto n | n >= 0 = n
           | n < 0  = negate n 


funzione :: Int -> Int
funzione n | mod n 2 == 0 = successore n
           | otherwise    = assoluto n

main :: IO ()
main = do
  print (funzione 2)
  print (funzione (-5))

