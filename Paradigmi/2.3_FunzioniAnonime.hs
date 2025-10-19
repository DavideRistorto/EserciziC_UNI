{-
Funzioni anonime e sezioni
==================================

In Haskell, le funzioni sono "prima classe": puoi passarle come argomenti, restituirle come risultato e definirle direttamente dove servono. 
Le funzioni anonime (lambda espressioni) ti permettono di scrivere funzioni senza nome, usando la sintassi `\x -> espressione parametro`.

Esempio di funzione anonima:
successore = \x -> x + 1

Le funzioni anonime possono essere anche applicate direttamente:
(\x -> x + 1) 2     -- Risultato: 3
(\x -> x >= 0) 2    -- Risultato: True
(\x -> x + 1) (negate 2)  -- Risultato: -1

**Sezioni**: una sezione è un modo rapido di ottenere una funzione applicando solo uno dei due argomenti di un operatore.

Esempi di sezioni:
(1 +)     -- Funzione che aggiunge 1
(`mod` 2) -- Funzione "resto della divisione per 2"

Applicazione:
(1 +) 2         -- Risultato: 3
(1 +) 3         -- Risultato: 4
(`mod` 2) 2     -- Risultato: 0
(`mod` 2) 3     -- Risultato: 1

Espansione automatica:
(1 +)         ==> \x -> 1 + x
(`mod` 2)     ==> \x -> x `mod` 2

Attenzione alla proprietà di **commutatività**: per operatori commutativi come `+`, `(1 +)` e `(+ 1)` portano sempre alla "funzione successore"; 
per altri operatori, l'ordine cambia il significato (``(`mod` 2)``, `(2 `mod`)``).
-}

-- Esercizi di riepilogo capitolo

-- 1) Consegna: Scrivere due funzioni anonime che stabiliscano se un numero è pari o dispari.
-- (\x -> x even) 5
-- (\x -> not (even x)) 5

-- 2) Consegna: Scrivere la funzione anonima "valore assoluto".
-- (\x -> abs x ) (-5)


-- 3) Consegna: Descrivere a parole le seguenti funzioni e verificarle in GHCi.
-- 3.1) (< 10)        -- Funzione che verifica se l'argomento è minore di 10
-- 3.2) (10 <)        -- Funzione che verifica se 10 è minore dell'argomento
-- 3.3) (`mod` 2)     -- Funzione: calcola il resto della divisione per 2
-- 3.4) (1 /)         -- Funzione: calcola 1 diviso l'argomento
-- 3.5) (+ 1) . (* 2) -- Funzione: raddoppia l'argomento e poi aggiunge 1
-- 3.6) (* 2) . (+ 1) -- Funzione: aggiunge 1 all'argomento e poi raddoppia il risultato
-- 3.7) (== 0) . (`mod` 2) -- Funzione: restituisce True se il numero è pari
-- 3.8) (/= 0) . (`mod` 2) -- Funzione: restituisce True se il numero è dispari
