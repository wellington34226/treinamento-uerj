/**
 * Arrays
*/

import java.util.Scanner;
import java.util.Arrays;
import java.nio.charset.StandardCharsets;

public class ArraysTestes {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false,continuar = false;
    String texto;
    do{
        ArraysTestes.executar(entrada);
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
    String nomes[] = new String[10];
    for (int i = 0; i < nomes.length; i++) {
        System.out.print("Digite o ");
        switch (i) {
            case 0:
                System.out.print("primeiro");
                break;
            case 1:
                System.out.print("segundo");
                break;
            case 2:
                System.out.print("terceiro");
                break;
            case 3:
                System.out.print("quarto");
                break;
            case 4:
                System.out.print("quinto");
                break;
            case 5:
                System.out.print("sexto");
                break;
            case 6:
                System.out.print("sétimo");
                break;
            case 7:
                System.out.print("oitavo");
                break;
            case 8:
                System.out.print("nono");
                break;
            case 9:
                System.out.print("décimo");
                break;
        }
        System.out.print(" nome:");
        String nome = entrada.nextLine();
        byte[] bytes = nome.getBytes(StandardCharsets.UTF_8);
        nomes[i] = new String(bytes,StandardCharsets.UTF_8);
    }
    System.out.println("Array original:");
    for (int i = 0; i < nomes.length; i++) {
        System.out.print("O ");
        switch (i) {
            case 0:
                System.out.print("primeiro");
                break;
            case 1:
                System.out.print("segundo");
                break;
            case 2:
                System.out.print("terceiro");
                break;
            case 3:
                System.out.print("quarto");
                break;
            case 4:
                System.out.print("quinto");
                break;
            case 5:
                System.out.print("sexto");
                break;
            case 6:
                System.out.print("sétimo");
                break;
            case 7:
                System.out.print("oitavo");
                break;
            case 8:
                System.out.print("nono");
                break;
            case 9:
                System.out.print("décimo");
                break;
        }
        System.out.println(" nome e "+nomes[i]);
    }
    Arrays.sort(nomes);
    System.out.println("Array ordenado:");
    for (int i = 0; i < nomes.length; i++) {
        System.out.print("O ");
        switch (i) {
            case 0:
                System.out.print("primeiro");
                break;
            case 1:
                System.out.print("segundo");
                break;
            case 2:
                System.out.print("terceiro");
                break;
            case 3:
                System.out.print("quarto");
                break;
            case 4:
                System.out.print("quinto");
                break;
            case 5:
                System.out.print("sexto");
                break;
            case 6:
                System.out.print("sétimo");
                break;
            case 7:
                System.out.print("oitavo");
                break;
            case 8:
                System.out.print("nono");
                break;
            case 9:
                System.out.print("décimo");
                break;
        }
        System.out.println(" nome e "+nomes[i]);
    }
    int tabela[] = {54,9,18,44,26,5,99,20,100,-4,123,432};
    System.out.println("Array original:");
    for (int i = 0; i < tabela.length; i++) {
        System.out.print(tabela[i] +" ");
    }
    Arrays.sort(tabela);
    System.out.println("\nArray ordenado:");
    for (int i = 0; i < tabela.length; i++) {
        System.out.print(tabela[i] +" ");
    }
    System.out.println();
  }
}