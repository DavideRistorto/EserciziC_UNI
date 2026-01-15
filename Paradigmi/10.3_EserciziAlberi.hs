data Tree a = Leaf | Branch a (Tree a) (Tree a) deriving Show

height :: Tree a -> Int
height Leaf = 0
height (Branch x sx dx) = 1 + max (height sx) (height dx)

size :: Tree a -> Int
size Leaf = 0
size (Branch x sx dx) = 1 + size sx + size dx  