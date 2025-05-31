package Lezione_5;

public class Node {
	
	private int elem;
	private Node next;
	
	public Node(int e, Node n){
		elem = e;
		next = n;
	}
	
	public int getElem(){return elem;}
	public Node getNext(){return next;}
	public void setElem(int e){elem = e;}
	public void setNext(Node n){next = n;}
}
