#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<conio.h>

void displayWelcomeScreen();
void loadingAnimation();
int adminLogin();
int employeeLogin();
void clearScreen();
void employeeDashboard(const char *empid);
void adminDashboard();
void adminInfoAnimation();
void addEmployee();
void removeEmployee();

typedef struct {
    char empid[20];
    char name[50];
    char department[30];
    char position[30];
    char contact[15];
} Employee;

Employee employees[] = {
    {"ZAMIUL_01", "Zamiul Hasan", "IT", "Software Engineer", "017xxxxxxx1"},
    {"SOHA_02", "Soha Khan", "HR", "HR Manager", "017xxxxxxx2"},
    {"Arman_03", "Arman Ali", "Finance", "Accountant", "017xxxxxxx3"},
    {"Neelima_04", "Neelima Das", "Marketing", "Marketing Head", "017xxxxxxx4"},
    {"Jayed_05", "Jayed Ahmed", "Operations", "Operations Manager", "017xxxxxxx5"}
};
int numEmployees = sizeof(employees) / sizeof(employees[0]);

struct Admin {
    char adminid[20];
    char name[50];
    char position[30];
    char contact[15];
};

struct Admin admin = {"ADMIN_01", "Zamiul Hasan", "System Administrator", "018xxxxxxx0"};

int main() {
    int choice;

    displayWelcomeScreen();

    printf("\033[1;36m");
    printf("\nChoose an option:\n");
    printf("\033[0m");

    printf("\033[0;32m");
    printf("                                         ========================================\n");
    printf("                                         ||           1. Admin Login           ||\n");
    printf("                                         ========================================\n");
    printf("\033[0m");
    printf("\033[0;32m");
    printf("                                         ========================================\n");
    printf("                                         ||          2. Employee Login         ||\n");
    printf("                                         ========================================\n");
    printf("\033[0m");
    printf("\033[1;34m");
    printf("Enter your choice: ");
    printf("\033[0m");
    scanf("%d", &choice);

    clearScreen();
    switch (choice) {
        case 1:
            if (adminLogin()) {
                adminInfoAnimation();
                adminDashboard();
            } else {
                printf("Access denied. Invalid credentials.\n");
            }
            break;
        case 2:
            if (employeeLogin()) {
                loadingAnimation();
            } else {
                printf("Access denied. Invalid credentials.\n");
            }
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            exit(1);
    }

    return 0;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void displayWelcomeScreen() {
    #define GRN "\e[0;32m"
    printf("\e[1;32m\n\n");
    printf("                                         ========================================\n");
    printf("                                         ||            Welcome to the          ||\n");
    printf("                                         ||        Employee Record System      ||\n");
    printf("                                         ========================================\n");
    printf("\e[0m\n\n");

    loadingAnimation();
}

void loadingAnimation() {

    printf("Loading ");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        usleep(5000000000000);
    }
    printf("!");
    printf("\n");
    clearScreen();
}

#include <stdio.h>
#include <string.h>

int adminLogin() {
    char username[20], password[20];
    const char correctUsername[] = "ZamiulHasan";
    const char correctPassword[] = "Cheater_123";

    printf("\033[2J\033[H");
    printf("\033[0;32m");
    printf("                                   ========================================\n");
    printf("                                   ||            Admin Login             ||\n");
    printf("                                   ========================================\n");
    printf("                                                                             \n");
    printf("                                   ========================================\n");
    printf("                                   || Username:                          ||\n");
    printf("                                   ||------------------------------------||\n");
    printf("                                   || Password:                          ||\n");
    printf("                                   ========================================\n");
    printf("\033[0m");

    printf("\033[5;58H");
    scanf("%s", username);

    printf("\033[7;58H");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        return 1;
    }
    return 0;
}

int employeeLogin() {
    char empID[20], empPassword[20];

    const char *validempIDs[] = {"ZAMIUL_01", "SOHA_02", "Arman_03", "Neelima_04", "Jayed_05"};
    const char *validEmpPasswords[] = {"ZAMIUL_01", "SOHA_02", "Arman_03", "Neelima_04", "Jayed_05"};

    printf("\033[0;32m");
    printf("                                         ========================================\n");
    printf("                                         ||           Employee Login           ||\n");
    printf("                                         ========================================\n");
    printf("\033[0m");
    printf("Employee ID: ");
    scanf("%s", empID);
    printf("Password: ");
    scanf("%s", empPassword);

    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(empID, validempIDs[i]) == 0 && strcmp(empPassword, validEmpPasswords[i]) == 0) {
            employeeDashboard(empID);
            return 1;
        }
    }

    printf("Error: Invalid credentials.\n");
    return 0;
}

