public class Usando_Variaveis_e_Underscore {
	public static void main(String[] args){	
			
    boolean result = true;
    char capitalC = 'C';
    byte b = 54;
    short s = -2587;
    int i = 11847852;
    
    System.out.println(result);
    System.out.println(capitalC);
    System.out.println(b);
    System.out.println(s);
    System.out.println(i);
    
  
    long creditCardNumber = 1234_5678_9012_3456L;			
    System.out.println(creditCardNumber);
    long socialSecurityNumber = 999_99_9999L;
    System.out.println(socialSecurityNumber);
    float pi =  3.14_15F;
    System.out.println(pi);
    long hexBytes = 0xFF_EC_DE_5E;
    System.out.println(hexBytes);
    long hexWords = 0xCAFE_BABE;
    System.out.println(hexWords);
    long maxLong = 0x7fff_ffff_ffff_ffffL;
    System.out.println(maxLong);
    byte nybbles = 0b0010_0101;
    System.out.println(nybbles);
    long bytes = 0b11010010_01101001_10010100_10010010;
    System.out.println(bytes);
  }
}
