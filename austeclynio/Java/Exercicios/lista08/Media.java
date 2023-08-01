public class Media extends Thread{
  private int numeros[];
  public Media(int[] numeros){
    this.numeros = numeros;
  }
  @Override
  public void run() {
    int media = 0;
    System.out.print("A média dos números [ ");
    for (int numero : this.numeros) {
      System.out.print(numero+" ");
      media += numero;
    }
    System.out.println("] é "+media/this.numeros.length);
  }
}
