package oops;

import java.util.Scanner;

public class Main4 {
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
		
		System.out.println("Enter the target:");
		int targ=in.nextInt();
		
		int t;
		for(int i=0;i<n;i++)
		{
            for(int j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;  
                }
            }
		}
		
		int k=1,floor=-1;
		int j=n-1;
		while(k!=0)
		{
			if(targ>a[j])
			{
			floor=a[j];
			k=0;
			}
			j--;
		}
		if(k==1)
		{
			System.out.println("Floor="+floor);
		}
		else {
			System.out.println("Floor="+ floor);
		}
        in.close();
    }
}