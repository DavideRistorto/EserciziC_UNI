package Lezione_5;

public class Node {

  private int elem;
  private Node next;

  
  public Node(int elem){
    this.elem = elem;
    this.next = null;
  }

  public int getElem(){
    return this.elem;
  }

  public Node getNext(){
    return this.next;
  }

  public void setElem(int elem){
    this.elem = elem;
  }

  public void setNext(Node next){
    this.next = next;
  }
}
