package oops;
import java.util.Scanner;

public class Main3 {

	public static void reverseArray(int [] a,int beg,int end) {
		if(beg>=end)
		{
		return;
	    }
		
		int temp=a[beg];
		a[beg]=a[end];
		a[end]=temp;
		
		reverseArray(a,beg+1,end-1);
       }
	
	public static void main(String[] args) 
    {
        Scanner in= new Scanner(System.in);
        System.out.print("Enter the size:");
        int n=in.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the integer:");
            a[i]=in.nextInt();
        }
        
        reverseArray(a,0,n-1);
        
        System.out.println("The reversed array:");
        for(int i=0;i<n;i++)
            System.out.println(a[i]);

        in.close();    
    }
	
}