#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start();
void login();
void signup();
void student_menu(char *username);
void teacher_menu();

void teacher_menu() {

}

void student_menu(char *username) {

}

void login() {
    system("cls");
    char username[50], password[50], line[300], stored_username[50], stored_password[50], occupation[20];
    FILE *file;
    int found = 0;

    printf("Enter username: ");
    fgets(username, 50, stdin);
    strtok(username, "\n");

    printf("Enter password: ");
    fgets(password, 50, stdin);
    strtok(password, "\n");

    file = fopen("users.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%s", stored_username, stored_password, occupation);

        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("Login successful!\n");

        if (strcmp(occupation, "student") == 0) {
            student_menu(username);
        } else if (strcmp(occupation, "teacher") == 0) {
            teacher_menu();
        } else {
            printf("Invalid occupation.\n");
        }
    } else {
        printf("Invalid username or password.\n");
        login();
    }
}

void signup() {
    system("cls");
    printf("Please Provide The Below Details.\n\n");

    char username[50], password[50], confirm_password[50], occupation[20];
    FILE *file;

    printf("Enter username: ");
    fgets(username, 50, stdin);
    strtok(username, "\n");

    printf("Enter password: ");
    fgets(password, 50, stdin);
    strtok(password, "\n");

    printf("Confirm password: ");
    fgets(confirm_password, 50, stdin);
    strtok(confirm_password, "\n");

    if (strcmp(password, confirm_password) != 0) {
        printf("Passwords do not match.\n");
        signup();
        return;
    }

    printf("Enter occupation (student/teacher): ");
    fgets(occupation, 20, stdin);
    strtok(occupation, "\n");

    file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "%s,%s,%s\n", username, password, occupation);
    fclose(file);

    printf("Signup successful!\n");
    start();
}

void start() {
    system("cls");
    printf("==============================================================================\n");
    printf("========================Welcome To DataBase Management========================\n");
    printf("==============================================================================\n");

    int choice;
    printf("\n1.) Login \t\t\t 2.) Signup\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        signup();
        break;
    default:
        printf("Invalid Choice!!\n");
        start();
        break;
    }    
}

int main() {
    start();
    return 0;
}