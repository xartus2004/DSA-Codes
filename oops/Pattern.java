package oops;
import java.util.*;
public class Pattern {
	public static void main(String[] args) {
		Scanner in= new Scanner(System.in);
		System.out.println("Enter the height:");
		int h=in.nextInt();
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=h;j++)
			{
				if(j>=9-i)
				{
					System.out.print("*");
				}
				else {
					System.out.print(" ");
				}
			
			}
			System.out.println("");
		}
		in.close();
		
		}
	}