import java.util.*;

class Employee {
    int id;
    String name;
    int salary;

    Employee(int id, int salary, String name) {
        this.id = id;
        this.salary = salary;
        this.name = name;
    }
    class address{
    	String street;
    	int houseno;
    	String city;
    	String state;
    	public address(String street,int houseno,String city,String state){
    		this.street=street;
    		this.houseno=houseno;
    		this.city=city;
    		this.state=state;
    	}
     }
    
	public address add;

}

class EmployeeDatabase {
    HashMap<Integer, Employee> emp = new HashMap<>();
    static int ind = 0;

    void addEmployee(Employee e1) {
        if (ind >= 50) {
            System.out.println("Database is full");
            return;
        }
        emp.put(e1.id, e1);
        ind++;
    }

    void printEmployees() {
        for (Map.Entry<Integer, Employee> entry : emp.entrySet()) {
            Employee it = entry.getValue();
            System.out.println("Id No:"+it.id + " " +"Name:"+it.name + " "+"Salary:"+ it.salary);
        }
    }
    
    void getAddress(int id) {
    	
    	Employee it = emp.get(id);
    	if (it == null)
    		return;
    	System.out.println("Street:"+it.add.street+" "+"House No:"+it.add.houseno+" "+"City:"+it.add.city+" "+"State:"+it.add.state);            	
    }

    void raiseSalary(int id, int amt) {
        Employee employee = emp.get(id);
            employee.salary += amt;
        emp.put(id, employee);
    }

    int getSalary(int id) {
        Employee employee = emp.get(id);
        if (employee != null) {
            return employee.salary;
        }
        return -1;
    }
}

public class Main7 {
    public static void main(String[] args) {
        EmployeeDatabase database = new EmployeeDatabase();

        Employee emp1 = new Employee(1, 5000, "Rohith");
        Employee emp2 = new Employee(2, 4000, "Suyash");
        emp1.add =  emp1.new address("MG",07,"Kasaragod","Kerala");
        emp2.add =  emp2.new address("Dombivli",14,"Mumbai","Maharashtra");
        
        
        

        database.addEmployee(emp1);
        database.addEmployee(emp2);
        

       

        database.printEmployees();
        database.getAddress(1);

        database.raiseSalary(1, 2000);
        int salary = database.getSalary(1);
        System.out.println("Employee-1 salary after incrementing: " + salary);
    }
}