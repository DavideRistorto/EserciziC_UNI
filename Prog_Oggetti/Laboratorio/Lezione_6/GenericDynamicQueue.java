package Lezione_6;

public class GenericDynamicQueue <T> {
	
	private GenericNode<T> first;
	private GenericNode<T> last;
	
	public GenericDynamicQueue(){
		first = null;
		last = null;
	}
	
	@Override
	public String toString(){
		String s = "";
		GenericNode<T> cur = first;
		while(cur != null){
			s += cur.getElem() + " ";
			cur = cur.getNext();
		}
		return s;
	}
	
	public void enqueue(GenericNode<T> n){
		//coda vuota
		if(first == null){
			first = n;
			last = first;
		}else{
			//metto il nodo alla fine e diventa il nuovo last
			last.setNext(n);
			last = n;
		}
	}
	
	public T dequeue(){
		if(first == null) return null;
		//salvo il valore e shifto il first
		T val = first.getElem();
		first = first.getNext();
		return val;
	}
	
	public int size(){
		int counter = 0;
		GenericNode<T> c = first;
		while(c != null){
			counter++;
			c = c.getNext();
		}
		return counter;
	}
	
	public T front(){
		return first != null ? first.getElem() :  null;
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	public boolean contains(int x){
		if(first == null) return false;
		
		GenericNode<T> c = first;
		while(c != null){
			if(c.getElem().equals(x)){
				return true;
			}
			c = c.getNext();
		}
		return false;
	}
}
