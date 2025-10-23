{-
Polimorfismo
==================================

Il polimorfismo in Haskell è la proprietà per cui alcune funzioni possono essere applicate ad argomenti di tipi diversi. 
Le funzioni definite usando variabili di tipo anziché tipi concreti sono dette polimorfe.

Funzioni polimorfe
------------------
Una funzione polimorfa classica è la funzione identità:

    id x = x

Il tipo più generale di `id` è:

    id :: a -> a
    id x = x

Questo tipo indica che `id` può essere applicata a qualunque tipo `a` e restituisce un valore dello stesso tipo. Ad esempio, tutti i seguenti sono istanze di `id`:

    id 2          -- :: Int
    id True       -- :: Bool
    id 2.5        -- :: Float
    id id         -- :: (a -> a) -> (a -> a)

Polimorfismo e vincoli di tipo
------------------------------
Le variabili di tipo possono esprimere vincoli fra gli argomenti di una funzione. Ad esempio, l’operatore di concatenazione `++`:

    (++) :: [a] -> [a] -> [a]
    (++) [] ys = ys
    (++) (x:xs) ys = x : (xs ++ ys)

Il tipo sopra specifica che entrambe le liste in input devono avere lo stesso tipo di elementi. Analogamente, l’operatore di composizione funzionale:

    (.) :: (b -> c) -> (a -> b) -> a -> c
    (.) f g x = f (g x)

Il polimorfismo permette di comporre funzioni purché i tipi siano coerenti.

-}

-- Esercizi di riepilogo capitolo
identita :: a -> a -- Il tipo del dominio e del codominio sono uguali
identita x = x



-- 1) Determinare il tipo più generale delle seguenti funzioni:

fst (x, _) = x -- (a,b) -> a
snd (_, y) = y --(a,b) -> b
const x _ = x  -- a -> b -> a
curry f x y = f (x, y) --((a, b) -> c) -> a -> b -> c
uncurry f (x, y) = f x y --(a -> b -> c) -> (a, b) -> c

-- 2) La funzione "magia" ha tipo apparentemente "magico":

magia :: Int -> a
magia n = magia (n - 1) -- Non termina mai

-- 3) Osservando solo il tipo, prova a ragionare sul comportamento di funzioni con questi tipi:

-- 1. [a] -> Int    length perchè prende una lista e ritorna la lunghezza che è un intero
-- 2. [a] -> Bool   null perchè testa se una lista è vuota o no
-- 3. [a] -> a      head perchè prende una lista e ritorna il primo elemento
-- 4. [a] -> [a]    reverse perchè prende una lista e la ritorna al contrario
-- 5. [[a]] -> [a]  concat perchè prende una lista di liste e le unisce in una sola lista
-- 6. [a] -> Int -> a (!!) perchè prende una lista e un intero e ritorna l'elemento alla posizione indicata dall'intero
-- 7. Int -> [a] -> [a] take perchè prende un intero e una lista e ritorna i primi n elementi della lista
-- 8. [a] -> [b] -> [(a, b)] zip perchè prende due liste e ritorna una lista di coppie abbinate
-- 9. [(a, b)] -> ([a], [b]) unzip perchè prende una lista di coppie e ritorna due liste separate
