-- Per creare una tupla è sufficiente elencarne gli elementi racchiusi tra parentesi tonde e separati da virgole:
-- Esempio:
tuple1 :: (Int, String, Bool)
tuple1 = (1, "ciao", True)
tuple2 :: (Bool, Int)
tuple2 = (False, 3)


-- Le funzioni possono accettare/restituire tuple:
-- Esempio:
addizione :: Int -> Int -> Int
addizione x y = x + y

-- Oppure versione che usa una tupla
addizioneTupla :: (Int , Int ) -> Int
addizioneTupla (x, y) = x + y

scambia :: (Int, Int) -> (Int, Int)
scambia (x,y) = (y, x)

ordina :: (Int, Int, Int) -> (Int, Int, Int)
ordina (x,y,z) | x <= y && y <= z = (x,y,z)
               | y <= x && x <= z = (y,x,z)
               | z <= x && x <= y = (z,x,y)
               | x <= z && z <= y = (x,z,y)
               | y <= z && z <= x = (y,z,x)
               | z <= y && y <= x = (z,y,x)
