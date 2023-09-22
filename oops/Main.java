import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in= new Scanner(System.in);
		System.out.println("Enter the height:");
		int h=in.nextInt();
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=h-i;j++)
				System.out.print(" ");
			for(int j=1 ; j<=i ; j++)
				System.out.print("*");
			System.out.println("");
		}
		in.close();
		
		}
	}