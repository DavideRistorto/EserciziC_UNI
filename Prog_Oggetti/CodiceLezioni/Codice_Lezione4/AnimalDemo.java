//Inseriamo tutto nel file AnimalDemo.class
class Animal { //classe non eseguibile 
  /** Introduciamo una classe per sperimentare costruttori e metodo equals. Gli attributi sono private. */
  private String nome;
  private int eta;
  private double peso;
  
  /** (i) Il primo costruttore assegna valori di default privi di interesse (ma scelti dal programmatore) */
  public Animal(){nome = "nessun nome"; eta=0; peso=0;}
  
  /** Il secondo costruttore produce un oggetto a partire da informazioni rilevanti */
  public Animal(String n, int e, double p)
   {nome=n; eta=e; peso=p;}
  
  /** (ii) Metodi set e get */
  public void setAnimal(String n, int e, double p)
   {nome = n; eta=e; peso=p;}
  
  public String getNome(){return nome;}
  public int    getEta() {return eta;}
  public double getPeso(){return peso;}
  
  public void setNome(String n){nome = n;}
  
  public void setEta(int e){
    if (e>=0) eta = e;
    else System.out.println("L'eta' deve essere non negativa");
  }
  
  public void setPeso(double p){
    if (peso>=0) peso=p; 
    else System.out.println("Il peso deve essere non negativo");
  }
  
  /** Metodo di conversione animale --> stringa */
  public String toString()
   {return " nome " + nome + "\n eta'  " + eta + "\n peso " + peso;}

  /** (iii) Metodo che assegna a un animale x gli attributi di un altro animale y. */
  public void assegna(Animal altroAnimale){
    this.nome = altroAnimale.nome;
    this.eta = altroAnimale.eta; 
    this.peso = altroAnimale.peso; 
  }
 /** Questo metodo di assegnazione è diverso dall’assegnare direttamente x = y. 
Con x = y: x e y occupano lo stesso spazio di memoria, sono lo 
stesso oggetto e ogni modifica fatta a x si ripercuote su y. */

 /** (iv) Metodo equals che controlla se due animali hanno gli stessi valori di attributi. Uso il metodo dinamico s.equalsIgnoreCase(s'): controlla se s, s' sono uguali ignorando la differenza maiuscole/minuscole. Qui s e s' sono gli oggetti legati rispettivamente a this (ovvero l’oggetto su cui chiamiamo il metodo) e ad altroAnimale (passato come parametro). Il metodo equals() compare in tutte le classi Java, e può essere ridefinito da noi. Quando definite una classe, pensate sempre se è il caso di ridefinire un tale metodo.*/
 public boolean equals(Animal altroAnimale){
   return 
    (this.nome.equalsIgnoreCase(altroAnimale.nome))      
    && 
    (this.eta  == altroAnimale.eta) 
    && 
    (this.peso == altroAnimale.peso);
  }
}

 /* Verifichiamo che essere uguali e' diverso dall'avere lo stesso indirizzo. Usiamo la classe AnimalDemo e il file AnimalDemo.java */
public class AnimalDemo { //classe eseguibile pubblica
  public static void main(String[] args){
   Animal tramot = new Animal("Tramot",10,5.0); //valori significativi
   Animal galileo = new Animal(); //valori di default
    
   System.out.println( "1. Tramot" );
   System.out.println(tramot); 
   // sta per: System.out.println(tramot.toString());
   System.out.println( "2. Galileo" );
   System.out.println(galileo); 
   /** All'inizio i due oggetti sono diversi */
   System.out.println("3. Tramot e' uguale a Galileo?"+tramot.equals(galileo)); 
   /** Se assegno il primo al secondo attributo per attributo 
  diventano uguali attributo per attributo. */
   System.out.println("4. Assegno gli attributi di Tramot a Galileo ");
   galileo.assegna(tramot); 
   System.out.println("5. Tramot e' uguale a Galileo?"+tramot.equals(galileo)); 
   //Vero: stessi attributi
   System.out.println("6. Tramot == Galileo? "+(tramot==galileo));
   //Falso: diversi indirizzi
 }
}
