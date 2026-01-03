{-
Tipi polimorfi e ricorsivi
==================================

Questa lezione introduce i tipi polimorfi e ricorsivi in Haskell.

-- Tipi polimorfi

Un tipo polimorfo permette di rappresentare valori di differenti tipologie senza duplicare codice. 
Esempio classico: il tipo Maybe, che sostituisce una versione monomorfa (ad esempio ForseInt).
Definizione:

data Maybe a = Nothing | Just a

Esempi di utilizzo:

Just 1        :: Maybe Int
Just True     :: Maybe Bool
Just [0.5]    :: Maybe [Float]

I costruttori Nothing e Just sono entrambi polimorfi.
Maybe diventa così un costruttore di tipo: dato un tipo T, produce il tipo Maybe T.

Altro esempio polimorfo è Either, che rappresenta un'unione disgiunta di due tipi:

data Either a b = Left a | Right b

Esempi:

Left 1        :: Either Int b
Right True    :: Either a Bool
[Left 1, Right True]  -- lista di Either Int Bool

-- Tipi ricorsivi

Un tipo ricorsivo può contenere valori definiti dallo stesso tipo. Esempio: le liste.

data List a = Nil | Cons a (List a)

Esempi:

Nil
Cons 1 Nil
Cons 1 (Cons 2 (Cons 3 Nil))

-}

-- Esercizi di riepilogo capitolo

-- 1) Definire le seguenti funzioni per Maybe:
--    maybeLength :: Maybe a -> Int
--    maybeMap :: (a -> b) -> Maybe a -> Maybe b
--    maybeFilter :: (a -> Bool) -> Maybe a -> Maybe a

-- Funzione polimorfa: restituisce 1 se c'è un valore, 0 se Nothing
maybeLength :: Maybe a -> Int
maybeLength Nothing  = 0
maybeLength (Just _) = 1

maybeMap :: (a -> b) -> Maybe a -> Maybe b
maybeMap f Nothing = Nothing
maybeMap f (Just x) = Just (f x)


data List a = Nil | Cons a (List a)
lengthList :: List a -> Int
lengthList Nil = 0
lengthList (Cons _ xs) = 1 + lengthList xs

sumList :: List Int -> Int
sumList Nil = 0
sumList (Cons x xs) = x + sumList xs

countGreater :: Int -> List Int -> Int
countGreater _ Nil = 0
countGreater val (Cons x xs) = if x > val then 1 + countGreater val xs else countGreater val xs
