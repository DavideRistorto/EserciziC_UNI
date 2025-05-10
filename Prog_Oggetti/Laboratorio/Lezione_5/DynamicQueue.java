package Lezione_5;

public class DynamicQueue {

  private Node first;

  private Node last;

  public DynamicQueue(){
    first = null;
    last = null;
  }

  public Node getFirst(){
    return first;
  }

  public Node getLast(){
    return last;
  }

  @Override
  public String toString() {
    String s = "";
    Node cur = first;
    while(cur != null){
      s = s+" " + cur.getElem();
      cur = cur.getNext();
    }
    return s;
  }

  public void enqueue(int x) {
    Node node = new Node(x);
    // caso coda vuota
    if (last == null) {
      last = node;
      first = node;
      return;
    }
    last.setNext(node);
    last = node;       
  }

  public int dequeue(){
    Node current = first;
    first = first.getNext();
    return current.getElem();
  }

  public int size(){
    int count = 0;
    Node cur = first;
    while(cur != null){
      count++;
      cur = cur.getNext();
    }
    return count;
  }

  public boolean empty(){
    return first == null;
  }

  public boolean contains(int x){
    //caso coda vuota
    if(first == null){
      return false;
    }
    Node cur = first;
    while(cur != null){
      if(cur.getElem() == x){
        return true;
      }
      cur = cur.getNext();
    }
    return false;
  }

  public int front(){
    if(first == null){
      return -1; //caso coda vuota
    }
    return first.getElem();
  }

  public static void main(String[] args){
    DynamicQueue q = new DynamicQueue();
    System.out.println( "q = {17,42,4} " );
    q.enqueue(17); q.enqueue(42); q.enqueue(4);
    System.out.print(q);
    System.out.println( "\nq.empty() = " + q.empty());
    /** Aggiungete queste righe se avete realizzato "contains"
   System.out.println( "q.contains(4) = " + q.contains(4));
   //true
   System.out.println( "q.contains(40) = " +
   q.contains(40));//false
   */
    System.out.println("q.size() = " + q.size()); // stampa 3
    System.out.println("q.front()= " + q.front()); // stampa 17
    System.out.println(q.dequeue()); //toglie e stampa 17
    System.out.println(q.dequeue()); //toglie e stampa 42
    System.out.println(q.dequeue()); //toglie e stampa 4: coda vuota
    // gli elementi vengono stampati nello stesso ordine in cui
    // sono stati inseriti, dal momento che la coda e' una
    // struttura FIFO (First-In-First-Out)
    System.out.println( "q.empty() = " + q.empty());
    /** Questo comando deve far scattare un "assert":
    q.front();*/
   }
  
}
