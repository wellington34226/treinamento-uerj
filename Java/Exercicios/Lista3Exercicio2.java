/**
 * Lista3Exercicio2   
 * 2. Escreva um aplicativo que leia do teclado o salário bruto de determinado funcionário e calcule o desconto do Imposto de Renda, segundo a seguinte tabela:
 * _______________________________________________
 * | Salário bruto          |      Desconto      |
 * |_____________________________________________|
 * | Até 1200,00            | Isento de desconto |
 * | De 1201,00 até 1800,00 |        10%         |
 * | De 1801,00 até 2500,00 |        15%         |
 * | Acima de 2500,00       |        25%         |
 * |_____________________________________________|
 * Devem ser impressos o salário bruto e o valor do desconto.
*/

import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Lista3Exercicio2 {
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      Lista3Exercicio2.executar(entrada);
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
        System.out.print("Digite o salário bruto do funcionário: ");
        double salario = -1.0;
        String texto = entrada.nextLine();
        if(texto.isEmpty()){
          System.out.println("Nenhum valor informado");
          continuar = false;
        }else{
          byte[] bytes = texto.getBytes(StandardCharsets.UTF_8);
          texto = new String(bytes,StandardCharsets.UTF_8);
          salario = Integer.parseUnsignedInt(texto);
          if(salario > 0.0){
            continuar = true;
            if(salario > 2500.0){
              System.out.printf("Salário bruto de %.2f desconto do Imposto de Renda de 25%%\n",salario);
            }else if(salario < 1201.00){
              System.out.printf("Salário bruto de %.2f isento de Imposto de Renda\n",salario);
            }else if(salario < 1801.00){
              System.out.printf("Salário bruto de %.2f desconto do Imposto de Renda de 10%%\n",salario);
            }else{
              System.out.printf("Salário bruto de %.2f desconto do Imposto de Renda de 15%%\n",salario);
            }
          }else{
            System.out.println("Salário inválido, salário deve ser maior que zero");
            continuar = false;
          }
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um número válido");
        continuar = false;
      }
    }while(!continuar);
  }
}
