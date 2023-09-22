import java.util.*;

public class bankManagementSystem {
    static Scanner sc = new Scanner(System.in);

    public static class Bank {
        public String BankName;
        public Account[] accounts = new Account[50];

        public class Account {
            public static int id = 0;
            public String name;
            public String accountNum;
            public double balance;

            Account(String name, double balance) {

                this.name = name;
                this.balance = balance;
                this.accountNum = "95771000" + Account.id;
            }
        }

        public void withdraw() {
            System.out.print("Enter account No :- ");
            String accountNum = sc.next();
            System.out.println();
            System.out.print("Enter money to deposit :- ");
            double money = sc.nextDouble();
            System.out.println();
            int num = Integer.parseInt(accountNum.substring(7));
            if (accounts[num] == null) {
                System.out.println("Account is not present in our system");
                return;
            }
            if (accounts[num].balance - money < 0) {
                System.out.println("Insufficient bank balance");
                return;
            }
            accounts[num].balance -= money;
            System.out.println("Now your account balance is :- " + accounts[num].balance);

        }

        public void deposite() {
            System.out.print("Enter account No :- ");
            String accountNum = sc.next();
            System.out.println();
            System.out.print("Enter money to deposit :- ");
            double money = sc.nextDouble();
            System.out.println();
            int num = Integer.parseInt(accountNum.substring(7));
            if (accounts[num] == null) {
                System.out.println("Account is not present in our system");
                return;
            }
            accounts[num].balance += money;
            System.out.println("Now your account balance is :- " + accounts[num].balance);
        }

        public void transfer() {
            System.out.print("Enter source account no. :- ");

            String src1 = sc.next();
            System.out.println();
            int src = Integer.parseInt(src1.substring(7));

            System.out.println("Enter destination account no. :- ");
            String dest1 = sc.next();
            int dest = Integer.parseInt(dest1.substring(7));

            if (accounts[src] == null || accounts[dest] == null) {
                System.out.println("Account is not present in our system");
                return;
            }

            System.out.println("Enter amount to transfer :- ");
            double amt = sc.nextDouble();
            if (accounts[src].balance - amt < 0) {
                System.out.println("Insufficient bank balance");
                return;
            }
            accounts[dest].balance = accounts[src].balance + amt;
            accounts[src].balance -= amt;
            System.out.println("Source acc balance :- " + accounts[src].balance);
            System.out.println("Destination acc balance :- " + accounts[dest].balance);
        }

        public void openNewAcc() {
            System.out.println("Enter New Account-Holder details :- ");
            System.out.print("Name :- ");
            String name = sc.next();
            System.out.println();
            System.out.print("Initial Balance :- ");
            double balance = sc.nextDouble();
            System.out.println();
            accounts[++(Account.id)] = new Account(name, balance);
            System.out.println("Your Account no. :- " + accounts[Account.id].accountNum);
            System.out.println(" your account balance is :- " + accounts[Account.id].balance);

        }

        public void closeAccount() {
            System.out.print("Enter Account no. :- ");
            String accountNum = sc.next();
            System.out.println();
            int num = Integer.parseInt(accountNum.substring(7));
            if (accounts[num] == null) {
                System.out.println("Account is not present in our system");
                return;
            }
            accounts[num] = null;
        }

    }

    public static void main(String[] args) {
        Bank myBank = new Bank();
        while (true) {
            System.out.println("Enter corresponding num for operation :- ");
            System.out.println("1. Create a new account ");
            System.out.println("2. Deposite ");
            System.out.println("3. Withdraw ");
            System.out.println("4. Transfer ");
            System.out.println("5. Close ");
            System.out.println("6. Exit ");
            int val = sc.nextInt();
            switch (val) {
                case 1:
                    myBank.openNewAcc();
                    break;
                case 2:

                    myBank.deposite();
                    break;
                case 3:
                    myBank.withdraw();
                    break;
                case 4:
                    myBank.transfer();
                    break;
                case 5:
                    myBank.closeAccount();
                    break;
                case 6:
                    return;

            }

        }
    }
}