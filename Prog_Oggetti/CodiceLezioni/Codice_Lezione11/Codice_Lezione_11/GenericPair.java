//GenericPair.java

/* Permette di creare oggetti "coppia di elementi (x,y)" di tipo rispettivamente T e S, tipi non noti a priori. Sarà il codice client che al momento in cui eseguiamo una new istanzierà le variabili di classe con delle classi (tipi) specifiche. 
Trovate degli esempi nel file TestGenericPair.java. La classe coppia viene detta una classe parametrica, i suoi parametri sono i parametri di tipo T e S. Si dice anche che è una classe polimorfa, perché può assumere più ruoli a seconda della scelta di T e S, favorendo il riuso del codice.
*/

public class GenericPair<T,S> {
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
