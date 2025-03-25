
import java.util.Arrays;
import java.util.List;

public class StringOps {

  public static String longest(List<String> strings){
    assert strings != null;
      String max = strings.get(0);
      int maxLen = strings.get(0).length();
      for(String stringa : strings){
        if(stringa.length() > maxLen){
          max = stringa;
          maxLen = stringa.length();
        }
      }
      return max;
  }

  public static String concatAll(List<String> strings){
    assert strings != null;
    String concat = "";
    for(String stringa : strings){
      concat = concat.concat(stringa);
    }
    return concat;
  }

  public static String trim(String stringa){
    return stringa.trim();
  }

  public static void main(String[] args) {
    // Test per il metodo longest
    List<String> strings = Arrays.asList("apple", "banana", "cherry", "date");
    System.out.println("Longest string: " + longest(strings)); // Output: banana

    // Test per il metodo concatAll
    System.out.println("Concatenated string: " + concatAll(strings)); // Output: applebananacherrydate

    // Test per il metodo trim
    String stringWithSpaces = "   hello world   ";
    System.out.println("Trimmed string: '" + trim(stringWithSpaces) + "'"); // Output: 'hello world'
  }
}