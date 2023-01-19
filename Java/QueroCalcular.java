/**
 * QueroCalcular
 * Esta classe lerá os dois números do tipo double do teclado e o tipo da operação aritmética a ser realizada, em seguida acionará o método desejado para realizar a operação aritmética.  O resultado retornado, também do tipo double, é obtido através do método getResultado() e é apresentado no desktop
 */

 import java.util.Scanner;

 public class QueroCalcular {
  /**
   * executar
   */
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
      QueroCalcular.executar(entrada);
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
    int operacao = 0;
    boolean continuar = false;
    double numero1 = 0.0, numero2 = 0.0;
    Calculadora calculadora = new Calculadora();
    do{
      try{
        System.out.println("Para somar digite 1");
        System.out.println("Para subtrair digite 2");
        System.out.println("Para multiplicar digite 3");
        System.out.println("Para dividir digite 4");
        System.out.print("Digite a operação desejada: ");
        String texto = entrada.nextLine();
        operacao = Integer.parseInt(texto);
        if(operacao < 1 || operacao > 4){
          System.out.println("Operação inválida");
          operacao = 0;
        }else{
          do{
            try{
              System.out.print("Digite o primeiro número: ");
              texto = entrada.nextLine();
              numero1 = Double.parseDouble(texto);
              continuar = true;
            }catch(NumberFormatException exception){
              System.out.println("Valor inserido não e um numero válido");
            }
          }while(!continuar);
          continuar = false;
          do{
            try{
              System.out.print("Digite o segundo número: ");
              texto = entrada.nextLine();
              numero2 = Double.parseDouble(texto);
              if(numero2==0.0 && operacao==4){
                System.out.println("O denominador não pode ser zero");
                continuar = false;
              }else{
                continuar = true;
              }
            }catch(NumberFormatException exception){
              System.out.println("Valor inserido não é um numero válido");
            }
          }while(!continuar);
          calculadora.setNumeros(numero1, numero2);
          System.out.print(numero1);
          switch(operacao){
            case 1:
              calculadora.somar();
              System.out.print(" + ");
              break;
            case 2:
              calculadora.subtrair();
              System.out.print(" - ");
              break;
            case 3:
              calculadora.multiplicar();
              System.out.print(" * ");
              break;
            case 4:
              calculadora.dividir();
              System.out.print(" / ");
              break;
          };
          System.out.print(numero2);
          System.out.print(" = ");
          System.out.println(calculadora.getResultado());
        }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido não é um inteiro válido");
        operacao = 0;
      }
    }while(operacao==0);
  }
}