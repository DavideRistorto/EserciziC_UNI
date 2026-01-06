--Scrivi una funzione che prende due liste di Int e restituisce una lista di stringhe che per ogni coppia corrispondente indica se il primo elemento è maggiore del secondo.
--Esempio: [3,5,2] [1,5,4] => ["3 è maggiore di 1", "5 è minore o uguale a 5", "2 è minore o uguale a 4"]
maggioreStringa :: [Int] -> [Int] -> [String]
maggioreStringa xs ys = map (\(a,b) -> show a ++ " e' maggiore di "++ show b) (filter (\(a,b) -> a > b) (zip xs ys))

--La funzione zip in Haskell prende due liste e le combina in una lista di coppie, accoppiando gli elementi corrispondenti delle due liste. 
--Se una lista è più corta, la lunghezza della lista risultante sarà quella della lista più corta.
accoppia :: [Int] -> [Int] -> [(Int, Int)]
accoppia xs ys = zip xs ys

--Somma di liste elemento per elemento:
--Scrivi una funzione che prende due liste di interi e restituisce una lista con la somma degli elementi corrispondenti.
sommaListe :: [Int] -> [Int] -> [Int]
-- sommaListe xs ys = zipWith (+) xs ys
sommaListe xs ys = map (\(a, b) -> a + b) (zip xs ys)

--Lista di massimi tra elementi corrispondenti:
--Scrivi una funzione che prende due liste di Int e restituisce una lista con il massimo tra ogni coppia di elementi.
maxCoppia :: [Int] -> [Int] -> [Int]
--maxCoppia xs ys = zipWith max xs ys
maxCoppia xs ys = map (\(a,b) -> max a b)   (zip xs ys)

--Lista di booleani che indica se gli elementi corrispondenti sono uguali:
--Scrivi una funzione che prende due liste di Int e restituisce una lista di Bool che indica se gli elementi nelle stesse posizioni sono uguali
uguali :: [Int] -> [Int] -> [Bool]
uguali xs ys = zipWith (==) xs ys
--uguali xs ys = map (\(a,b) -> a == b) (zip xs ys)

--prende due liste di Int, crea una lista di coppie, 
--filtra solo le coppie in cui la somma è pari, e restituisce una lista con la somma di queste coppie.
sommaPariCoppie :: [Int] -> [Int] -> [Int]
--sommaPariCoppie xs ys = filter even (zipWith (+) xs ys)
sommaPariCoppie xs ys = filter even (map(\(a,b) -> a+b) (zip xs ys))


--funzione che prende due liste di Int, crea una lista di coppie, filtra solo le coppie in cui il primo elemento è maggiore del secondo
--e restituisce una lista con la differenza tra questi elementi.
differenzaMaggiori :: [Int] -> [Int] -> [Int]
--differenzaMaggiori xs ys = map (uncurry (-)) (filter (uncurry (>)) (zip xs ys))
differenzaMaggiori xs ys = map (\(a, b) -> a - b) (filter (\(a, b) -> a > b) (zip xs ys))

--unzione che prende due liste di Int, crea una lista di coppie, 
prodottoDispari :: [Int] -> [Int] -> [Int]
prodottoDispari xs ys = map (uncurry (*)) (filter (\(a,b) -> even a || even b) (zip xs ys))


--Scrivi una funzione che prende due liste di Int e restituisce una lista di tuple (somma, prodotto) per ogni coppia corrispondente.
sommaEProdotto :: [Int] -> [Int] -> [(Int, Int)]
sommaEProdotto xs ys = map(\(a,b) -> (a+b, a*b))(zip xs ys)

--Scrivi una funzione che prende due liste di String e restituisce una lista di Bool che indica se le stringhe corrispondenti hanno la stessa lunghezza.
stessaLunghezza :: [String] -> [String] -> [Bool]
stessaLunghezza xs ys = map(\(a,b) -> length a == length b)(zip xs ys)

--Scrivi una funzione che prende due liste di Int e restituisce una lista con la somma degli elementi corrispondenti solo se entrambi sono dispari.
sommaDispari :: [Int] -> [Int] -> [Int]
sommaDispari xs ys = map (\(a,b) -> a+b) (filter (\(a,b) -> odd a && odd b)(zip xs ys))