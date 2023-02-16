import java.util.LinkedList;
import java.util. Collections;
public class TestaSortReverse{
  public static void main(String[] args){
    LinkedList<String> lista = new LinkedList<String>();
    lista.add("anna") ;
    lista.add("rose");
    lista.add("joao") ;
    lista.add("andre") ;
    lista.add("maria") ;
    Collections.sort(lista);
    System.out.printf("%s\n", lista);
    Collections.reverse(lista);
    System.out.printf("%s\n", lista);
  }
}