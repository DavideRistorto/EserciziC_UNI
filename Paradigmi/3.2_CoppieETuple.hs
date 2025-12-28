{-
Coppie e Tuple in Haskell
==================================

Una **tupla** è una sequenza ordinata e finita di elementi, che possono avere tipi diversi. In Haskell, la sintassi per creare una tupla è:

    (elemento1, elemento2, ...)

Alcuni esempi:
    (1, True)                   -- Coppia: un Int e Bool
    (False, 2.5, True)          -- Tripla: Bool, Double, Bool

La dichiarazione di tipo per una tupla segue la sequenza dei tipi delle sue componenti:
    (2.5, True)     :: (Double, Bool)
    (False, (2, True)) :: (Bool, (Int, Bool))

Una tupla può contenere funzioni o altre tuple come elementi. Attenzione: `(False, 2, True)` e `(False, (2, True))` sono di tipo diverso!

Le tuple non possono essere confrontate tra loro (`==`, `/=`) se non hanno lo stesso tipo.

Pattern matching sulle tuple
---------------------------
È possibile decomporre le tuple attribuendo un nome alle componenti, per esempio:

    addizione :: (Int, Int) -> Int
    addizione (x, y) = x + y

La funzione sopra accetta una coppia e restituisce la loro somma.
Esempio di applicazione:
    addizione (1, 2)   -- restituisce 3

Nota: pur essendo possibile raggruppare più argomenti in una tupla, in Haskell spesso è preferibile il currying per funzioni a più parametri.

-}

somma :: (Int, Int) -> Int
somma (x, y) = x + y

-- Esercizi di riepilogo capitolo

-- 1) Definire una funzione scambia :: (Int, Int) -> (Int, Int) che scambia le componenti di una coppia
scambia :: (Int, Int) -> (Int, Int)
scambia (x, y) = (y, x)


-- 2) Definire una funzione ordina :: (Int, Int, Int) -> (Int, Int, Int) che ordina gli elementi in modo non decrescente
ordina :: (Int, Int, Int) -> (Int, Int, Int)
ordina (a, b, c) | a > b = ordina (b, a, c)
ordina (a, b, c) | b > c = ordina (a, c, b)
ordina x = x

-- 3) Operazioni sui numeri complessi rappresentati come coppie di Double:
-- alias del tipo (Double, Double)
type Complesso = (Double, Double)
-- Addizione
addizione :: Complesso -> Complesso -> Complesso
addizione (a,b) (c,d) = (a+c, d+b) -- somma la parte reale con la reale e l' immaginaria con l' immaginaria

-- Negazione
nega :: Complesso -> Complesso
nega (a,b) = (-a, -b)

-- Sottrazione
sottrazione :: Complesso -> Complesso -> Complesso
sottrazione (a,b) (c,d) = (a-c+c, b-d)