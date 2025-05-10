package Lezione_5;

public class DynamicQueueMaxSize extends DynamicQueue{

  private int maxValue;

  public int getMaxValue() {return maxValue;}


  public void setMaxValue(){
    int max = Integer.MIN_VALUE;
    Node cur = getFirst();
    while(cur != null){
      if(cur.getElem() > max){
        max = cur.getElem();
      }
      cur = cur.getNext();
    }
    maxValue = max;
  }

  @Override
  public void enqueue(int x){
    super.enqueue(x);
    // aggiorna il valore massimo
    setMaxValue();
  }

  @Override
  public int dequeue(){
    int elem = super.dequeue();
    // aggiorna il valore massimo
    setMaxValue();
    return elem;
  }

  public static void main(String[] args) {
    DynamicQueueMaxSize queue = new DynamicQueueMaxSize();

    // Test enqueue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(5);
    System.out.println("Max value after enqueues: " + queue.getMaxValue()); // Should print 20

    // Test dequeue
    queue.dequeue();
    System.out.println("Max value after first dequeue: " + queue.getMaxValue()); // Should print 20

    queue.dequeue();
    System.out.println("Max value after second dequeue: " + queue.getMaxValue()); // Should print 5

    queue.dequeue();
    System.out.println("Max value after third dequeue: " + queue.getMaxValue()); // Should handle empty queue gracefully
  }



}