void employeeDashboard(const char *empid) {
    printf("\033[0;32m");
    printf("                                         ========================================\n");
    printf("                                         ||         Employee Dashboard         ||\n");
    printf("                                         ========================================\n");
    printf("\033[0m");
    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(employees[i].empid, empid) == 0) {
            printf("Welcome, %s\n", employees[i].name);
            printf("Your Details:\n");
            printf("Employee ID: %s\n", employees[i].empid);
            printf("Department: %s\n", employees[i].department);
            printf("Position: %s\n", employees[i].position);
            printf("Contact: %s\n", employees[i].contact);
            break;
        }
    }

    int choice;
    do {
        printf("\nOptions:\n");
        printf("1. Search Employee by id\n");
        printf("2. Logout\n");
        printf("\033[1;34m");
        printf("Enter your choice: ");
        printf("\033[0m");
        scanf("%d", &choice);

        if (choice == 1) {
            char searchID[20];
            printf("\nEnter Employee id to search: ");
            scanf("%s", searchID);

            int found = 0;
            for (int i = 0; i < numEmployees; i++) {
                if (strcmp(employees[i].empid, searchID) == 0) {
                    printf("\nEmployee Found:\n");
                    printf("Name: %s\n", employees[i].name);
                    printf("Department: %s\n", employees[i].department);
                    printf("Position: %s\n", employees[i].position);
                    printf("Contact: %s\n", employees[i].contact);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("No employee found with ID: %s\n", searchID);
            }
        }
    } while (choice != 2);

     printf("\033[0;31m");
    printf("\nLogging out...\n");
    printf("\033[0m");
}

void adminInfoAnimation() {
    printf("\033[0;32m");
    printf("\nWelcome, Admin!\n");
     printf("\033[0m");
    loadingAnimation();
    printf("Admin Details:\n");
    printf("Admin ID: %s\n", admin.adminid);
    printf("Name: %s\n", admin.name);
    printf("Position: %s\n", admin.position);
    printf("Contact: %s\n", admin.contact);
    printf("\nRedirecting to Admin Dashboard...\n");
    loadingAnimation();
}

void adminDashboard() {
    int choice;
    do {
        printf("                            \n--- Admin Dashboard ---\n");
        printf("                                 1. View All Employees\n");
        printf("                                 2. Edit Employee Information\n");
        printf("                                 3. Add Employee\n");
        printf("                                 4. Remove Employee\n");
        printf("                                 5. Logout\n");
        printf("                                    Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nAll Employees:\n");
            for (int i = 0; i < numEmployees; i++) {
                printf("\nEmployee ID: %s\n", employees[i].empid);
                printf("Name: %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                printf("Position: %s\n", employees[i].position);
                printf("Contact: %s\n", employees[i].contact);
            }
        } else if (choice == 2) {
            char editID[20];
            printf("\nEnter Employee ID to edit: ");
            scanf("%s", editID);

            int found = 0;
            for (int i = 0; i < numEmployees; i++) {
                if (strcmp(employees[i].empid, editID) == 0) {
                    printf("\nEditing Employee: %s\n", employees[i].name);
                    printf("Enter New Name: ");
                    scanf(" %[^\n]%*c", employees[i].name);
                    printf("Enter New Department: ");
                    scanf(" %[^\n]%*c", employees[i].department);
                    printf("Enter New Position: ");
                    scanf(" %[^\n]%*c", employees[i].position);
                    printf("Enter New Contact: ");
                    scanf(" %[^\n]%*c", employees[i].contact);
                    printf("\033[0;32m");
                    printf("Employee information updated successfully.\n");
                     printf("\033[0m");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("No employee found with ID: %s\n", editID);
            }
        } else if (choice == 3) {
            addEmployee();
        } else if (choice == 4) {
            removeEmployee();
        }
    } while (choice != 5);

    printf("\033[0;31m");
    printf("\nLogging out...\n");
    printf("\033[0m");

    clearScreen();
}

void addEmployee() {
    printf("\n--- Add Employee ---\n");

    Employee newEmployee;
    printf("Enter Employee ID: ");
    scanf("%s", newEmployee.empid);
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", newEmployee.name);
    printf("Enter Department: ");
    scanf(" %[^\n]%*c", newEmployee.department);
    printf("Enter Position: ");
    scanf(" %[^\n]%*c", newEmployee.position);
    printf("Enter Contact: ");
    scanf(" %[^\n]%*c", newEmployee.contact);

    employees[numEmployees] = newEmployee;
    numEmployees++;
    printf("New employee added successfully.\n");
}

void removeEmployee() {
    printf("\n--- Remove Employee ---\n");

    char empid[20];
    printf("Enter Employee ID to remove: ");
    scanf("%s", empid);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(employees[i].empid, empid) == 0) {

            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            printf("Employee with ID %s removed successfully.\n", empid);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No employee found with ID: %s\n", empid);
    }
}


