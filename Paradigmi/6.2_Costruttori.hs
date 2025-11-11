{- 
Costruttori con argomenti
=========================

I costruttori di tipo in Haskell possono avere argomenti, che permettono di associare dati ai valori creati. 
Questo è utile per creare tipi che distinguano tra casi diversi, come errori o valori validi.

Funzioni parziali e totali:
---------------------------
Una funzione **parziale** come:

elemento :: Int -> [Int] -> Int
elemento 0 (x : _)     = x
elemento n (_ : xs)    = elemento (n - 1) xs

non gestisce tutti gli input (ad esempio, l'indice fuori dai limiti). Una funzione **totale** può forzare un valore di errore:

elemento :: Int -> [Int] -> Int
elemento 0 (x : _)     = x
elemento n (_ : xs)    = elemento (n - 1) xs
elemento _ _           = -1

Ma questa strategia sacrifica il significato di -1.

Meglio ancora, si può restituire un tipo che distingue il caso di errore, come ForseInt:

data ForseInt = Niente | Proprio Int deriving Show

così il costruttore Proprio include il dato valido, e Niente indica errore.

Esempio pratico:

elemento :: Int -> [Int] -> ForseInt
elemento 0 (x : _)     = Proprio x
elemento n (_ : xs)    = elemento (n - 1) xs
elemento _ _           = Niente

Pattern matching sul risultato di funzioni:
-------------------------------------------
Per pattern matching sui risultati, si usa la case expression. Ad esempio, per trovare la posizione della prima occorrenza di un valore:

posizione :: Int -> [Int] -> ForseInt
posizione _ []         = Niente
posizione x (y : _) | x == y = Proprio 0
posizione x (_ : xs)  = case posizione x xs of
    Niente    -> Niente
    Proprio n -> Proprio (n + 1)

Quindi, se il valore non è trovato, restituisce Niente, altrimenti la posizione calibrata.

Esempi:
-- posizione 0 [1,2,3] --> Niente
-- posizione 1 [1,2,3] --> Proprio 0
-- posizione 3 [1,2,3] --> Proprio 2

-}

-- Esercizi di riepilogo capitolo

-- 1) Realizzare una funzione totale testa :: [Int] -> ForseInt
-- che ritorni la testa di xs se non vuota, Niente altrimenti.

-- 2) Definire un tipo di dato Numero
-- data Numero = I Int | F Float
-- e una funzione somma :: Numero -> Numero -> Numero
-- che somma due numeri rispettando i tipi (float solo se necessario).

-- 3) Definire sommatoria :: [Numero] -> Numero
-- che somma una lista di Numero senza ricorsione esplicita.

-- 4) Definire proprio :: [ForseInt] -> [Int]
-- che estrae la lista dei valori n tali che Proprio n appare in xs.

