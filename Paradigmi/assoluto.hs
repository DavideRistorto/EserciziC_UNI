assoluto :: Int -> Int          --  In input un intero e restituisce un intero
assoluto n | n >= 0 = n         --  Se n è positivo o nullo restituisce n
           | n < 0  = negate n  --  Se n è negativo restituisce -n (else si definische come otherwise)

main :: IO ()
main = print (assoluto (-5))