package Simulazione_Lab;

public class Generic {

  static final int variabileStatica = 0;
  private int attributoInt;
  private String attributoString;

  public Generic(){
    this.attributoInt = variabileStatica;
    this.attributoString = null;
  }

  public Generic(int val, String vals){
    attributoInt = val;
    attributoString = vals;
  }

  public void setAttributoInt(int val){
    this.attributoInt = val;
  }

    public void setAttributoString(String val){
    this.attributoString = val;
  }

  public int getAttributoInt(){
    return attributoInt;
  }

  public String getAttributoString(){
    return attributoString;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) return true;
    if (obj == null || getClass() != obj.getClass()) return false;
    Generic g = (Generic) obj;
    return attributoInt == g.attributoInt &&
           ((attributoString == null && g.attributoString == null) ||
            (attributoString != null && attributoString.equals(g.attributoString)));
  }

  @Override
  public String toString() {
    return "Generic{attributoInt=" + attributoInt + ", attributoString='" + attributoString + "'}";
  }


  
}
