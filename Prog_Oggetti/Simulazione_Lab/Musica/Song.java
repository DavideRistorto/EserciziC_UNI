package Simulazione_Lab.Musica;

public class Song implements Playable {

  private String title;
  private String artist;

  public Song(String t, String a){
    title = t;
    artist = a;
  }

  @Override
  public void play(){
    System.out.println(String.format("Riproduzione della canzone <%s> dell' artista <%s>", title,artist));
  }

  @Override
  public String getTitle(){
    return  title;
  } 
 
}
