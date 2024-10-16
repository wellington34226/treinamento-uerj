public class TestaJoin implements Runnable {
  int[] array;
  static int soma =0;
  public TestaJoin(int[] array){
  this.array=array;
  }
  public void run() {
    for (int i=0; i<array.length; i++){
      soma = soma + array[i];
      }
  }
  public static void main(String[] args) {
    int[] array1 = new int[]{1,2,3,4,5,6,7,8,9,10};
    int[] array2 = new int[]{11,12,13,14,15,16,17,18,19,20};
    Runnable ping1=new TestaJoin(array1);
    Thread ping11 = new Thread(ping1);
    Runnable ping2=new TestaJoin(array2);
    Thread ping22 = new Thread(ping2);
    ping11.start();
    ping22.start();
    try {
      ping11.join();
      ping22.join();
      System.out.println("Esperei o término !");
      System.out.println(soma);
    }catch (Exception e) {
      System.err.println("Erro");
    }
  }
}