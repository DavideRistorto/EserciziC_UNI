--curry: trasforma una funzione che prende una coppia (una tupla) in una funzione che prende due argomenti separati.
-- Esempi pratici:

-- Esempio 1: uso di curry
sommaCoppia :: (Int, Int) -> Int
sommaCoppia (x, y) = x + y

sommaCurried :: Int -> Int -> Int
sommaCurried x y  = curry sommaCoppia x y 

-- sommaCurried 3 4 == 7
-- oppure: let f = sommaCurried 3 in f 4 == 7

--uncurry: fa l’opposto, trasforma una funzione che prende due argomenti in una funzione che prende una tupla.
-- Esempio 2: uso di uncurry
moltiplica :: Int -> Int -> Int
moltiplica x y = x * y

moltiplicaCoppia :: (Int, Int) -> Int
moltiplicaCoppia = uncurry moltiplica

-- moltiplicaCoppia (3, 4) == 12

-- Esempio 3: map con uncurry
listaCoppie = [(1,2), (3,4), (5,6)]
sommaTutte = map (uncurry (+)) listaCoppie  -- [3,7,11]


-- =========================
-- Esercizi su curry e uncurry
-- =========================

-- 1. Scrivi una funzione che prende una coppia di stringhe e le concatena, 
-- poi usala con curry per ottenere una funzione che prende due stringhe separate.
concatenaString :: (String, String) -> String
concatenaString (s1, s2) = s1 ++ s2 

concatenaStringCurry :: String -> String -> String
concatenaStringCurry s1 s2 = curry concatenaString s1 s2 


-- 2. Scrivi una funzione che prende due Float e restituisce la loro media, poi usala con uncurry per applicarla a una lista di coppie di Float.
mediaFloat :: Float -> Float -> Float
mediaFloat a b = (a+b)/2

mediaFloatUncurry :: (Float, Float) -> Float
mediaFloatUncurry (a,b) = uncurry mediaFloat (a,b)

-- 3. Data la funzione max :: Ord a => a -> a -> a, usala con uncurry per trovare il massimo in una lista di coppie di numeri.

-- 4. Scrivi una funzione che prende una tripla (Int, Int, Int) e restituisce la somma dei tre numeri. Riesci a "currificare" questa funzione? (Suggerimento: guarda la firma di curry)

-- 5. Spiega con parole tue la differenza tra curry e uncurry e quando può essere utile usarle.