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
	
		
	public boolean contains(T elem){
		GenericNode<T> cur = first;
		while(cur != null){
			if(cur.getElem().equals(elem)){
				return true;
			}
			cur = cur.getNext();
		}
		return false;
	}
	
	public void addElem(T elem){
		//non aggiungo elemento perchè giò presente
		if(contains(elem)) return;
		
		GenericNode <T> newNode = new GenericNode<>(elem, null);
		if(first == null){
			first = newNode;
		}else{
			//metto il nuovo nodo in cima
			newNode.setNext(first);
			first = newNode;
		}
		size++;
	}
	
	public void remove(T elem){
		//non rimuovo elemento perchè non presente
		if(!contains(elem)) return;
		// caso in cui il primo nodo contiene l'elemento
		if(first != null && first.getElem().equals(elem)) {
			first = first.getNext();
			size--;
			return;
		}
		// caso generale
		GenericNode<T> prev = first;
		GenericNode<T> cur = first != null ? first.getNext() : null;
		while(cur != null){
			if(cur.getElem().equals(elem)){
				prev.setNext(cur.getNext());
				size--;
				return;
			}
			prev = cur;
			cur = cur.getNext();
		}
	}
	
	public boolean equalsTo(GenericSet<T> set){
		if(set.size != size) return false;
		
		GenericNode<T> cur = first;
		while(cur != null){
			if(!set.contains(cur.getElem())){
				return false;
			}
			cur = cur.getNext();
		}
		return true;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("{");
		GenericNode<T> cur = first;
		while (cur != null) {
			sb.append(cur.getElem());
			if (cur.getNext() != null) {
				sb.append(", ");
			}
			cur = cur.getNext();
		}
		sb.append("}");
		return sb.toString();
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
    System.out.println("Set1 e Set2 sono uguali? " + set1.equalsTo(set2));

    // Test del metodo empty
    System.out.println("Set1 è vuoto? " + set1.empty());
    System.out.println("Set2 è vuoto? " + set2.empty());

    // Test del metodo size
    System.out.println("Dimensione di Set1: " + set1.size());
    System.out.println("Dimensione di Set2: " + set2.size());
}
  
}
