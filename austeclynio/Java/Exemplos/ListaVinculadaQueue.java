/**
 * ListaVinculadaQueue
*/
import java.util.LinkedList;
import java.util.Queue;
import java.util.Iterator;

public class ListaVinculadaQueue {

  /**
   * @param args
   */
  public static void main(String[] args) {
    Queue<String> queue = new LinkedList<String>();
    queue.add("Cascadura");
    queue.add("Madureira");
    queue.add("Bento Ribeiro");
    queue.add("Oswaldo Cruz");
    queue.add("Marechal Hermes");
    System.out.println("Início:"+queue.element());
    System.out.println("Início:"+queue.peek());
    System.out.println("Iteragindo:");
    Iterator<String> itr = queue.iterator();
    while(itr.hasNext()){
      System.out.println("    "+itr.next());
    }
    queue.remove();
    queue.poll();
    System.out.println("Após remoções");
    itr = queue.iterator();
    while (itr.hasNext()) {
      System.out.println("    "+itr.next());
    }
  }
}