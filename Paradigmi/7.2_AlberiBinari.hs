{-
Alberi binari di ricerca
==================================

In questa lezione si definisce un tipo algebrico ricorsivo per rappresentare alberi binari e si mostrano le operazioni fondamentali su alberi
binari di ricerca: controllo dell’albero vuoto, profondità, visita in-order, massimo elemento, inserimento e cancellazione, più alcuni esercizi
riassuntivi sugli alberi di ricerca [page:1].

Tipo algebrico Tree
----------------------------------

Un albero binario ha due forme: una foglia (albero vuoto) o una diramazione con un elemento e due sotto-alberi [page:1].
Si introduce quindi un tipo polimorfo e ricorsivo `Tree a` con due costruttori, `Leaf` per l’albero vuoto e `Branch` per le diramazioni [page:1].

-}

data Tree a = Leaf | Branch a (Tree a) (Tree a) deriving Show


{-
Esempio di albero
----------------------------------

Si può costruire un albero non vuoto annidando i costruttori: `Leaf` rappresenta un sotto-albero vuoto, mentre `Branch` collega un valore con
il sotto-albero sinistro e destro [page:1].

-}

-- Esempio:
-- Branch 1 Leaf (Branch 2 Leaf Leaf)


{-
Funzione empty
----------------------------------

La funzione `empty` verifica se un albero è vuoto controllando se è il costruttore `Leaf` [page:1].
Se l’albero è `Leaf` restituisce True, altrimenti False [page:1].

-}

empty :: Tree a -> Bool
empty Leaf = True
empty _ = False

{-
Funzione depth
----------------------------------

La funzione `depth` calcola la profondità di un albero come lunghezza del percorso più lungo dalla radice a una foglia [page:1].
Per `Leaf` la profondità è 0, mentre per una `Branch` è 1 più il massimo tra la profondità del sotto-albero sinistro e destro [page:1].

-}

depth :: Tree a -> Int
depth Leaf = 0
depth (Branch _ sx dx) = 1 + max (depth sx) (depth dx)


{-
Funzione elements (visita in-order)
----------------------------------

La funzione `elements` raccoglie tutti gli elementi dell’albero in una lista eseguendo una visita in-order: prima il sotto-albero sinistro,
poi la radice, infine il sotto-albero destro [page:1].
Su `Leaf` restituisce la lista vuota, su `Branch` concatena gli elementi del sinistro, l’elemento alla radice e quelli del destro [page:1].

-}

elements :: Tree a -> [a]
elements Leaf = []
elements (Branch x sx dx) = elements sx ++ [x] ++ elements dx

-- Esempi:
-- elements Leaf
-- elements (Branch 1 Leaf (Branch 2 Leaf Leaf))


{-
Funzione tmax
----------------------------------

La funzione `tmax` calcola l’elemento più grande di un albero binario di ricerca seguendo iterativamente le diramazioni destre
fino a raggiungere una foglia [page:1].
La funzione è parziale: viene definita solo per alberi non vuoti e assume implicitamente che l’argomento sia un albero di ricerca (BST),
non un albero arbitrario [page:1].

-}

tmax :: Tree a -> a
tmax (Branch x _ Leaf) = x
tmax (Branch _ _ t)    = tmax t

-- Esempi:
-- tmax (Branch 1 Leaf (Branch 2 Leaf Leaf))
-- (non definita per Leaf)


{-
Funzione insert
----------------------------------

La funzione `insert` inserisce un elemento in un albero binario di ricerca restituendo un nuovo albero che mantiene la proprietà di ordinamento [page:1].
Si distinguono i casi: inserimento in `Leaf`, uguaglianza con la radice, elemento più piccolo della radice (si scende a sinistra),
elemento più grande (si scende a destra); viene usata un’ascrizione `t@(Branch ...)` per riutilizzare direttamente l’albero originale quando
non ci sono modifiche [page:1].

-}

insert :: Ord a => a -> Tree a -> Tree a
insert x Leaf = Branch x Leaf Leaf
insert x t@(Branch y t1 t2)
  | x == y    = t
  | x < y     = Branch y (insert x t1) t2
  | otherwise = Branch y t1 (insert x t2)

-- Esempi:
-- insert 3 (Branch 1 Leaf (Branch 2 Leaf Leaf))
-- foldr insert Leaf [4,2,1,3,0,5]


{-
Funzione delete
----------------------------------

La funzione `delete` rimuove un elemento da un albero binario di ricerca; se l’elemento non è presente l’albero resta invariato [page:1].
Si distinguono i casi: albero vuoto, ricerca nel sotto-albero sinistro o destro quando la radice è diversa dall’elemento,
cancellazione alla radice con uno dei sotto-alberi vuoto (si restituisce l’altro), oppure con entrambi i sotto-alberi non vuoti,
in cui si sostituisce la radice con il massimo del sotto-albero sinistro e si rimuove tale massimo da quel sotto-albero [page:1].

-}

delete :: Ord a => a -> Tree a -> Tree a
delete _ Leaf = Leaf
delete x (Branch y t1 t2)
  | x < y     = Branch y (delete x t1) t2
  | x > y     = Branch y t1 (delete x t2)
delete _ (Branch _ t Leaf) = t
delete _ (Branch _ Leaf t) = t
delete x (Branch _ t1 t2)  = Branch y (delete y t1) t2
  where
    y = tmax t1


-- Esercizi di riepilogo capitolo
-- (solo consegne, senza soluzioni)

-- 1) Definire la funzione tmin :: Tree a -> a
--     che restituisce l’elemento più piccolo in un albero binario di ricerca non vuoto. [page:1]
tmin :: Tree a -> a
tmin (Branch x Leaf _) = x
tmin (Branch _ sx _) = tmin sx

-- 2) Definire una versione totale di tmin con tipo
--     tminTotal :: Tree a -> Maybe a
--     che restituisce Nothing per l’albero vuoto e Just del minimo altrimenti. [page:1]
tminTotal :: Tree a -> Maybe a
tminTotal Leaf = Nothing
tminTotal (Branch x Leaf _) = Just x
tminTotal (Branch _ sx _) = Just (tmin sx)


-- 3) Definire la funzione
--     treeSort :: Ord a => [a] -> [a]
--     che ordina gli elementi di una lista usando un albero binario di ricerca come struttura intermedia. [page:1]

-- 4) Definire la funzione
--     bst :: Tree a -> Bool
--     che verifica se un albero binario qualsiasi è un albero binario di ricerca (BST).
--     Suggerimento: usare empty, tmin, tmax. [page:1]
