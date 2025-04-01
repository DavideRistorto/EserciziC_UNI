

public class GenericStack<T> {
  private GenericNode<T> first;

  public GenericStack(){first = null;}

  public boolean empty(){ return first == null; }

  /* Al posto di GenericNode<T> posso scrivere GenericNode<>, purche' il compilatore Java sia in grado di dedurre in modo unico il valore T */
  public void push(T elem){
     first = new GenericNode<>(elem, first);
  }

 public T pop(){
   assert !empty(): "pop on empty stack";
   T x = first.getElem();
   first = first.getNext();
   return x;
 }

 public String toString(){
   GenericNode<T> p = first; String s = ""; 
   while(p!=null) {
    s = s + p.getElem() + " ";
    p=p.getNext();
   }
   return s;
 }    
}
