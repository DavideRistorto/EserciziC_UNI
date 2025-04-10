//DynamicStackSize.java
public class DynamicStackSize extends DynamicStackMax {
  private int size; 
  // Aggiunta all’INVARIANTE di classe: 
  // "size" = numero elementi sullo stack

  //COSTRUTTORE 
public DynamicStackSize(){
   super(); 
   //Invoco il costruttore della classe superiore:0 argomenti
    size = 0;
 }

// NUOVO metodo get() per il nuovo campo size
public int getSize() {
  return size; 
}

// OVERRIDE del metodo push(): inserimento elemento in cima alla pila
public void push(int n) {
  super.push(n); //invoco il metodo push()della classe superiore
  size++;        //aggiorno il numero degli elementi
 }

// OVERRIDE del metodo pop: rimozione elemento dalla cima della pila
public int pop(){
 assert !empty();
 size--;             //aggiorno il numero degli elementi
 return super.pop(); //invoco il metodo pop() della classe superiore
}

//EREDITA' - top() viene ereditato e non deve essere riscritto: 
//leggere l'elemento in cima alla pila non cambia il size della pila.

//OVERRIDE del metodo di conversione in stringa 
public String toString(){
  return super.toString() + " || size = " + size + "\n";
 }
}
