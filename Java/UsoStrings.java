import java.util.Scanner;

public class UsoStrings {
  public static void main(String[] args) {
    String texto = new String();
    Scanner entrada = new Scanner(System.in);
    do{
      System.out.print("Digite um texto:");
      texto = entrada.nextLine();
      if(texto.equalsIgnoreCase("quit")){
        System.out.println("Finalizando");
      }else{
        switch(texto.length()){
          case 0:
            System.out.println("Erro: string vazia");
            break;
        case 1:
          System.out.println("String original:"+texto);
          break;
        case 2:
          System.out.println("String maiuscula:"+texto.toUpperCase());
          break;
        case 3:
          System.out.println("String minuscula:"+texto.toLowerCase());
          break;
        case 4:
          System.out.println("String original:"+texto+" substring: "+texto.substring(2,texto.length()));
          break;
        case 5:
          System.out.println("String original:"+texto+" caracter do meio: "+texto.charAt(2));
          break;
        default:
          System.out.println(texto.concat(" VALIDADO"));
        };
      }
    }while(!texto.equalsIgnoreCase("quit"));
    entrada.close();
  }
}