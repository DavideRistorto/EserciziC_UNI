import Data.Char (ord)

{-
Caratteri e stringhe
==================================

La lezione introduce il tipo `Char` per rappresentare i singoli caratteri e il tipo `String` come alias per `[Char]`, spiegando come
scrivere letterali di carattere e di stringa, come usare le sequenze di escape, come rappresentare caratteri tramite codici Unicode e
come convertire tra caratteri e interi con le funzioni `ord` e `chr` del modulo `Data.Char` [page:2].
Viene inoltre ricordato che le stringhe sono liste di caratteri, quindi tutte le funzioni sulle liste (come `length` o l’operatore `++`)
sono applicabili anche alle stringhe [page:2].

Caratteri (`Char`)
----------------------------------

Un **carattere** in Haskell si scrive tra apici singoli ed è di tipo `Char`, distinto e incompatibile con i tipi numerici interi [page:2].
Non esistono conversioni implicite tra `Char` e `Int`, ma si usano le funzioni `ord` e `chr` dal modulo `Data.Char` per passare dal
codice numerico al carattere e viceversa [page:2].

Esempi di caratteri semplici
----------------------------------

-- Alcuni caratteri visibili
'a'
'b'
'a' == 'A'   -- False: distinzione tra minuscole e maiuscole [page:2]

Esempi di caratteri con escape
----------------------------------

-- Caratteri "invisibili" o speciali
'\n'   -- ritorno a capo
'\t'   -- tabulazione
'\\'   -- backslash
'\''   -- apice singolo
'\"'   -- doppi apici [page:2]

Caratteri tramite codice Unicode
----------------------------------

-- Codici Unicode in base 10
'\32'    -- spazio
'\48'    -- cifra decimale '0'

-- Caratteri Unicode letterali
'λ'      -- lettera greca lambda

-- Codici Unicode in base 16 (prefisso x)
'\x3BB'  -- lettera greca lambda [page:2]

Uso di `ord` e `chr` (Data.Char)
----------------------------------

-- Import delle funzioni per convertire tra caratteri e interi
import Data.Char (ord, chr)  -- da mettere in cima al file quando serve [page:2]

-- Esempi di conversione
ord '0'   -- restituisce il codice numerico del carattere '0'
chr 48    -- restituisce il carattere con codice 48, cioè '0' [page:2]


Stringhe (`String` e `[Char]`)
----------------------------------

Una **stringa** si scrive tra doppi apici; il tipo `String` è un alias per la lista di caratteri `[Char]`, quindi una stringa è
rappresentata internamente come una lista di `Char` [page:2].
Di conseguenza tutte le funzioni definite per le liste sono direttamente applicabili alle stringhe, ad esempio `length` o l’operatore
di concatenazione `++` [page:2].

Esempi di stringhe letterali
----------------------------------

""                         -- stringa vuota
"Haskell"
"Questa è una stringa con spazi" [page:2]

Relazione tra `String` e `[Char]`
----------------------------------

['H','a','s','k','e','l','l']  -- lista di Char
[] == ""                       -- la lista vuota è la stringa vuota
['x','y','z'] /= "xyz"         -- confronto di liste/ stringhe come sequenze di Char [page:2]

Funzioni sulle stringhe (liste)
----------------------------------

-- `length` calcola la lunghezza di una stringa
length "xyz"    -- 3

-- `++` concatena due stringhe
"HAS" ++ "kell" -- "HASkell" [page:2]


-- Esercizi di riepilogo capitolo
-}

-- 1) Definire una funzione
--    showHex :: Int -> String
--    che, applicata a un numero intero, ne restituisca la rappresentazione in base 16,
--    gestendo anche il caso in cui il numero sia negativo.
--    Suggerimento: definire una funzione ausiliaria che converta un numero intero compreso
--    tra 0 e 15 (estremi inclusi) nel carattere corrispondente in base 16. [page:2]

-- 2) (difficile) Senza usare funzioni della libreria standard
--    ad eccezione di `ord` e `chr`, definire una funzione
--    readHex :: String -> Int
--    che, applicata a una stringa di cifre esadecimali, restituisca il numero intero
--    (non negativo) corrispondente, gestendo sia lettere minuscole che maiuscole. [page:2]
readHex :: String -> Int
readHex = aux 0
  where
    aux res [] = res
    aux res (c : cs) = aux (res * 16 + readChar c) cs

    readChar c | c >= '0' && c <= '9' = ord c - ord '0'
               | c >= 'a' && c <= 'f' = ord c - ord 'a' + 10
               | c >= 'A' && c <= 'F' = ord c - ord 'A' + 10

-- 3) (difficile) Ripetere l’esercizio precedente definendo ancora
--    readHex :: String -> Int
--    ma questa volta senza usare esplicitamente la ricorsione e potendo usare
--    tutte le funzioni della libreria standard. [page:2]
