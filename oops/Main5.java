package oops;
import java.util.*;
public class Main5{
    public static void main(String args[])
    {
        int n;
        Scanner in=new Scanner(System.in);
        System.out.print("Enter the number of numbers:");
        n=in.nextInt();
        int[] arr=new int[n];

        for(int i=0;i<n;i++)
        {
            System.out.print("Enter the number:");
            arr[i]=in.nextInt();
        }

        int min=arr[0];

        int n1;
        int s=0;
        int k=0;
        System.out.print("Enter the target number:");
        n1=in.nextInt();

        for(int i=1;i<n;i++)
            if (min>arr[i])
                min=arr[i];

        if (n1<min)
            System.out.print(-1);

        for(int i=0;i<n;i++)
            if (arr[i]==n1)
                s=i;
        
        int v=0;

        for (int i=0;i<n;i++)
        {
            if (arr[i]<n1 && arr[i]>v)
            {
                k=i;
                v=arr[i];
            }
        }

        if (s==0)
            System.out.print(k);
        else
            System.out.print(s);

        in.close();
    }
}