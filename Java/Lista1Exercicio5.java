
/**
 * Lista1Exercicio5
 * 5. Escreva um aplicativo que leia do teclado um nome e copie os 3 primeiros caracteres deste nome para outra string, imprimindo o texto.
 */

import java.util.Scanner;

public class Lista1Exercicio5 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista1Exercicio5.executar(entrada);
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
    do{
      System.out.print("Digite um nome com no mínimo 3 caracteres:");
      texto = entrada.next();
      entrada.nextLine();
      if(texto.length()>2){
        System.out.println("Resultado: "+texto.substring(0,2));
      }else{
        System.out.println("Texto menor que o necessário.");
      }
    }while(texto.length()<3);
  }
}