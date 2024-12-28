#include<stdio.h>
    int id;
    char name[100];
    float salary;
} Employee;

void addEmployee(Employee employees[], int *size) {
    printf("Enter employee ID: ");
    scanf("%d", &employees[*size].id);
    printf("Enter employee name: ");
    scanf("%s", employees[*size].name);
    printf("Enter employee salary: ");
    scanf("%f", &employees[*size].salary);
    (*size)++;
}


void deleteEmployee(Employee employees[], int *size, int id) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (employees[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (i = i; i < *size - 1; i++) {
            employees[i] = employees[i + 1];
        }
        (*size)--;
        printf("Employee record deleted successfully!\n");
    } else {
        printf("Employee record not found!\n");
    }
}


void viewEmployees(Employee employees[], int size) {
    int i;
    printf("Employee Records:\n");
    for (i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}


void calculateSalary(Employee employees[], int size) {
    int i;
    float totalSalary = 0;
    for (i = 0; i < size; i++) {
        totalSalary += employees[i].salary;
    }
    printf("Total salary of all employees: %.2f\n", totalSalary);
}

int main() {
    Employee employees[100];
    int size = 0, choice;
    while (1) {
        printf("Employee Payroll System\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. View Employees\n");
        printf("4. Calculate Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(employees, &size);
                break;
            case 2:
                int id;
                printf("Enter employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(employees, &size, id);
                break;
            case 3:
                viewEmployees(employees, size);
                break;
            case 4:
                calculateSalary(employees, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

            
