public class MinhaThread extends Thread{
  static int count = 0;
  private int id;
  private MinhaClasse soma = new MinhaClasse(0.0);
  MinhaThread(){
    count++;
    id = count;
  }
  public void run(){
    vai();
    soma.calcula();
  }
  public void vai(){
    System.out.println("Thread "+id+" Disparada !!");
    imprimeAlgo();
  }
  public void imprimeAlgo(){
    System.out.println("Thread "+id+" Imprimindo Algo !!");
  }
  public static void main(String[] args){
    Runnable dispara = new MinhaThread();
    Thread uma = new Thread(dispara);
    Thread dois = new Thread(dispara);
    uma.start();
    dois.start();
  }
}