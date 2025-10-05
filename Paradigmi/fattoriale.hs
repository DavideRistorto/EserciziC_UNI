fattoriale :: Int -> Int
fattoriale n | n == 0 = 1
             | otherwise = n * fattoriale (n-1)

main :: IO ()
main = do
  print (fattoriale 1)
  print (fattoriale (5))