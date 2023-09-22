import java.util.*;

class Employee{
    private int empID;
    private int salary;
    private String name;

    public Employee(int ID,int sal,String name)
    {
        this.empID=ID;
        this.salary=sal;
        this.name=name;
    }

    public int getSalary()
    {
        return this.salary;
    }

    public int getID()
    {
        return this.empID;
    }

    public static int getSalaryByID(Employee employees[],int ID)
    {
        for(Employee employee:employees)
            if(employee.empID==ID)
                return employee.salary;
        return -1;
    }

    public void incrementSalary(int amount)
    {
        salary+=amount;
    }
}

class EmployeeDatabase{
    private Employee employees[];
    private int size;

    public EmployeeDatabase(int capacity)
    {
        employees=new Employee[capacity];
        size=0;
    }

    public void addEmployee(int ID,int salary,String name)
    {
        if(size<employees.length)
        {
            employees[size]=new Employee(ID, salary, name);
            size++;
        }
        else
        {
            System.out.println("Database is Full");
        }
    }

    public void printEmployee(int ID)
    {
        for(int i=0 ; i<size ; i++)
            if(employees[i].getID()==ID)
            {
                System.out.println(employees[i]);
                return;
            }
        System.out.print("Employee Not Found")
    }
}

public class prac {
    
}
