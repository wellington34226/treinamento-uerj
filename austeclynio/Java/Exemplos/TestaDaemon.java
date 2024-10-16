public class TestaDaemon extends Thread {
  public void run(){
    if(Thread.currentThread().isDaemon()){
      System.out.println("Thread Daemon");
    }else{
      System.out.println("Thread de Usuário");
    }
  }
  public static void main(String[] args) {
    Thread t1 = new TestaDaemon();
    Thread t2 = new TestaDaemon();
    Thread t3 = new TestaDaemon();
    Thread t4 = new TestaDaemon();
    t1.setDaemon(true);
    t1.start();
    t2.start();
    t3.start();
    t4.start();
  }
}
