import java.util.Scanner;
public class Main1 {
	public static void main(String[] args) {
		Scanner in= new Scanner(System.in);
		System.out.print("Enter the integer:");
		String n=in.next();
		System.out.println(n);
		int sum1=0;
		int sum2=0;
		for(int i=0;i<n.length();i++)
		{
			if(i%2==0)
				sum2=sum2+(int)n.charAt(i);
			else
				sum1=sum1+(int)n.charAt(i);	
		}
		System.out.println("Result:" + (sum2-sum1));
        in.close();
  }
}