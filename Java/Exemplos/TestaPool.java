import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class TestaPool {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(5);
        for (int i = 0; i < 20; i++) {
            Runnable worker = new TestaThread("" + i);
            executor.execute(worker);
        }
        executor.shutdown();
        while (!executor.isTerminated()) { }
        System.out.println("Todas as threads encerradas");
    }
}