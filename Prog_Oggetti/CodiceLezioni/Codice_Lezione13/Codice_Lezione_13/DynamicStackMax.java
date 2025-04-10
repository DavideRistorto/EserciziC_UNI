//DynamicStackMax.java
public class DynamicStackMax extends DynamicStack {
// Ereditiamo il campo top di tipo Node e aggiungiamo:
 private int max;
/* INVARIANTE di classe di DynamicStack: top punta alla cima della pila. Aggiungiamo: SE lo stack non e` vuoto, allora max contiene il massimo valore dello stack, altrimenti, se lo stack e' vuoto, il valore di max e' arbitrario */
  
// COSTRUTTORE  
public DynamicStackMax(){
  super(); 
  //Invoco il costruttore della classe superiore con 0 argomenti
  max = 0; 
  // inizializziamo il nuovo attributo, max, anche se il suo valore non ha senso quando lo stack e' vuoto. Quando lo stack e' vuoto, infatti, non consentiremo l'uso di max.
}

// NUOVO metodo get per il nuovo campo max
public int getMax(){
  assert !empty(); // se pila vuota: non corretto chiedere il massimo
  return max;
}

// OVERRIDE del metodo push(int n): inseriamo di un elemento in cima alla pila aggiornando il valore del massimo
public void push(int n){
 if (empty()) 
   max=n;
 //se la pila e' vuota il massimo e' l'elemento n appena inserito  
 else 
//altrimenti e' il massimo tra elemento inserito e il max. precedente
   max = Math.max(max, n);
 super.push(n); //invoco il push della classe superiore  
}
    
// NUOVO metodo per ricalcolare max. Verrà utilizzato nella pop(). Perché allora questo codice non lo mettiamo direttamente nella pop()? Perché violerebbe il principio di buona progettazione High Cohesion, che dice, fra le altre cose, che ogni metodo deve, se possibile, svolgere un solo task ben preciso e quello della pop() è di restituire l’elemento al top dello stack e cancellarlo, non di ricalcolare max.    
// NOTA: possiamo usare il nodo top della classe DynamicStack perche' abbiamo dichiarato top "protected" e quindi accessibile nelle classi che estendono DynamicStack (si veda più avanti per le motivazioni).    
private void resetMax(){
  if (!empty()){ //se la pila e' vuota ogni valore di max va bene
    // altrimenti ricalcolo il massimo della pila
    max = top.getElem();
    // calcolo il max tra il primo elemento della pila e gli altri;
    // per evitare di modificare l’indirizzo top della pila introduco una nuova variabile p di tipo Node con valore l’indirizzo del nodo puntato da top 
    for (Node p = top.getNext(); p != null; p = p.getNext())
     max = Math.max(max, p.getElem());
    }
  }

// OVERRIDE di pop(): rimozione di un elemento dalla cima della pila. Attenzione: puo' richiedere il ricalcolo del massimo
public int pop(){
 assert !empty();
 int n = super.pop(); //invoco pop() della classe superiore
 // Se l'elemento tolto e' il massimo allora il massimo puo' cambiare e quindi va ricalcolato.
 if (n == max) resetMax();
 return n;
}

//EREDITARIETA' - Il metodo top() e' ereditato, non deve essere riscritto: leggere l'elemento in cima alla pila non cambia il max della pila.

//OVERRIDE del metodo di conversione in stringa 
 public String toString(){
  return super.toString() + " || max= " + max + "\n";
 }
}
