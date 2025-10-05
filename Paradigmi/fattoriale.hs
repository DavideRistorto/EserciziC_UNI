fattoriale :: Int -> Int
fattoriale n | n == 0 = 1
             | otherwise = n * fattoriale (n-1)

--Tecnica del pattern matching (riconosco l' input e scelgo la definizione giusta)
fattoriale1:: Int -> Int
fattoriale1 0 = 1
fattoriale1 n = n * fattoriale1 (n-1)

main :: IO ()
main = do
  print (fattoriale 1)
  print (fattoriale (5))