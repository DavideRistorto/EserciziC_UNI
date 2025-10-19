{-
Espressioni aritmetiche in Haskell
==================================

- Haskell può essere usato come calcolatrice per valutare espressioni aritmetiche.
- Gli operatori su numeri interi includono: +, -, *, /,`div`, `mod`, ^.
  - `div` e `mod` si usano con i backtick per la notazione infissa (es: 2 `div` 3).
- / è usato per la divisione reale su numeri floating point (7 / 2 = 3.5).
- div è usato per la divisione intera (7 `div` 2 = 3).
- Le parentesi tonde servono a forzare l’associatività tra operazioni.
- Le funzioni predefinite come negate o abs si applicano semplicemente scrivendo il nome seguito dall’argomento:
    negate 2           -- -2
    abs (2 - 5)        -- 3
- L’applicazione funzionale con lo spazio ha massima precedenza e associatività a sinistra:
    abs negate 3       -- errore (non è come abs (negate 3))
- Numeri con la virgola (floating point) si scrivono col punto o in notazione scientifica (es: 0.5, 5.0e-8).
  - L’operatore "/" effettua divisione reale differenziandosi da `div` che funziona solo su interi.
- ATTENZIONE: div e mod funzionano solo su numeri interi.
- Esempi ed esercizi propongono calcolo di somme e prodotti, uso di operatori e parentesi.

-}

-- Esercizi di riepilogo capitolo

-- 1) Scrivere un’espressione per calcolare la somma dei numeri da 1 a 5. Il valore dell’espressione deve essere 15
somma15 :: Integer
somma15 = 1 + 2 + 3 + 4 + 5

-- 2) Scrivere un’espressione per calcolare il prodotto dei numeri da 1 a 5. Il valore dell’espressione deve essere 120
prodotto120 :: Integer
prodotto120 = 1 * 2 * 3 * 4 * 5

-- 3) Scrivere un’espressione per calcolare la sommatoria delle prime 5 potenze di 2.  Il valore dell’espressione deve essere 31.
potenza31 :: Integer
potenza31 = 2^0 + 2^1 + 2^2 + 2^3 + 2^4