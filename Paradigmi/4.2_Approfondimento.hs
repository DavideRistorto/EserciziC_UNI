{-
Approfondimento sulle classi
==================================

Questa lezione tratta le classi predefinite in Haskell, cioè insiemi di tipi che condividono un insieme di operazioni. 
Le classi importanti presentate sono Eq, Ord, Enum, Bounded, Num e le sue sotto-classi. 
Ogni classe specifica quali operazioni sono disponibili per i suoi tipi istanza. 
Le linee di ereditarietà permettono alle sotto-classi di ereditare operazioni dalle classi superiori 
(ad esempio, se Int è istanza di Bounded, indirettamente eredita anche le operazioni di Enum, Real, Num, Ord, Eq). 
Puoi ottenere dettagli su ogni classe (operatori, istanze) usando il comando `:info <NomeClasse>` in GHCi.

Principali classi illustrate:
  - Eq: consente di confrontare uguaglianza (`==`) e disuguaglianza (`/=`) tra valori. Non si applica alle funzioni.
  - Ord: tipi con ordine totale (operatori `<`, `>`, `<=`, `>=`, funzioni `min`, `max`).
  - Enum: tipi che supportano il calcolo del successore/predecessore (`succ`, `pred`).
  - Bounded: tipi con minimo e massimo valore (`minBound`, `maxBound`).
  - Num e sotto-classi:
       `Num`: somma, sottrazione, prodotto, `abs`, `negate`
       `Integral`: divisione intera (`div`, `mod`)
       `Fractional`: numeri con la virgola (`/`, `recip`)
       `RealFrac`: arrotondamento e troncamento (`round`, `truncate`)
       `Floating`: numeri in virgola mobile, funzioni matematiche (`exp`, `log`, `sqrt`, trigonometriche)

Esempi selezionati:
----------------------------------

-- Eq
3 == 3        -- True
3 /= 4        -- True

-- Ord
min 5 7       -- 5
max 5 7       -- 7
5 < 7         -- True
7 > 5         -- True

-- Enum
succ 3        -- 4
pred 3        -- 2

-- Bounded
minBound :: Int   -- valore minimo rappresentabile per Int
maxBound :: Int   -- valore massimo rappresentabile per Int

-- Num & sotto-classi
5 + 3         -- 8
7 - 2         -- 5
4  6         -- 24
abs (-7)      -- 7
negate 5      -- -5

-- Integral
7 `div` 3     -- 2
7 `mod` 3     -- 1

-- Fractional
7 / 2         -- 3.5
recip 2       -- 0.5

-- RealFrac
round 3.7     -- 4
truncate 3.7  -- 3

-- Floating
exp 1         -- 2.718...
log 1         -- 0
sqrt 9        -- 3
sin (pi/2)    -- 1.0

-}

-- Esercizi di riepilogo capitolo

-- 1) Usa GHCi per scoprire il valore minimo e massimo rappresentabile per Int (usa: minBound :: Int e maxBound :: Int).

-- 2) Mostra che succ e pred della classe Enum sono funzioni parziali: prova ad applicarle al valore massimo/minimo di Int e discuti il risultato (ad esempio: succ (maxBound :: Int)).
-- Fornisce questo errore: *** Exception: Prelude.Enum.succ{Int}: tried to take `succ' of maxBound