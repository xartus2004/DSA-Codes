package oops;
import java.util.Scanner;
public class Main2 {
	public static void main(String[] args) {
		Scanner in= new Scanner(System.in);
		System.out.println("Enter the integer at greater than 4:");
		int n=in.nextInt();
		
		int[] series=new int[n];
		series[0]=0;
		series[1]=1;
		series[2]=2;
		for(int i=3;i<n;i++)
		{
			if(i%2==0)
			{   
				series[i]=series[i-1]+series[i-2];
			}
			else {
				series[i]=series[i-1]+series[i-2]+series[i-3];
			}
			
		}
		for(int i=0;i<n;i++)
		{
			System.out.print(series[i]+" ");
		}
		in.close();
	}
}