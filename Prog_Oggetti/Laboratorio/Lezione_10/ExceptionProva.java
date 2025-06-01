package Lezione_10;

public class ExceptionProva extends IllegalArgumentException{

  public ExceptionProva(){
    super("MESSAGGIO ERRORE");
  }

  public  ExceptionProva(String msg){
    super(msg);
  }
  
}
