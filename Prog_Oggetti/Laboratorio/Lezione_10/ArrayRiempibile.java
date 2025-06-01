public class ArrayRiempibile {
  private int[] elementi;
  private boolean[] occupazione;

  public ArrayRiempibile(int l) {
    assert (l > 0):  "errore, lunghezza non positiva : " + l;
    elementi = new int[l];
    occupazione = new boolean[l];
  }

  public String toString() {
    String s = "elementi:\n";
    for (int i = 0; i < elementi.length; i++ )
      s = s + " " + elementi[i];
    s = s + "\nmodificato:\n";  
    for (int i = 0; i < elementi.length; i++ )
      s = s + " " + occupazione[i];
    return s;
  }

  public void inserire(int i, int v) {
    assert (i >=0) && (i < elementi.length):  "indice "  + i + " fuori limite";
    assert occupazione[i] == false:  "indice "  + i + " gia` occupata";
    elementi[i] = v;
    occupazione[i] = true;
  }

  public boolean controllarePieno() {
    int i = 0;
    boolean trovatoVuoto = false;
    while (i < elementi.length && !trovatoVuoto) {
      if (occupazione[i] == false)
        trovatoVuoto = true;
      i++;
    }
    return !trovatoVuoto;
  }

  public int calcolareSomma() {
    assert (this.controllarePieno()): "calcolare somma su un array non pieno non e` possibile";
    int somma = 0;
    for (int i = 0; i < elementi.length; i++ )
      somma += elementi[i];
    return somma;
  }

}