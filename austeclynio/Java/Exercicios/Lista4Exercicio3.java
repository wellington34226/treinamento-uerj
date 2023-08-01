/**
 * Lista4Exercicio3
 * 3. Escreva um aplicativo que simulará uma máquina de calcular que realize as operações aritméticas de somar, subtrair, multiplicar e dividir de dois números. Ele deve possuir as seguintes classes:
 *   a. classe Calculadora
 *    Esta classe é constituida dos métodos somar, subtrair, multiplicar, dividir, getResultado e setNumeros. Os valores são passados para esta classe através do método setNumeros e são do tipo double. O resultado final é obtido através do método getResultado. 
 *   b. classe QueroCalcular
 *    Esta classe lerá os dois números do tipo double do teclado e o tipo da operação aritmética a ser realizada, em seguida acionará o método desejado para realizar a operação aritmética.  O resultado retornado, também do tipo double, é obtido através do método getResultado() e é apresentado no desktop 
*/

import java.util.Scanner;

public class Lista4Exercicio3 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista4Exercicio3.executar(entrada);
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
    QueroCalcular.executar(entrada);
  }

}
