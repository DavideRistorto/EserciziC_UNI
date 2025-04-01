
class GenericPair<T,S> {
 private T first; private S second; 
 
 public GenericPair(T first, S second)
 {this.first = first; this.second = second;}

 public T getFirst() { return first;  }
 public S getSecond(){ return second; }
    
 public void setFirst(T first)  { this.first = first;   }
 public void setSecond(S second){ this.second = second; }

 public String toString()
  {return "(" + first.toString() + "," + second.toString() + ")";}
}


public class Test{
 public static void provaS(GenericPair<String,String> p){
  // questo metodo si aspetta un GenericPair composto da due oggetti String
  System.out.println(p);
  System.out.println();
  //siccome si può assumere che il tipo di secondo di p sia String dal tipo del parametro p nella firma del metodo, la seguente istruzione sembra safe, ma non se si passa un GenericPair come avviene nel main() (si veda la variabile p6). In questo caso avrei un errore di compilazione che dipende dal codice client!!!
  //char c = p.secondo.charAt(0);
   
 }
    
 public static void main(String[] args){
  GenericPair p6 = new GenericPair("Mario",3);
  // non abbiamo indicato i valori delle variabili di tipo
  provaS(p6);
  // il compilatore accetta questa chiamata a provaS() anche se il tipo vero di p6 è GenericPair<String,Integer>, non GenericPair<String,String>!
 }
}

