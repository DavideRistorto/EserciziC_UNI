//Rubrica.java
public class Rubrica {
  /**
   * Invariante: (i) Una rubrica ha posizioni occupate da 0 a numContatti-1 e in
   * queste posizioni non contiene lo stesso nome (a meno di maiuscole/minuscole)
   * due volte, (ii) (0<=numContatti <= lunghezza array contatti)
   */

  private int numContatti; // all'inizio vale 0
  private Contatto[] contatti; // all'inizio vale null

  public Rubrica(int maxContatti) {
    assert (maxContatti >= 0) : "errore maxContatti negativo: " + maxContatti;
    // inizializza una rubrica con max. num. di contatti=maxContatti
    numContatti = 0;
    // all'inizio i contatti effettivi nella rubrica sono 0
    contatti = new Contatto[maxContatti];
    // IMPORTANTE: all'inizio tutti gli elementi dell’array
    // contatti(ovvero i contatti nella rubrica) hanno valore null
    /**
     * Dopo l’esecuzione del costruttore, l’oggetto di tipo Rubrica soddisfa
     * l'invariante.
     */
  }

  public int getNumContatti() {
    return numContatti;
  }

  /**
   * non diamo un metodo get per ottenere l’array dei contatti:
   * conoscendolo, un'altra classe potrebbe leggere e modificare i
   * contatti o il numContatti in modo errato (in contraddizione con l’invariante)
   */

  public String toString() { // conversione Rubrica-->Stringa
    int i = 0;
    String s = "Num. contatti = " + numContatti + "\n ";
    // concateniamo i contatti di indice da 0 fino a numContatti-1.
    /*
     * Gli altri contatti sono privi di significato,
     * non esistono dal punto di vista logico
     */
    while (i < numContatti) {
      s = s + contatti[i].toString();
      ++i;
    }
    // si noti che contatti[i].toString() chiama la toString()
    // della classe Contatto
    return s;
  }

  /**
   * Il metodo cercaIndice(n) restituisce l'unico indice i di un contatto di nome
   * n se c'e', altrimenti restituisce numContatti se non c'e'. Il metodo
   * cercaIndice(n) e' privato per evitare che le altre classi modifichino un
   * contatto, usando l'indice restituito da cercaIndice(n), con il rischio di
   * contraddire l’invariante.
   */
  private int cercaIndice(String n) {
    int i = 0;
    /*
     * Esaminiamo i contatti di indice da 0 a numContatti-1: il primo con nome n e'
     * il contatto cercato
     */
    while (i < numContatti) {
      if (contatti[i].getNome().equalsIgnoreCase(n))
        return i;
      ++i;
    }
    // L'oggetto su cui è chiamato il metodo equalsIgnoreCase()
    // è di tipo String, ed è stato restituito dalla chiamata
    // contatti[i].getNome(). Questa chiamata applica il metodo getNome()
    // su contatti[i], a sua volta un oggetto di tipo Contatto.

    // Se non troviamo n restituiamo un valore di default: numContatti
    return numContatti;
  }

  /**
   * Usando cercaIndice(n) possiamo stabilire se il nome n e' presente nella
   * rubrica
   */
  public boolean presente(String n) {
    return (cercaIndice(n) < numContatti);
  }

  /**
   * Usando cercaIndice(n) possiamo trovare quale e-mail corrisponde a un nome
   * presente nella rubrica (restituiamo "" per nome assente)
   */
  public String cercaEmail(String n) {
    int i = cercaIndice(n);
    if (i < numContatti)
      return contatti[i].getEmail();
    else
      return "";
  }

  /**
   * Controlliamo se una rubrica e' piena, cioe' se il numContatti e' uguale al
   * numero di elementi che possiamo inserire nell’array contatti
   */
  public boolean piena() {
    return (numContatti == contatti.length);
  }

  /**
   * Ora possiamo definire metodi per aggiungere, rimuovere e cambiare contatti. I
   * metodi restituiscono false quando falliscono
   */

  public boolean aggiungi(String n, String e) {
    if (presente(n))
      return false;
    // rubrica contiene n: fallimento
    if (piena())
      return false;
    // rubrica piena: fallimento
    contatti[numContatti] = new Contatto(n, e);
    // aggiungo il nuovo contatto nella prima posizione disponibile
    ++numContatti; // aggiorno il numero degli elementi
    return true; // successo
  }

  /**
   * Per rimuovere un contatto sposto l’ultimo contatto al posto del contatto
   * rimosso.
   */
  public boolean rimuovi(String n) {
    int i = cercaIndice(n);
    if (i == numContatti)
      return false;
    // il contatto manca: fallimento

    /**
     * Se invece il contatto c'e': diminuiamo di 1 il numero dei contatti
     * numContatti e scambiamo il contatto da cancellare che sta in posizione i con
     * il contatto che sta in posizione numContatti. In questo modo, il contatto che
     * era prima in posizione i non sarà più accessibile, visto che la posizione
     * numContatti rappresenta la prima posizione libera. Si noti che questa
     * cancellazione non è fisica (non si rimuove l’oggetto dalla struttura), ma
     * logica (si fa in modo che l’oggetto da cancellare non sia più raggiungibile).
     * Ovviamente questa cancellazione non preserva l’ordine dei contatti, tuttavia
     * nell’invariante non c’è scritto che la rubrica deve rispettare un certo
     * ordinamento.
     */
    --numContatti;
    contatti[i] = contatti[numContatti];
    return true; // successo
  }

  // Cerco un contatto di nome n e se lo trovo cambio il nome a n2
  public boolean cambiaNome(String n, String n2) {
    int i = cercaIndice(n), j = cercaIndice(n2);
    if ((i == numContatti) || (j < numContatti))
      return false;
    // contatto di nome n non trovato oppure contatto di nome n2
    // trovato: fallimento
    // altrimenti cambiamo il nome del contatto i da n a n2
    contatti[i].setNome(n2);
    return true;
  }

  // Cerco un contatto di nome n e se lo trovo cambio la email a e2
  public boolean cambiaEmail(String n, String e2) {
    int i = cercaIndice(n);
    if (i == numContatti)
      return false;
    // contatto di nome n non trovato: fallimento
    // altrimenti, se n e' presente modifichiamo la email
    contatti[i].setEmail(e2);
    return true;
  }
}
