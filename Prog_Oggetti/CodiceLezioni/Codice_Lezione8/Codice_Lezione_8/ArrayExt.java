//ArrayExt.java
/* La classe ArrayExt definisce array estendibili con dimensioni un valore min deciso inizialmente, oppure il doppio, il quadruplo eccetera, a seconda di quanto spazio viene richiesto.

Inoltre ArrayExt fornisce operazioni più generali, di aggiunta e rimozione di un elemento dato il suo indice. Queste operazioni mantengono l'ordine all’interno dell’array se questo esiste.
Vengono utilizzate nel caso di array ordinati, quando vogliamo
modificare l’array mantenendone l’ordinamento. */

public class ArrayExt{

  private int size;   
  private int[] vett; 
// Invariante: (0 <= size <= lunghezza vett) e (lunghezza vett>0) (ovvero parte significativa di vett: da 0 a size-1)

// METODI

public int getSize(){return size;}

/* Se min>0, il seguente costruttore costruisce un array di min elementi con size=0. Da qui in avanti, la lunghezza di vett sara`: min*(2^n), n >= 0. */
  public ArrayExt(int min){
    assert min>0 : "min non positivo = " + min;
    size = 0;
    vett = new int[min];
    assert 0<=size && size<=vett.length;
  }
  
  @Override
  public String toString(){
    String s = " size = " + size;
    for(int i=0;i<size;++i) s = s + "\n vett["+i+"]="+vett[i];
    return s;
  }
  
//Metodo di lettura dell'elemento i con 0<=i<size
  public int get(int i){
    assert 0<=i && i<size: "get su indice non in 0,...,size-1 " + i;
    return vett[i];
 }

//Metodo di scrittura dell'elemento i con 0<=i<size
  public void set(int i, int x){
     assert 0<=i && i<size: "set su indice non in 0,...,size-1 " + i;
     vett[i]=x;
  }

//Metodo per espandere l’array quando necessario
  private void extend(){
   int[] vett1 = new int[this.vett.length*2];
   //nuovo array di lunghezza doppia
   for(int i=0;i<size;++i)
    {vett1[i] = vett[i];} //trascrivo il vecchio array nel nuovo
   vett = vett1; //aggiorno l'indirizzo del campo vett
   assert 0<=size && size<=vett.length;
  }
  
//Metodo per aggiungere un elemento x nel posto 0<=i<=size, spostando di una posizione gli elementi a destra di i. Fa da push se l’inserimento viene fatto nel posto 0 dell’array.  
public void add(int i, int x){
  assert 0<=i && i<=size: "add su indice non in 0,...,size " + i;
  if (size==vett.length)  //se manca lo spazio
    this.extend(); //espando l’array
  assert size<vett.length; //controllo che ora lo spazio ci sia
  for(int j=size-1;j>=i;--j) {vett[j+1] = vett[j];} 
  //sposto avanti di una posizione gli elementi a destra di i
  //eseguo le assegnazioni nell’ordine da destra a sinistra
  vett[i] = x; //nello spazio cosi' creato aggiungo x
  ++size;    //aggiorno il numero degli elementi
  assert 0<=size && size<=vett.length;
}
  
//Rimozione della posizione 0<=i<size effettivamente nell’array. Restituisce l'elemento rimosso e quindi puo' fare da "pop".
public int remove(int i){
    assert 0<=i && i<size : "set su indice non in 0,...,size-1 " + i;
    --size; //aggiorno la dimensione
    int x = vett[i]; //salvo vett[i] in x prima di cancellarlo
    for(int j=i;j<=size-1;++j) {vett[j] = vett[j+1];}
    //sposto gli elementi a destra di i indietro di uno;
    //eseguo le assegnazioni nell’ordine da sinistra a destra
    assert 0<=size && size<=vett.length; 
    return x;
 }
}
