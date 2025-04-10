package Lezione_6;

public class GenericSet <T> {

  private GenericNode<T> first;
  private int size;

  public GenericSet(){
    first = null;
    size = 0;
  }

  public int size(){
    return size;
  }

  public boolean empty(){
    return size == 0;
  }

  public void addElem(T elem){
    //elem gia presente
    if(contains(elem)) return;
    GenericNode<T> newNode = new GenericNode<>(elem);
    newNode.setNext(first);
    first = newNode;
    size++;
  }

  public void remove(T elem){
    // elem non presente
    if (!contains(elem)) return;
    // caso in cui l'elemento da rimuovere è il primo
    if (first.getElem().equals(elem)) {
        first = first.getNext();
        size--;
        return;
    }
    // caso in cui l'elemento da rimuovere è altrove nella lista
    GenericNode<T> cur = first;
    while (cur.getNext() != null) {
        if (cur.getNext().getElem().equals(elem)) {
            cur.setNext(cur.getNext().getNext());
            size--;
            return;
        }
        cur = cur.getNext();
    }
  }

  public boolean contains(T elem){
    GenericNode<T> cur = first;
    while(cur != null){
        if(cur.getElem().equals(elem)){
            return true;
        }
        cur = cur.getNext(); // Avanza al nodo successivo
    }
    return false;
  }

  public boolean uguali(GenericSet<T> set){
    if(set.size() != size) return false;

    GenericNode<T> cur = first;
    while(cur != null){
      if(!set.contains(cur.getElem())){
        return false;
      }
      cur = cur.getNext();
    }
    return true;
  }

  public GenericSet<T> intersection(GenericSet<T> set) {
    GenericSet<T> result = new GenericSet<>();
    //prendi i nodi in comune tra i 2 set
    GenericNode<T> cur = first;
    while (cur != null) {
        if (set.contains(cur.getElem())) {
            result.addElem(cur.getElem());
        }
        cur = cur.getNext();
    }
    return result;
  }

  @Override
  public String toString(){
    String s = "";
    GenericNode<T> cur = first;
    while(cur != null){
      s = s+ " "+cur.getElem();
      cur = cur.getNext();
    }
    return s;
  }

  public static void main(String[] args) {
    // Creazione di due set generici
    GenericSet<Integer> set1 = new GenericSet<>();
    GenericSet<Integer> set2 = new GenericSet<>();

    // Aggiunta di elementi al primo set
    set1.addElem(1);
    set1.addElem(2);
    set1.addElem(3);
    System.out.println("Set1: " + set1);
    // Aggiunta di elementi al secondo set
    set2.addElem(3);
    set2.addElem(4);
    set2.addElem(5);
    System.out.println("Set2: " + set2);

    // Test del metodo contains
    System.out.println("Set1 contiene 2? " + set1.contains(2));
    System.out.println("Set2 contiene 2? " + set2.contains(2));

    // Test del metodo remove
    set1.remove(2);
    System.out.println("Set1 dopo aver rimosso 2: " + set1);

    // Test del metodo uguali
    System.out.println("Set1 e Set2 sono uguali? " + set1.uguali(set2));

    // Test del metodo intersection
    GenericSet<Integer> intersection = set1.intersection(set2);
    System.out.println("Intersezione di Set1 e Set2: " + intersection);

    // Test del metodo empty
    System.out.println("Set1 è vuoto? " + set1.empty());
    System.out.println("Set2 è vuoto? " + set2.empty());

    // Test del metodo size
    System.out.println("Dimensione di Set1: " + set1.size());
    System.out.println("Dimensione di Set2: " + set2.size());
}
  
}
