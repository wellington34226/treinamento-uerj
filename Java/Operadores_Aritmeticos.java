import java.util.Scanner;

public class Operadores_Aritmeticos {
  public static void main (String[] args) {

    int result = 1 + 2,numero;
    // result is now 3
    System.out.println("1 + 2 = " + result);
    int original_result = result;

    result = result - 1;
    // result is now 2
    System.out.println(original_result + " - 1 = " + result);
    original_result = result;

    result = result * 2;
    // result is now 4
    System.out.println(original_result + " * 2 = " + result);
    original_result = result;

    result = result / 2;
    // result is now 2
    System.out.println(original_result + " / 2 = " + result);
    original_result = result;

    result = result + 8;
    // result is now 10
    System.out.println(original_result + " + 8 = " + result);
    original_result = result;

    result = result % 7;
    // result is now 3
    System.out.println(original_result + " % 7 = " + result);
    Scanner entrada = new Scanner(System.in);
    numero = 0;
    do{
      try{
        numero = entrada.nextInt();
          try {
            System.out.println(original_result + " / " + numero + " = " + original_result / numero);
          } catch (java.lang.ArithmeticException exception) {
            System.out.println("Digite um valor diferente de zero");
          }
      }catch(NumberFormatException exception){
        System.out.println("Valor inserido nao e um inteiro valido");
      }
    }while(numero==0);
    entrada.close();
  }
}
