/**
 * Lista6Exercicio2
 * 2. Escreva uma interface denominada Calculadora que possui as seguintes assinaturas de seus métodos:
 *   public int somar(int numero1, int numero2);
 *   public int subtrair(int numero1, int numero2);
 * Escreva uma classe denominada Calcular que implementa esta interface.
*/

import java.util.Scanner;

public class Lista6Exercicio2 {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista6Exercicio2.executar(entrada);
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
    Calcular calcular = new Calcular();
    int numero1 = 0,numero2 = 0;
    String texto;
    do{
      try{
        System.out.print("Digite primeiro número: ");
        texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.print("Nenhume número informado");
          continuar = false;
        }else{
          numero1 = Integer.parseUnsignedInt(texto);
          continuar = true;
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um número inteiro válido");
        continuar = false;
      }
    }while(!continuar);
    do{
      try{
        System.out.print("Digite segundo número: ");
        texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.println("Nenhum número");
          continuar = false;
        }else{
          numero2 = Integer.parseUnsignedInt(texto);
          continuar = true;
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um número inteiro válido");
        continuar = false;
      }
    }while(!continuar);
    System.out.printf("Soma: %d + %d = %d\nSubtração: %d - %d = %d\n",numero1,numero2,calcular.somar(numero1,numero2),numero1,numero2,calcular.subtrair(numero1,numero2));
  }
}