package oops;

public class Main8 {
	
	public static class account{
		String accname;
		double bankbal;
		int accno;
		public account(String accname,double bankbal,int accno)
		{
			this.accname=accname;
			this.bankbal=bankbal;
			this.accno=accno;
		}
		
		  public void deposit(double amount)
		  {
			    bankbal+=amount;
		  }
		  public void withdraw(double amount)
		  {
			    bankbal-=amount;
		  }
		  public void transfer(account acc,double amount)
		  {
			    if (amount > bankbal)
			    	return;
			    
			    bankbal -= amount;
			    acc.bankbal += amount;
		  }
		
	}
	public static class bank{
		account [] accounts=new account[100];
		int j=1;
		public void addacc(account a) {
			accounts[j]=a;
			j++;
		}
		public void removeacc(account a)
		{
			for(int i = 0; i < accounts.length; ++i) {
				if(accounts[i]==a)
				{
					accounts[i]=null;
				}
			}
		}
		
		public void transfer(int accno1,int accno2,double amount)
		{
			 if (accounts[accno1].bankbal < amount)
			    	return;
			 else {
			accounts[accno1].bankbal-=amount;
			accounts[accno2].bankbal+=amount;
			 }
			
		}
		

	}
	
	public static void main(String[] args)
	{
      account a1= new account("Rohith",10000,1);
      account a2= new account("Hari",5000,2);
      
      bank b = new bank();
      
      b.addacc(a1);
      b.addacc(a2);
      b.transfer(1, 2, 2000);
      System.out.println("Rohith's Balance:"+a1.bankbal+"\t"+"Hari's Balance:"+a2.bankbal);
      
 
	}
	


}