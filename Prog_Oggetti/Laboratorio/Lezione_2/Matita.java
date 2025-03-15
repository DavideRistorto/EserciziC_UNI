public class Matita {

  private final static int MIN_STELO = 10;

  private final static int MAX_STELO = 20;

  private final static int MAX_PUNTA = 5;

  private int stelo;

  private int punta;

  public Matita(int stelo, int punta){
    assert stelo >= MIN_STELO && stelo <= MAX_STELO;
    assert punta >= 0 && punta <= MAX_PUNTA;
    this.stelo = stelo;
    this.punta = punta;
  }

  public Matita(int stelo){
    assert stelo >= MIN_STELO && stelo <= MAX_STELO;
    this.stelo = stelo;
    this.punta = MAX_PUNTA;
  }

  public int getStelo(){
    return stelo;
  }

  public int getPunta(){
    return punta;
  }

  public boolean disegna(){
    if(punta >= 1){
      punta = 1;
      return true;
    }
    return false;
  }

  public boolean tempera(){
    if(stelo <= MIN_STELO) return false;
    stelo --;
    if(punta < MAX_STELO){
      punta++;
    }
    return  true;
  }

}