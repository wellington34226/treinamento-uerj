/**
 * Lista1Exercicio2
 * 2. Escreva um aplicativo que leia do teclado um nome e substitua todas as vogais existentes neste nome pelo caractere “k”. Imprima o texto.
 */

import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Lista1Exercicio2 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista1Exercicio2.executar(entrada);
      do{
        System.out.print("\nDeseja finalizar s/n:");
        texto = entrada.nextLine();
        if(
          texto.toLowerCase().equals("s") || 
          texto.toLowerCase().equals("y") ||
          texto.toLowerCase().equals("sim") || 
          texto.toLowerCase().equals("yes")
        ){
          continuar = true;
          sair = true;
        }else if(
          texto.toLowerCase().equals("n") || 
          texto.toLowerCase().equals("não") || 
          texto.toLowerCase().equals("no")
        ){
          continuar = true;
        }else{
          System.out.println("Digite s, y sim ou yes para finalizar o programa ou n, não ou no para continuar executando");
          continuar = false;
        }
      }while(!continuar);
      System.out.println("");
    }while(!sair);
    System.out.println("Programa finalizado");
    entrada.close();
  }
  
  public static void executar(Scanner entrada) {
    String texto;
    System.out.print("Digite um nome:");
    texto = entrada.next();
    entrada.nextLine();
    byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
    texto = new String(bytes,StandardCharsets.UTF_8);
    System.out.println("Resultado: "+texto.replaceAll("[aeiouAEIOU]","k"));
  }
}
