public class Lista6 {
  public static int x = 7;
  public int y = 3;
  public static void main(String[] args) {
    Lista6 a = new Lista6();
    Lista6 b = new Lista6();
    a.y = 5;
    b.y = 6;
    Lista6.x = 1;
    Lista6.x = 2;
    System.out.println("a.y ="+a.y);
    System.out.println("b.y ="+b.y);
    System.out.println("a.x ="+Lista6.x);
    System.out.println("b.x ="+Lista6.x);
    System.out.println("Lista6.x ="+Lista6.x);
  }
}