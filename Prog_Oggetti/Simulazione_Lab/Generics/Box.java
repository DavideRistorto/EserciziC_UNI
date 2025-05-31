package Simulazione_Lab.Generics;

public class Box <T>{
	
	private T item;
	
	public Box(T t){
		item = t;
	}
	
	public void setItem(T t){
		item = t;
	}
	
	public T getItem(){
		return item;
	}
	
	public boolean isEmpty(){
		return item == null;
	}
	
	
  
}
