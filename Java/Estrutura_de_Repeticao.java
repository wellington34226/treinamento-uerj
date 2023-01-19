
public class Estrutura_de_Repeticao {

  public static void main(String[] args){
    for(int i=1; i<11; i++){
      System.out.println("Count is: " + i);
    }
  
    int count = 1;
    while (count < 11) {
      System.out.println("Count is: " + count);
      count++;
    }
    
    System.out.println("");
    
    count = 1;
    do {
      System.out.println("Count is: " + count);
      count++;
    } while (count < 11);
  }
}