//Salveremo il tutto nel file: GattoDemo.java
import java.util.Scanner; //Usiamo la classe Scanner (Java utility)
/* Nota: l’unica libreria Java che viene importata automaticamente è la java.lang, a cui appartiene, per esempio il metodo System.out.println() che adoperiamo per stampare a video. */

class Gatto { /* Le classi iniziano con la maiuscola */ 
  // Classe come generatore/"blueprint" di oggetti

  // Stato: campi dell'oggetto (a loro volta possono essere 
  // degli oggetti)

  /** Ogni classe induce un tipo oggetto che corrisponde alla classe   stessa. Per esempio, la classe Gatto induce il tipo Gatto, che può   essere usato come qualsiasi altro tipo predefinito Java: come se fosse int, double, boolean.
   */

  public String nome; 
  public String razza; 
  public int anni;
/** Le operazioni sugli oggetti della classe sono rappresentate come metodi dinamici pubblici: se senza argomenti, si scrivono:
public tipo metodo(){… …}	
Secondo una convezione ben stabilita, ariabili e metodi iniziano con la minuscola, se uniamo piu' parole dalla seconda in poi iniziano con la maiuscola. Es.: leggiInput() 
Dentro il metodo indichiamo con this l’oggetto di tipo Gatto a cui applicheremo il metodo. */
 
  private static Scanner tastiera = new Scanner(System.in); 
/** Definisco un nuovo oggetto "tastiera" di tipo Scanner, capace di 
tradurre un input in caratteri, inviato da tastiera, nella sua 
rappresentazione Java. Il metodo nextLine(); se applicato a "tastiera" richiede una riga di input da tastiera e restituisce una stringa. */

 public void leggiInput() {
//metodo dinamico: chiamandolo, chiediamo a un oggetto di tipo Gatto
//di assumere nome, razza e eta' che gli inviamo da tastiera
  System.out.println( " nome = " );
  this.nome = tastiera.nextLine(); //nome gatto che riceve il metodo
  System.out.println( " razza = " );
  this.razza = tastiera.nextLine(); //razza gatto che riceve il metodo
  System.out.println( " anni = " );
  this.anni = tastiera.nextInt(); //eta'  gatto che riceve il metodo
  tastiera.nextLine();/* consumo il return dopo il numero anni */   }
  /* si "consuma" il carattere return dopo l’ultimo dato inserito,
   in questo caso il numero degli anni */   

  public String toString(){
  /* metodo dinamico: chiamandolo, chiediamo a un oggetto di tipo Gatto di fornire   una stringa contenente i suoi dati. Possiamo abbreviare this.nome con nome, eccetera. Ogni "\n" inserisce un a capo. */ 
   return " nome  = " + nome + "\n razza = " + razza + 
       "\n anni = " + anni;
  }

 public int getEtaInAnniUmani(){
//metodo dinamico: chiamandolo, chiediamo a un oggetto di tipo
//Gatto di mandarci i suoi anni trasformati in anni corrispondenti 
//per l'uomo. Conto 11 anni ciascuno i primi due anni del gatto, 
//conto 5 anni ogni altro anno 
       if (anni <=2) 
        return anni*11; 
       else 
        return 22 + (anni-2)*5;
  }
}

/** Segue il primo esempio di un programma che usa classi definite da noi: la classe GattoDemo ha un main, quindi e' un programma, e usa la classe Gatto. La classe Gatto deve: (1) trovarsi nello stesso file del programma (e' la nostra scelta), oppure (2) trovarsi in un file di nome Gatto.java della stessa cartella ed essere public. 
La classe GattoDemo deve essere salvata nel file GattoDemo.java
Per assegnare un attributo pubblico dell’oggetto Gatto x, per esempio assegnare "anni" a 8 devo scrivere: x.anni = 8 */

public class GattoDemo { 
//Una classe e' eseguibile se ha un main, come questo:
  public static void main(String[] args) {
    Gatto tramot = new Gatto(); 
/** Il comando C x = new C(); definisce un nuovo oggetto x di tipo C 
con valori di default per gli attributi. Nel caso di un gatto: null, null, 0 per gli attributi: nome, razza, anni */

    System.out.println( "tramot prima inserimento dati" );
    // stampo i valori di default: null, null, 0
    // se c'e' la toString() in Gatto
    System.out.println(tramot); 
    System.out.println( "Inserisci dati tramot" );
    tramot.leggiInput();
    System.out.println( "Dati inseriti tramot" );
    // stampo i valori 
    System.out.println(tramot);
    //qui "tramot" abbrevia "tramot.toString()" 
    System.out.println( "eta' tramot in anni umani  " 
                         + tramot.getEtaInAnniUmani());
    
    Gatto galileo = new Gatto(); 
    /** Questo crea un nuovo oggetto di tipo Gatto con valori di  
     default null, null, 0 per gli attributi nome, razza, anni */
    System.out.println("Inserisco dati galileo dentro il programma");
    galileo.nome = "Galileo";
    galileo.razza = "Persiano";
    galileo.anni = 5;
    System.out.println(galileo); 
    //qui "galileo" abbrevia "galileo.toString()" 
 }
}
