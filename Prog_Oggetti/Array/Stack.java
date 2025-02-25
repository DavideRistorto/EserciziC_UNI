import java.util.Scanner;

public class Stack {

  // private perché non voglio permettere all' utente di modificare direttamente
  // lo stack
  private int stack[] = new int[100];
  private int size = 0;

  public void push(int val) {
    stack[size] = val;
    size++;
  }

  public int pop() {
    size--;
    return stack[size];
  }

  public String toString() {
    StringBuilder ret = new StringBuilder("Elementi dello stack: ");
    for (int i = 0; i < size; i++) {
      ret.append(stack[i]);
      if (i < size - 1) {
        ret.append(", ");
      }
    }
    return ret.toString();
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Stack pila = new Stack();
    System.out.println("Inserisci due valori interi: ");
    int val = scanner.nextInt();
    pila.push(val);
    val = scanner.nextInt();
    pila.push(val);
    System.out.println(pila);
    System.out.println("elemento rimosso dopo la pop: " + pila.pop());
    scanner.close();
  }
}