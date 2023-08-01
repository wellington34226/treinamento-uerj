public class Menor extends Thread{
  private int numeros[];
  public Menor(int[] numeros){
    this.numeros = numeros;
  }
  @Override
  public void run() {
    int menor = 0;
    System.out.print("O menor número da lista [ ");
    for(int posicao=0;posicao < this.numeros.length;posicao++) {
      System.out.print(this.numeros[posicao]+" ");
      if(this.numeros[posicao] < this.numeros[menor]){
        menor = posicao;
      }
    }
    System.out.println("] é "+this.numeros[menor]+" na posição "+menor);
  }
}
