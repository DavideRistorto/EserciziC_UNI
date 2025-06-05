public class TreeTest {
    public static void main(String[] args) {
        // Esempio: radice 2, sinistra foglia, destra radice -3
        Tree<Integer> t = new Branch<>(2, new Leaf<>(), new Branch<>(-3, new Leaf<>(), new Leaf<>()));
        System.out.println("Albero originale: " + t);
        Tree<Integer> t2 = t.detach(-3);
        System.out.println("Dopo detach(-3): " + t2);
    }
}

abstract class Tree<T> {
    public abstract Tree<T> detach(T x);
}

class Leaf<T> extends Tree<T> {
    public Tree<T> detach(T x) {
        return this;
    }
    public String toString() {
        return "Leaf";
    }
}

class Branch<T> extends Tree<T> {
    private T elem;
    private Tree<T> left;
    private Tree<T> right;

    public Branch(T elem, Tree<T> left, Tree<T> right) {
        this.elem = elem;
        this.left = left;
        this.right = right;
    }

    public Tree<T> detach(T x) {
        if(elem != null && elem.equals(x)) {
            // Se l'elemento da staccare è la radice, ritorna un Leaf
            return new Leaf<>();
        }
        left = left.detach(x);
        right = right.detach(x);
        return this;
    }
    public String toString() {
        return "Branch(" + elem + ", " + left + ", " + right + ")";
    }
}
