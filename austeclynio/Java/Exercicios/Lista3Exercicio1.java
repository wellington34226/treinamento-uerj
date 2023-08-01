/**
 * Lista3Exercicio1
 * 1. Escreva um aplicativo que leia do teclado a nota de um aluno e imprima o seu conceito final de acordo com a seguinte tabela:
 * Nota entre | Conceito
 * 90 -100    |    A
 * 70 -89     |    B
 * 50 - 69    |    C
 * 0 - 49     |    D
 * Deve ser utilizada a instrução de controle switch.
*/

import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Lista3Exercicio1 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista3Exercicio1.executar(entrada);
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
    boolean continuar;
    do{
      try{
        System.out.print("Digite a nota do aluno: ");
        int nota = -1;
        String texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.println("Nenhuma nota informada");
          continuar = false;
        }else{
          byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
          texto = new String(bytes,StandardCharsets.UTF_8);
          nota = Integer.parseInt(texto);
          continuar = true;
          if(nota>=0){
            switch(nota / 10) {
              case 0:
              case 1:
              case 2:
              case 3:
              case 4:
                System.out.println("Resultado: conceito D");
                break;
              case 5:
              case 6:
                System.out.println("Resultado: conceito C");
                break;
              case 7:
              case 8:
                System.out.println("Resultado: conceito B");
                break;
              case 9:
              case 10:
                if(nota > 100){
                  System.out.println("Nota digitada inválida, a nota deve estar entre 0 e 100");
                }else{
                  System.out.println("Resultado: conceito A");
                }
                break;
              default:
                System.out.println("Nota digitada inválida, a nota deve estar entre 0 e 100");
                continuar = false;
                break;
            }
          }else{
            System.out.println("Nota digitada inválida, a nota deve estar entre 0 e 100");
            continuar = false;
          }
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um inteiro válido");
        continuar = false;
      }
    }while(!continuar);
  }
}
