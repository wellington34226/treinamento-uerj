public class Lista06 {
  public static int x = 7;
  public int y = 3;
  public static void main(String[] args) {
    Lista06 a = new Lista06();
    Lista06 b = new Lista06();
    a.y = 5;
    b.y = 6;
    Lista06.x = 1;
    Lista06.x = 2;
    System.out.println("a.y ="+a.y);
    System.out.println("b.y ="+b.y);
    System.out.println("a.x ="+Lista06.x);
    System.out.println("b.x ="+Lista06.x);
    System.out.println("Lista6.x ="+Lista06.x);
  }
}