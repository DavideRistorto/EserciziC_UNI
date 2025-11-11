{- 
Enumerazioni
==================================

Una enumerazione è un tipo di dato i cui valori sono finiti e specificati alla definizione. 
Esempio: il tipo Bool in Haskell ha solo i valori True e False.

-- Definizione di una enumerazione
data Mossa = Sasso | Carta | Forbici

-- I valori di tipo Mossa sono solo Sasso, Carta e Forbici.

-- Il tipo è incompatibile con gli altri tipi. Ad esempio non si possono mischiare numeri e mosse.
-- [Sasso, 0] -- Errore

-- Visualizzazione
-- Per visualizzare un valore di tipo Mossa, serve rendere il tipo istanza di Show:

data Mossa = Sasso | Carta | Forbici deriving Show

-- Pattern matching
-- Si può analizzare il valore di un tipo enumerato con il pattern matching.

vince :: Mossa -> Mossa -> Int
vince Sasso Carta    = 2  -- Vince il giocatore 2
vince Sasso Forbici  = 1  -- Vince il giocatore 1
vince Carta Sasso    = 1
vince Carta Forbici  = 2
vince Forbici Sasso  = 2
vince Forbici Carta  = 1
vince _ _            = 0  -- Parità

-- Funzione che simula una partita a morra cinese tra due liste di mosse:
morra :: [Mossa] -> [Mossa] -> Int
morra [] [] = 0                 -- Parità
morra _ [] = 1                  -- Vince giocatore 1
morra [] _ = 2                  -- Vince giocatore 2
morra (x:xs) (y:ys)
  | vincitore /= 0 = vincitore  -- Se c'è un vincitore, termina
  | otherwise = morra xs ys     -- Altrimenti continua con le mosse successive
  where vincitore = vince x y

-- Esempi di uso:
-- morra [Sasso,Carta,Carta] [Sasso,Carta]
-- morra [Sasso,Carta,Carta] [Sasso,Carta,Forbici]
-- morra [Sasso,Carta,Sasso] [Sasso,Carta,Forbici]

-- Tipo Unitario
-- Un tipo enumerato con un solo costruttore (unit type):

data () = ()

-- Il tipo unitario ha un solo valore (), che non porta informazione. 
-- Funzioni come () -> T o T -> () sono usate spesso per rappresentare effetti nulli.

-}

data Mossa = Sasso | Carta | Forbici
vince :: Mossa -> Mossa -> Int
vince Sasso Carta    = 2  -- Vince il giocatore 2
vince Sasso Forbici  = 1  -- Vince il giocatore 1
vince Carta Sasso    = 1
vince Carta Forbici  = 2
vince Forbici Sasso  = 2
vince Forbici Carta  = 1
vince _ _            = 0  -- Parità


-- Esercizi di riepilogo capitolo

-- 1) Definire un tipo PuntoCardinale con costruttori Nord, Sud, Ovest, Est.
--    Implementare: 
--    sinistra :: PuntoCardinale -> PuntoCardinale
--    destra :: PuntoCardinale -> PuntoCardinale
--    indietro :: PuntoCardinale -> PuntoCardinale
--    solo una funzione deve usare il pattern matching.

data PuntoCardinale = Nord | Sud | Ovest | Est deriving Show -- deriving Show serve per poter stampare questi valori come stringhe
sinistra :: PuntoCardinale -> PuntoCardinale
sinistra Nord  = Est
sinistra Est   = Sud
sinistra Sud   = Ovest
sinistra Ovest = Nord
destra :: PuntoCardinale -> PuntoCardinale
destra = indietro . sinistra
indietro :: PuntoCardinale -> PuntoCardinale
indietro = sinistra . sinistra


-- 2) Definire un tipo Giorno con costruttori Lun, Mar, Mer, Gio, Ven, Sab, Dom.
--    Implementare:
--    domani :: Giorno -> Giorno
--    fra :: Int -> Giorno -> Giorno -- restituisce il giorno n giorni dopo quello dato (n >= 0)
--    Ridefinire fra usando la funzione di libreria replicate senza ricorsione esplicita.

data Giorno = Lun | Mar | Mer | Gio | Ven | Sab | Dom
  deriving Show

domani :: Giorno -> Giorno
domani Lun = Mar
domani Mar = Mer
domani Mer = Gio
domani Gio = Ven
domani Ven = Sab
domani Sab = Dom
domani Dom = Lun

fra :: Int -> Giorno -> Giorno
fra 0 = id
fra n = domani . fra (n - 1)

fra_replicate :: Int -> Giorno -> Giorno
fra_replicate n = foldr (.) id (replicate n domani)
