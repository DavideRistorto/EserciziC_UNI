//Animale.java
public class Animale{
  private String nome; 
  private int eta; 
  private double peso;

  public String   getNome()         {return nome;}
  public int      getEta()          {return eta;}
  public double   getPeso()         {return peso;}
  public void setNome(String n){nome =  n;}
  public void setEta(int e){eta = e;}
  public void setPeso(double p){peso = p;}

  public Animale(String n, int e, double p)
        {nome = n; eta = e; peso = p;}
  

  public String toString()
   {return " |nome=" + nome + "\n eta=" + eta + "\n peso=" +  peso;}
}


