public class TestaThreads implements Runnable{
  private String palavra;
  private int delay;
  private boolean renuncia;
  public TestaThreads(String oQueFalar,int tempoDelay,boolean renuncia){ // Construtor
    this.palavra=oQueFalar;
    this.delay = tempoDelay;
    this.renuncia = renuncia;
  }
  public void run() {
    for(;;){
      try {
        System.out.println(Thread.currentThread().getName()+" "+Thread.currentThread().getPriority()+":"+palavra);
        if(renuncia){
          Thread.yield();
          Runnable filha = new ThreadFilha();
          Thread th = new Thread(filha);
          th.start();
          Thread.sleep(delay);
          
        }else{
          Thread.sleep(delay);
        }
      } catch (InterruptedException e) {
        System.out.println("Erro");
      }
    }
  }    
  public static void main(String[] args) {
    Runnable ping1=new TestaThreads("um",500,true);
    Runnable ping2=new TestaThreads("dois",500,false);
    Runnable ping3=new TestaThreads("tres",500,false);
    Runnable ping4=new TestaThreads("quatro",500,false);
    Runnable ping5=new TestaThreads("cinco",500,false);
    Runnable ping6=new TestaThreads("seis",500,false);
    Thread ping11 = new Thread(ping1);
    Thread ping22 = new Thread(ping2);
    Thread ping33 = new Thread(ping3);
    Thread ping44 = new Thread(ping4);
    Thread ping55 = new Thread(ping5);
    Thread ping66 = new Thread(ping6);
    ping11.start();
    ping22.start();
    ping33.start();
    ping44.start();
    ping55.start();
    ping66.start(); 
  }
}