public class DynamicStack {
 protected Node top; 
 /* Rispetto alla classe DynamicStack vista precedentemente, cambia la visibilità di top  da private a protected: visibile a tutte le classi dello stesso package, e a tutte le sottoclassi, anche in package diversi (si veda più avanti per le motivazioni).*/

 public DynamicStack(){
  top = null;
 }

 public boolean empty(){
  return top == null;
 }

 public void push(int x) {
  top = new Node(x,top);
 }

 public int pop(){
   assert !empty();
   int x = top.getElem(); 
   top = top.getNext(); 
   return x;
 }

 public int top(){
  assert !empty(); 
  int x = top.getElem();
  return x;
 }

 public String toString(){
  Node temp = top; String s = ""; 
  while (temp!=null){
   s = s + " || " + temp.getElem() + "\n"; 
   temp = temp.getNext();
  } 
  return s;
 }
}
