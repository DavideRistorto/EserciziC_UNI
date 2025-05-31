package Lezione_5;

public class DynamicQueueTest {
    public static void main(String[] args) {
        DynamicQueue queue = new DynamicQueue();
        System.out.println("Coda vuota? " + queue.isEmpty());
        
        // Enqueue di alcuni elementi
        queue.enqueue(new Node(10, null));
        queue.enqueue(new Node(20, null));
        queue.enqueue(new Node(30, null));
        System.out.println("Coda dopo enqueue: " + queue);
        System.out.println("Size: " + queue.size());
        System.out.println("Front: " + queue.front());
        System.out.println("Contiene 20? " + queue.contains(20));
        System.out.println("Contiene 40? " + queue.contains(40));
        
        // Dequeue
        int val1 = queue.dequeue();
        System.out.println("Dequeue: " + val1);
        System.out.println("Coda dopo dequeue: " + queue);
        System.out.println("Size: " + queue.size());
        
        // Dequeue fino a svuotare la coda
        queue.dequeue();
        queue.dequeue();
        System.out.println("Coda dopo svuotamento: " + queue);
        System.out.println("Coda vuota? " + queue.isEmpty());
    }
}
