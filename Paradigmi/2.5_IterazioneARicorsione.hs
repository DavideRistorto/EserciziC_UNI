{-
Dall'Iterazione alla Ricorsione
==================================

In Haskell, gli algoritmi iterativi spesso vengono trasformati in forma **ricorsiva**. La ricorsione, però, non è sempre efficiente o immediata. 
Alcuni algoritmi, come la funzione di Fibonacci o il test di primalità, richiedono strategie particolari per essere tradotti da versione imperativa a ricorsiva. 

Esempio: Fibonacci ricorsivo semplice (inefficiente)
fibonacci :: Int -> Integer
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci k = fibonacci (k - 1) + fibonacci (k - 2)

Questa versione ha complessità esponenziale. Vediamo come ottenere una versione ricorsiva **lineare**.

**Esempio: Fibonacci ricorsivo lineare usando una funzione ausiliaria**
fibonacciAux :: Integer -> Integer -> Int -> Integer
fibonacciAux m _ 0 = m
fibonacciAux m n k = fibonacciAux n (m + n) (k - 1)

-- Specializzazione per il calcolo classico:
fibonacci :: Int -> Integer
fibonacci = fibonacciAux 0 1

In alternativa, la funzione ausiliaria (`aux`) si può definire localmente:
fibonacci :: Int -> Integer
fibonacci = aux 0 1
  where
    aux m _ 0 = m
    aux m n k = aux n (m + n) (k - 1)

**Esempio: Test di primalità ricorsivo**
primo :: Int -> Bool
primo n = aux 2
  where
    aux k
      | k >= n        = k == n
      | n `mod` k == 0 = False
      | otherwise      = aux (k + 1)

Qui la funzione ricorsiva `aux` scorre i possibili divisori di `n`, simulando l'iterazione.
-}

-- Esercizi di riepilogo capitolo

-- 1) Scrivi una funzione ricorsiva corrispondente al seguente algoritmo iterativo del fattoriale:
-- public static int fattoriale(int n) {
--     assert n >= 0;
--     int res = 1;
--     while (n > 0) {
--         res = res * n;
--         n = n - 1;
--     }
--     return res;
-- }
fattoriale :: Int -> Int
fattoriale n = if n == 0 then 1 else n * fattoriale (n-1)

-- 2) Scrivi una funzione ricorsiva corrispondente all'algoritmo iterativo dell'algoritmo di Euclide per il MCD:
-- public static int euclide(int m, int n) {
--     assert m > 0 && n > 0;
--     while (m != n)
--         if (m < n)
--             n -= m;
--         else
--             m -= n;
--     return n;
-- }
euclide :: Int -> Int -> Int
euclide m n
  | m <= 0 || n <= 0 = 0
  | m == n           = n
  | m < n            = euclide m (n - m)
  | otherwise        = euclide (m - n) n


--Scrivi una funzione sommaQuadratiPari :: [Int] -> Int che calcola la somma dei quadrati di tutti i numeri pari in una lista.
sommaQuadratiPari :: [Int] -> Int
sommaQuadratiPari xs = aux xs
  where 
    aux [] = 0
    aux (y:ys)
      | even y = y^2 + aux ys
      | otherwise = aux ys

-- Scrivi una funzione contaOccorrenze :: Int -> [Int] -> Int che conta quante volte un elemento appare in una lista.
contaOccorrenze :: Int -> [Int] -> Int
contaOccorrenze n xs = aux n xs
  where 
    aux n [] = 0
    aux n (x:xs)
      | n == x = 1 + aux n xs
      | otherwise = aux n xs



-- Scrivi una funzione listaCrescente :: [Int] -> Bool che verifica se una lista è ordinata in modo crescente.
listaCrescente :: [Int] -> Bool
listaCrescente [] = True
listaCrescente [x] = True
listaCrescente (x:y:xs) = if x > y then False else listaCrescente (y:xs)

-- Scrivi una funzione rimuoviElemento :: Int -> [Int] -> [Int] che rimuove tutte le occorrenze di un elemento da una lista.
rimuoviElemento :: Int -> [Int] -> [Int]
rimuoviElemento n [] = []
rimuoviElemento n (x:xs) = if n == x then rimuoviElemento n xs else x : rimuoviElemento n xs


-- Scrivi una funzione filtraETrasforma :: [Int] -> [Int] che:
-- Filtra solo i numeri maggiori di 10
-- Trasforma ciascun numero filtrato moltiplicandolo per 3
-- Restituisce la lista risultante

filtraETrasforma :: [Int] -> [Int]
filtraETrasforma [] = []
filtraETrasforma x = aux x
  where 
    aux [] = []
    aux (x:xs) = if x > 10 then x * 3 : aux xs else aux xs


