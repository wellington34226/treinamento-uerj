/**
 * @(#)QualquerCoisa.java
 *
 *
 * @author 
 * @version 1.00 2023/1/10
 */
import java.util.Scanner;
public class QualquerCoisaScanner{	
	public static void main(String[] args)
	{	
		Scanner entrada = new Scanner(System.in);
		System.out.printf("Digite o primeiro numero: \t");
		int i1 = entrada.nextInt();
		System.out.println(i1);
		System.out.printf("Digite o segundo numero: \t");
		int i2 = entrada.nextInt();
		System.out.printf("%s%d\n","A soma: ",i1 + i2);
		entrada.close();
	}

		
}