package Lezione_6;

public class GenericDynamicQueue<T> {

  private GenericNode<T> first;
  private GenericNode<T> last;

  public GenericDynamicQueue() {
    first = null;
    last = null;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    GenericNode<T> current = first;
    sb.append("[");
    while (current != null) {
      sb.append(current.getElem());
      if (current.getNext() != null) {
        sb.append(", ");
      }
      current = current.getNext();
    }
    sb.append("]");
    return sb.toString();
  }

  public void enqueue(T x) {
    GenericNode<T> node = new GenericNode<>(x);
    // caso coda vuota
    if (last == null) {
      last = node;
      first = node;
      return;
    }
    last.setNext(node);
    last = node;
  }

  public T dequeue() {
    if (first == null) {
      throw new IllegalStateException("Queue is empty");
    }
    GenericNode<T> current = first;
    first = first.getNext();
    return current.getElem();
  }

  public int size() {
    int count = 0;
    GenericNode<T> cur = first;
    while (cur != null) {
      count++;
      cur = cur.getNext();
    }
    return count;
  }

  public boolean empty() {
    return first == null;
  }

  public boolean contains(T x) {
    // caso coda vuota
    if (first == null) {
      return false;
    }
    GenericNode<T> cur = first;
    while (cur != null) {
      if (cur.getElem().equals(x)) {
        return true;
      }
      cur = cur.getNext();
    }
    return false;
  }

  public T front() {
    if (first == null) {
      throw new IllegalStateException("Queue is empty");
    }
    return first.getElem();
  }

  public static void main(String[] args) {
    GenericDynamicQueue<Integer> queue = new GenericDynamicQueue<>();
    System.out.println("Testing GenericDynamicQueue with Integer type:");

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    System.out.println("Queue after enqueuing 10, 20, 30: " + queue);
    System.out.println("Queue size: " + queue.size());
    System.out.println("Queue front: " + queue.front());

    System.out.println("Dequeue: " + queue.dequeue());
    System.out.println("Queue after dequeue: " + queue);

    System.out.println("Contains 20: " + queue.contains(20));
    System.out.println("Contains 40: " + queue.contains(40));

    System.out.println("Dequeue: " + queue.dequeue());
    System.out.println("Dequeue: " + queue.dequeue());

    System.out.println("Queue empty: " + queue.empty());
  }
}
