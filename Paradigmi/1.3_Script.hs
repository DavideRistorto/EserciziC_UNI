{-
Definizioni e dichiarazioni in Haskell
====================================

In Haskell, uno script è un file di testo con estensione `.hs` in cui si raccolgono **definizioni** (associazioni tra un nome e un'espressione). 
Si usa uno script quando il programma è complesso, invece di valutare solo espressioni semplici in `ghci`.

Ogni definizione di variabile in uno script è preceduta da una dichiarazione di tipo, ad esempio:
anno_terra :: Float          -- dichiarazione del tipo Float
raggio_terra = 2 * pi * 150e6   -- valore associato al nome (lunghezza orbita in km)

La notazione `150e6` significa 150 × 10^6 (cioè 150 milioni). Si può ugualmente dichiarare e definire altre costanti:

v_terra :: Float             -- dichiarazione del tipo Float
v_terra = anno_terra / (365 * 24)    -- velocità stimata della Terra (km/h)

Per usare le definizioni all'interno di `ghci`, si carica lo script:

  ghci PrimoScript.hs

o da dentro `ghci`:

  Prelude> :load PrimoScript.hs

Dopo ogni modifica del file, occorre ricaricare lo script con `:reload` o `:r`. Si lavora in due finestre: l'editor per modificare lo script e il terminale con `ghci` per testare.

Esempi principali
-----------------

anno_terra :: Float
anno_terra = 2 * pi * 150e6

v_terra :: Float
v_terra = anno_terra / (365 * 24)

-- Uso in ghci
-- > anno_terra
-- > v_terra

Dichiarare il tipo Int ad esempio per i numeri di Fibonacci, che richiedono interi:

f0 :: Int
f0 = 0

f1 :: Int
f1 = 1

f2 :: Int
f2 = f0 + f1

-}

-- Esercizi di riepilogo capitolo

-- 1) Aggiungere a PrimoScript.hs le definizioni per i nomi anno_mercurio e v_mercurio,
-- tenendo conto che Mercurio dista dal Sole circa 58 milioni di km e impiega 88 giorni terrestri per un'orbita.

anno_mercurio :: Float
anno_mercurio = 2 * pi * 58e6

v_mercurio :: Float
v_mercurio = anno_mercurio / (88 * 24)

-- 2) Completare la sequenza di Fibonacci aggiungendo allo script le definizioni per i nomi da f3 a f7,
-- dove ogni termine è dato dalla somma dei due precedenti.

f0 :: Int
f0 = 0

f1 :: Int
f1 = 1

f2 :: Int
f2 = f0 + f1
