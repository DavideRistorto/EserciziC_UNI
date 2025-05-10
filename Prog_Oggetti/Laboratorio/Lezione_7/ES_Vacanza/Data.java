package Lezione_7.ES_Vacanza;

public class Data {

  private int giorno;
  private int mese;
  private int anno;

  public Data(int giorno, int mese, int anno){
    assert giorno > 0 && giorno <= 31;
    assert mese > 0 && mese < 13;
    assert anno > 2024 && anno < 3000;
    this.giorno = giorno;
    this.mese = mese;
    this.anno = anno;
  }

  private int getGiorno() {return giorno;}
  private int getMese() {return mese;}
  private int getAnno() {return anno;}

  @Override
  public String toString() {
    return String.format("%02d/%02d/%04d", giorno, mese, anno);
  }

  public int differenza(Data d) {
    int differenza = 0;
    if (anno == d.getAnno()) {
      if (mese == d.getMese()) {
        differenza = d.getGiorno() - giorno;
      } else {
        differenza = (d.getMese() - mese) * 30 + (d.getGiorno() - giorno);
      }
    } else {
      differenza = (d.getAnno() - anno) * 365 + (d.getMese() - mese) * 30 + (d.getGiorno() - giorno);
    }
    return differenza;
  }

  
}
