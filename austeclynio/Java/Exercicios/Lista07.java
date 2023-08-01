/**
 * Lista07
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Random;
import java.util.Scanner;

public class Lista07 {

  public static void main(String[] args) {
    Scanner entrada = new Scanner(System.in);
    boolean sair  = false;
    int exercicio = 0;
    String texto;
    do{
      do{
        try{
            System.out.print("Digite o número do exercício: ");
            texto = entrada.nextLine();
            if(texto.isEmpty()){
            System.out.println("Nenhum exercício informado");
            }else{
              exercicio = Integer.parseInt(texto);
              switch(exercicio){
                case 1:
                  Lista07.execicio1();
                  break;
                case 2:
                  Lista07.execicio2();
                  break;
                case 3:
                  Lista07.execicio3();
                  break;
                case 4:
                  Lista07.execicio4();
                  break;
                case 5:
                  Lista07.execicio5();
                  break;
                case 6:
                  Lista07.execicio6();
                  break;
                case 7:
                  Lista07.execicio7();
                  break;
                default:
                  System.out.println("Exercício inválido, por favor digite um valor entre 1 e 7");
                  exercicio = 0;
              };
            }
        }catch(NumberFormatException exception){
            System.out.println("Valor inserido não é um inteiro válido");
            exercicio = 0;
        }
      }while(exercicio==0);
      exercicio = 0;
      do{
          System.out.print("\nDeseja finalizar s/n:");
          texto = entrada.nextLine();
          if(
              texto.toLowerCase().equals("s") || 
              texto.toLowerCase().equals("y") ||
              texto.toLowerCase().equals("sim") || 
              texto.toLowerCase().equals("yes")
          ){
              exercicio = 1;
              sair = true;
          }else if(
              texto.toLowerCase().equals("n") || 
              texto.toLowerCase().equals("não") || 
              texto.toLowerCase().equals("no")
          ){
              exercicio = 1;
          }else{
              System.out.println("Digite s, y sim ou yes para finalizar o programa ou n, não ou no para continuar executando");
          }
      }while(exercicio==0);
      System.out.println("");
    }while(!sair);
    System.out.println("Programa finalizado");
    entrada.close();
  }

  public static void execicio1() {
    ArrayList<Integer> array = new ArrayList<Integer>(10);
    Random random = new Random();
    for (int index = 0; index < 10; index++) {
      array.add(random.nextInt(1, 1000));
    }
    System.out.print("Array original:[ ");
    ListIterator<Integer> iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    Collections.sort(array);
    System.out.print("Array classificado:[ ");
    iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
  }
  public static void execicio2() {
    ArrayList<Integer> array = new ArrayList<Integer>(10);
    Random random = new Random();
    for (int index = 0; index < 10; index++) {
      array.add((index+1)*10);
    }
    System.out.print("Array original:[ ");
    ListIterator<Integer> iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    for(int i = 0; i < 5; i++) {
      Collections.swap(array,random.nextInt(0, 4),random.nextInt(5, 9));
    }
    System.out.print("Array embaralhado:[ ");
    iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
  }
  public static void execicio3() {
    ArrayList<Integer> array = new ArrayList<Integer>(10);
    Random random = new Random();
    for (int index = 0; index < 10; index++) {
      array.add(random.nextInt(1, 1000));
    }
    System.out.print("Array original:[ ");
    ListIterator<Integer> iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    Collections.swap(array,random.nextInt(0, 4),random.nextInt(5, 9));
    System.out.print("Array modificado:[ ");
    iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
  }
  public static void execicio4() {
    ArrayList<Integer> array1 = new ArrayList<Integer>(10);
    ArrayList<Integer> array2 = new ArrayList<Integer>(10);
    for (int index = 0; index < 10; index++) {
      array1.add((index+1)*10);
      array2.add((index+1)*10);
    }
    System.out.print("Array1:[ ");
    ListIterator<Integer> iterator = array1.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    System.out.print("Array2:[ ");
    iterator = array2.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    ArrayList<Integer> array = new ArrayList<Integer>(20);
    array.addAll(array1);
    array.addAll(array2);
    System.out.print("Array unido:[ ");
    iterator = array.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");

  }
  public static void execicio5() {
    LinkedList<Integer> lista = new LinkedList<Integer>();
    Random random = new Random();
    for (int index = 0; index < 10; index++) {
      lista.push(random.nextInt(1, 1000));
    }
    System.out.println("Lista:[");
    for (int i = 0; i < lista.size(); i++) {
      System.out.print("        posição:");
      System.out.print(i);
      System.out.print(" valor:");
      System.out.println(lista.get(i));
    }
    System.out.println("]");
  }
  public static void execicio6() {
    LinkedList<Integer> lista = new LinkedList<Integer>();
    Random random = new Random();
    for (int index = 0; index < 10; index++) {
      lista.push(random.nextInt(1, 1000));
    }
    System.out.print("Lista:[ ");
    ListIterator<Integer> iterator = lista.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    System.out.print("Primeiro elemento da lista é ");
    System.out.println(lista.peekFirst());
    System.out.print("Lista depois da operação:[ ");
    iterator = lista.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
  }
  public static void execicio7() {
    LinkedList<Integer> lista = new LinkedList<Integer>();
    Random random = new Random();
    for (int index = 0; index < 10; index++) {
      lista.push(random.nextInt(1, 1000));
    }
    System.out.print("Lista:[ ");
    ListIterator<Integer> iterator = lista.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
    System.out.print("Primeiro elemento da lista é ");
    System.out.println(lista.pollFirst());
    System.out.print("Último elemento da lista é ");
    System.out.println(lista.pollLast());
    System.out.print("Lista depois da operação:[ ");
    iterator = lista.listIterator();
    while(iterator.hasNext()) {
      System.out.print(iterator.next());
      if(iterator.hasNext()) {System.out.print(",");}
    }
    System.out.println(" ]");
  }
}