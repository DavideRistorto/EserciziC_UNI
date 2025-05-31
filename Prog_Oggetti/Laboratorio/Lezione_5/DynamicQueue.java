package Lezione_5;

public class DynamicQueue {
	
	private Node first;
	private Node last;
	
	public DynamicQueue(){
		this.first = null;
		this.last = null;
	}
	
	@Override
	public String toString(){
		String s = "";
		Node c = first;
		while(c != null){
			s += c.getElem() + " ";
			c = c.getNext();
		}
		return s;
	}
	
	public void enqueue(Node n){
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
	
	public int dequeue(){
		if(first == null) return -1;
		//salvo il valore e shifto il first
		int val = first.getElem();
		first = first.getNext();
		return val;
	}
	
	public int size(){
		int counter = 0;
		Node c = first;
		while(c != null){
			counter++;
			c = c.getNext();
		}
		return counter;
	}
	
	public int front(){
		return first != null ? first.getElem() : 0;
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	public boolean contains(int x){
		if(first == null) return false;
		
		Node c = first;
		while(c != null){
			if(c.getElem() == x){
				return true;
			}
			c = c.getNext();
		}
		return false;
	}
	
}
