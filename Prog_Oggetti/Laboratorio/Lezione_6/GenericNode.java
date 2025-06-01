package Lezione_6;

public class GenericNode <T> {
	
	private T elem;
	private GenericNode<T> next;
	
	public GenericNode(T e, GenericNode<T> n){
		elem = e;
		next = n;
	}
	
	public T getElem(){return elem;}
	public GenericNode<T> getNext(){return next;}
	public void setElem(T e){elem = e;}
	public void setNext(GenericNode<T> n){next = n;}

}
