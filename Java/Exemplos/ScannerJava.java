import java.util.Scanner;

public class ScannerJava {
  /**
   * @param args
   */
  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    int i1 = 0,i2 = 0;
    System.out.print("Digite o primerio inteiro: ");
    String texto = entrada.nextLine();
    
    i1 = Integer.parseInt(texto); 
    System.out.print("Digite o segundo inteiro: ");
    texto = entrada.nextLine();

    i2 = Integer.parseInt(texto);
    System.out.printf("A soma %d + %d = %d\n\n",i1,i2, i1 + i2);
    boolean sair = false,continuar = false;
    int op = 0, numero1 = 0 ,numero2 = 0;
    
    do{
      do{
        try{
          System.out.println("Para finalizar digite 0");
          System.out.println("Para somar digite 1");
          System.out.println("Para subtrair digite 2");
          System.out.println("Para multiplicar digite 3");
          System.out.println("Para dividir digite 4");
          System.out.println("Para continuar o resto digite 5");
          System.out.print("Digite a operacao desejada: ");
          texto = entrada.nextLine();
          if(texto.isEmpty()){
            System.out.println("Nenhuma operação informada");
            continuar = false;
          }else{
            op = Integer.parseInt(texto);
            continuar = true;
            if(op>0 && op<6){
              do{
                try{
                  System.out.print("Digite o primeiro inteiro: ");
                  texto = entrada.nextLine();
                  numero1 = Integer.parseInt(texto);
                  continuar = true;
                }catch(NumberFormatException exception){
                  System.out.print("Valor inserido nao e um inteiro valido");
                }
              }while(!continuar);
              continuar = false;
              do{
                try{
                  System.out.print("Digite o segundo inteiro: ");
                  texto = entrada.nextLine();
                  numero2 = Integer.parseInt(texto);
                  continuar = true;
                }catch(NumberFormatException exception){
                  System.out.println("Valor inserido nao e um inteiro valido");
                }
              }while(!continuar);
            }
            switch (op) {
              case 0:
                sair = true;
                continuar = true;
                break;
              case 1:
                somar(numero1,numero2);
                break;
              case 2:
                subtrair(numero1,numero2);
                break;
              case 3:
                multiplicar(numero1,numero2);
                break;
               case 4:
                dividir(numero1,numero2);
                break;
              case 5:
                calculaResto(numero1,numero2);
                break;
              default:
                System.out.println("Operacao nao reconhecida\n");
                continuar = false;
                break;
            };
          }
        }catch(NumberFormatException exception){
          System.out.println("Valor inserido nao e um inteiro valido\n");
        }
      }while(!continuar);
    }while(!sair);
    System.out.println("Programa finalizado");
    entrada.close();
  }
  static void somar(int numero1, int numero2){
    System.out.printf("Operacao %d + %d = %d\n\n",numero1,numero2,numero1 + numero2);
  }
  static void subtrair(int numero1, int numero2){
    System.out.printf("Operacao %d - %d = %d\n\n",numero1,numero2,numero1 - numero2);
  }
  static void multiplicar(int numero1, int numero2){
    System.out.printf("Operacao %d x %d = %d\n\n",numero1,numero2,numero1 * numero2);
  }
  static void dividir(int numero1, int numero2){
    try{
      System.out.printf("Operacao %d / %d = %d\n\n",numero1,numero2,numero1 / numero2);
    }catch(java.lang.ArithmeticException exception){
      System.out.println("Divisao por zero nao permitida");
    }
  }
  static void calculaResto(int numero1, int numero2){
    System.out.printf("Operacao %d resto %d = %d\n\n",numero1,numero2,numero1 % numero2);
  }
}
