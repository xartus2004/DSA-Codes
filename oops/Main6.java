class Employee {
    private int id;
    private String name;
    private int salary;

    public Employee(int id, String name, int salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }
    
    public int getSalary() {
        return salary;
    }
    

    public int getId() {
        return id;
    }

    public static int getSalaryById(Employee[] employees, int id) {
        for (Employee employee : employees) {
            if (employee.getId() == id) {
                return employee.getSalary();
            }
        }
        return -1;
    }
    
    public void incrementSalary(int amount) {
        salary += amount;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", salary=" + salary +
                '}';
    }
}

class EmployeeDatabase {
    private Employee[] employees;
    private int size;

    public EmployeeDatabase(int capacity) {
        employees = new Employee[capacity];
        size = 0;
    }

    public void addEmployee(int id, String name, int salary)
    {
        if (size < employees.length) {
            employees[size] = new Employee(id, name, salary);
            size++;
        } else {
            System.out.println("Database is full. Cannot add more employees.");
        }
    }

    public void printEmployee(int id) {
        for (int i = 0; i < size; i++) {
            if (employees[i].getId() == id) {
                System.out.print(employees[i]);
                return;
            }
        }
        System.out.println("Employee not found.");
    }

    public void incrementSalary(int id, int amount) {
        for (int i = 0; i < size; i++) {
            if (employees[i].getId() == id) {
                employees[i].incrementSalary(amount);
                System.out.println("Salary incremented for employee " + id);
                return;
            }
        }
        System.out.println("Employee not found.");
    }
}

public class Main6 {
    public static void main(String[] args) {
        EmployeeDatabase database = new EmployeeDatabase(10); // You can change the capacity as needed

        // Adding employees
        database.addEmployee(1, "John Doe", 50000);
        database.addEmployee(2, "Jane Smith", 60000);

        // Printing employees
        database.printEmployee(1);
        database.printEmployee(2);

        // Incrementing salary
        database.incrementSalary(1, 1000);

        // Printing updated employee
        database.printEmployee(1);
    }
}