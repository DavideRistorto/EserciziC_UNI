data Tree a = Leaf | Branch a (Tree a) (Tree a) deriving Show

height :: Tree a -> Int
height Leaf = 0
height (Branch x sx dx) = 1 + max (height sx) (height dx)

-- (Branch 1 (Branch 2 (Branch 4 Leaf Leaf) (Branch 5 Leaf Leaf)) (Branch 3 Leaf Leaf))
size :: Tree a -> Int
size Leaf = 0
size (Branch x sx dx) = 1 + size sx + size dx

countLeaves :: Tree a -> Int
countLeaves Leaf = 1
countLeaves (Branch _ sx dx) = countLeaves sx + countLeaves dx

contains :: Eq a => a -> Tree a -> Bool
contains a Leaf = False
contains a (Branch x sx dx) = x == a || contains a sx || contains a dx

mirror :: Tree a -> Tree a
mirror Leaf = Leaf
mirror (Branch a sx dx) = Branch a (mirror dx) (mirror sx)

inorder :: Tree a -> [a]
inorder Leaf = []
inorder (Branch x sx dx) = inorder sx ++ [x] ++ inorder dx

isBalanced :: Tree a -> Bool
isBalanced Leaf = True
isBalanced (Branch x sx dx) = if abs (height sx - height dx) > 1 then False else True && isBalanced sx && isBalanced dx


data Treee a = Empty | Node a [Treee a]
elements :: Treee a -> [a]
elements Empty = []
elements (Node x xs) = x : concatMap elements xs

ne :: Treee a -> Bool
ne Empty = False
ne (Node _ _) = True

normalize :: Treee a -> Treee a
normalize Empty = Empty
normalize (Node x xs) = Node x (filter ne (map normalize xs))