{-
Tipi e classi in Haskell
==================================

Haskell è un linguaggio fortemente tipato: permette solo le espressioni che rispettano regole precise sui tipi. I tipi principali sono:
  - Int: numeri interi a precisione finita (es: 32 o 64 bit).
  - Integer: numeri interi a precisione arbitraria.
  - Float: numeri decimali a precisione singola.
  - Double: numeri decimali a precisione doppia.
  - Bool: valori booleani, True e False.

# Tipi delle costanti
Il tipo di una costante numerica dipende dal contesto. Ad esempio:
  :type 1         -- Num a => a
  :type 1.5       -- Fractional a => a
Si può forzare il tipo:
  :type 1 :: Int
  :type 1 :: Integer
  :type 1 :: Float
  :type 1 :: Double

## Tipi delle funzioni
Le funzioni hanno tipo T -> S, ad esempio:
  :type not        -- not :: Bool -> Bool
  :type negate     -- negate :: Num a => a -> a
Posso applicare la funzione a un argomento di tipo compatibile:
  :type not True
  :type negate 1
  :type negate (1 :: Int)

N.B: Num si usa come tipo generico per definire una funzione che lavora con numeri 

Le funzioni polimorfe usano classi di tipi, ad esempio Num a => a -> a.

## Conversioni tra tipi numerici
Non si può convertire forzando il tipo:
  1.5 :: Int              -- Errore
  (1 :: Int) :: Float     -- Errore
Serve usare funzioni di conversione:
  fromIntegral :: (Integral a, Num b) => a -> b
  truncate     :: (RealFrac a, Integral b) => a -> b
  round        :: (RealFrac a, Integral b) => a -> b

Esempi:
  fromIntegral (1 :: Int) :: Float
  truncate 1.5
  round 1.5

-}

-- Esercizi di riepilogo capitolo

--1) Consegna es 1
-- Quali delle seguenti espressioni sono ben tipate? Verifica con GHCi.
-- 1 `div` 2
-- 1.5 `div` 2
-- 1 / 2
-- 1.5 / 2
-- (1 :: Int) / 2
-- (1 :: Float) / 2
-- (2 :: Int) + (3 :: Integer)
-- (2 :: Float) <= 3
-- (2 :: Float) < (3 :: Int)

--2) Consegna es 2
-- Correggi le espressioni mal tipate dell'esercizio precedente usando conversioni di tipo:
-- Esempi di correzioni:
-- fromIntegral (1 :: Int) / 2
-- (fromIntegral (2 :: Int)) + (3 :: Integer)
-- (2 :: Float) < fromIntegral (3 :: Int)

--3) Consegna es 3
-- Scrivi due espressioni che mostrano chiaramente la differenza tra "Int" e "Integer" (precisione finita vs arbitraria):
-- Esempio 1: maxBound :: Int
-- Esempio 2: 2^1000 :: Integer
