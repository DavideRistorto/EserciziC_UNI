package Lezione_7.ES_Vacanza;

public class VacanzaInternazionale extends  Vacanza{

  private String paese;

  public VacanzaInternazionale(String luogo, Data partenza, Data ritorno, String paese){
    super(luogo, partenza, ritorno);
    this.paese = paese;
  }

  public String getPaese(){return this.paese;}
  public void setPaese(String paese){this.paese = paese;}

  @Override
  public String toString(){
    String s = super.toString() + "Paese: "+paese;
    return s;
  }
  
}
