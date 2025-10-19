{-
Proposizioni logiche in Haskell
==================================

Valori booleani
In Haskell, i valori di verità sono rappresentati dalle costanti True e False.

Gli operatori logici sono:

AND: &&
OR: ||
NOT: not (funzione prefix, es: not True)

Esempi:
True && True -- True
True || False -- True
not True -- False
not ((True && False) || True) -- False

Gli operatori && e || sono cortocircuitati: il secondo operando viene valutato solo se necessario.

Confronti e relazioni d'ordine
Operatori di confronto su numeri e valori:
== -- uguaglianza
/= -- disuguaglianza
<, >, <=, >= -- relazioni d'ordine

Esempi:
2 == 3 -- False
2 /= 3 -- True
2.5 < 3 -- True
2 >= 3 -- False

In Haskell, la struttura condizionale è:
if condizione then espr1 else espr2

La condizione deve essere un'espressione booleana; espr1 ed espr2 devono avere lo stesso tipo.

Esempio di funzione che restituisce il valore assoluto di un intero:
assoluto :: Int -> Int
assoluto n = if n >= 0 then n else negate n

assoluto 3 -- 3
assoluto (negate 3) -- 3

Esempi di espressioni condizionali valide:
if True then 1 else 0
if 2 < 3 then 1 else 0
if 2 == 2 then False else True

Esempi errati (per tipologia o assenza dell'else):
if 1 then True else False -- ERRATO: 1 non è booleano
if True then 1 else False -- ERRATO: 1 e False hanno tipi diversi

Non si può omettere else.

if E1 then E2 else E3 è simile a E1 ? E2 : E3 in C/Java.

-}


-- Esercizi di riepilogo capitolo

--1) Esprimere la condizione "1 <= 0 || 0 <= 1". Il valore deve essere True.
condizione1 :: Bool
condizione1 = 1 <= 0 || 0 <= 1

--2) Dimostrare che && è cortocircuitato (usando ad esempio una divisione per zero nel secondo operando).
condizione2 :: Bool
condizione2 = False && 1 / 0 == 0

--3) Ripetere il precedente con ||.
condizione3 :: Bool
condizione3 = True || 1 / 0 == 0

--4) Riscrivere E1 && E2 ed E1 || E2 tramite espressioni condizionali if-then-else.
andCond :: Bool -> Bool -> Bool
andCond e1 e2 = if e1 then e2 else False

orCond :: Bool -> Bool -> Bool
orCond e1 e2 = if e1 then True else e2