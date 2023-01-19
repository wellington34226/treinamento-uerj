/**
 * Lista3Exercicio3
 * 3. Escreva um aplicativo que leia do teclado quatro números inteiros não negativos e diga se estes números podem constituir os lados de um retângulo.
 * 
*/

import java.util.Scanner;

public class Lista3Exercicio3 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista3Exercicio3.executar(entrada);
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
    int[] lados = {-1,-1,-1,-1};
    byte indiceCorrente = 0;
    boolean continuar = false;
    do{
      try{
        switch(indiceCorrente) {
          case 0:
            System.out.print("Digite o primeiro lado do retângulo: ");
            break;
          case 1:
            System.out.print("Digite o segundo lado do retângulo: ");
            break;
          case 2:
            System.out.print("Digite o terceiro lado do retângulo: ");
            break;
          case 3:
            System.out.print("Digite o quarto lado do retângulo: ");
            break;
        }
        String texto = entrada.nextLine();
        lados[indiceCorrente] = Integer.parseUnsignedInt(texto);
        if(lados[indiceCorrente] < 0){
          System.out.println("Lado deve ser positivo");
          continuar = false;
        }else{
          indiceCorrente++;
          if(indiceCorrente>3){
            if(lados[0] == 0 || lados[1] == 0 || lados[2] == 0 || lados[3] == 0){
              System.out.println("Lado não pode ser nulo");
            }else{
              if(
                lados[0] == lados[1] && lados[2] == lados[3] || 
                lados[0] == lados[2] && lados[1] == lados[3] ||
                lados[0] == lados[3] && lados[1] == lados[2]
              ){
                System.out.println("Lados informados constituem um retângulo");
              }else{
                System.out.println("Lados informados não constituem um retângulo");
              }
            }
            continuar = true;
          }
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um inteiro válido");
        continuar = false;
      }
    }while(!continuar);
  }
}
