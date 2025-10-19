{-
Funzioni
==================================

Definizione e applicazione di funzioni
--------------------------------------
Una funzione è una trasformazione dal dominio al codominio. 
In Haskell, si dichiarano specificando il tipo, che ha la forma `T -> S`, dove T è il dominio e S il codominio.

Esempio:

successore :: Int -> Int
successore x = x + 1

Esempi di uso della funzione `successore`:

successore 0 -> 1
successore 1 -> 2
successore 2 -> 3
successore 2 * 3  -- equivale a (successore 2) * 3 -> 3 * 3 -> 9
successore (2 * 3) -- equivale a successore (2 * 3) -> successore 6 -> 7

Predicati
---------
Una funzione dal tipo `Int -> Bool` può essere usata come predicato, ossia stabilisce se l'argomento ha una certa proprietà. Esempio:

pari :: Int -> Bool
pari n = n `mod` 2 == 0

Applicazione della funzione `pari`:

pari 0    -- True
pari 2    -- True
pari 3    -- False

Operatore di composizione funzionale
------------------------------------
Si possono comporre due funzioni con l'operatore `.` (punto):

dispari :: Int -> Bool
dispari = not . pari

`f . g` applicato a un argomento x calcola `f (g x)`. La funzione `dispari` è la negazione di `pari`, costruita tramite composizione senza dare esplicitamente il nome all’argomento.

-}

-- Esercizi di riepilogo capitolo

successore :: Int -> Int
successore n = n + 1

pari :: Int -> Bool
pari n = n `mod` 2 == 0

dispari :: Int -> Bool
dispari n = not (pari n)

-- 1) Ridefinire la funzione dispari senza usare l’operatore di composizione funzionale.
dispari2 :: Int -> Bool
dispari2 n = n `mod` 2 == 1

-- 2) Un anno è bisestile se è multiplo di 4 ma non di 100, oppure se è multiplo di 400. Definire un predicato bisestile :: Int -> Bool che, applicato a n, stabilisca se n è bisestile.
bisestile :: Int -> Bool
bisestile n = n `mod` 4 == 0 && n `mod` 100 /= 0

-- 3) La somma dei primi n numeri naturali è n(n+1)/2. Definire la funzione somma :: Int -> Int usando questa formula.
somma :: Int -> Int
somma n = n * (n+1) `div` 2

-- 4) Definire una funzione area :: Float -> Float che calcoli l’area del cerchio dato il raggio n.
area :: Float -> Float
area n = n ^ 2 * pi 
