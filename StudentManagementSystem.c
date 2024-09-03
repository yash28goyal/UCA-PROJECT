#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start();
void login();
void signup();
void student_menu(char *username);
void teacher_menu();
void view_student_details();
void view_upcoming_exams();
void add_student(char *username1);
void remove_student();
void get_student_details();
void update_student_details();
void add_upcoming_exam();
void view_students_List();

void view_students_List() {

}

void add_upcoming_exam() {

}

void update_student_details() {

}

void get_student_details() {

}

void remove_student() {

}

void add_student(char* username1) {
    char username[50], password[50] = "default", occupation[20] = "student";
    char marks[10], attendance[10], father_name[50], mother_name[50], class_name[10];
    char phone[15], rollno[10], age[5], dob[15], mentor[50];
    FILE *file;

    printf("Enter student username: ");
    fgets(username, 50, stdin);
    strtok(username, "\n");

    printf("Enter marks: ");
    fgets(marks, 10, stdin);
    strtok(marks, "\n");

    printf("Enter attendance: ");
    fgets(attendance, 10, stdin);
    strtok(attendance, "\n");

    printf("Enter father's name: ");
    fgets(father_name, 50, stdin);
    strtok(father_name, "\n");

    printf("Enter mother's name: ");
    fgets(mother_name, 50, stdin);
    strtok(mother_name, "\n");

    printf("Enter class: ");
    fgets(class_name, 10, stdin);
    strtok(class_name, "\n");

    printf("Enter phone number: ");
    fgets(phone, 15, stdin);
    strtok(phone, "\n");

    printf("Enter roll number: ");
    fgets(rollno, 10, stdin);
    strtok(rollno, "\n");

    printf("Enter age: ");
    fgets(age, 5, stdin);
    strtok(age, "\n");

    printf("Enter date of birth (DOB): ");
    fgets(dob, 15, stdin);
    strtok(dob, "\n");
    
    printf("Enter Mentor name : ");
    fgets(mentor, 50, stdin);
    strtok(mentor, "\n");

    // Open file in append mode to add new student
    file = fopen("students.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write student details to the file
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", username, password, occupation, marks, attendance, father_name, mother_name, class_name, phone, rollno, age, dob, mentor);
    fclose(file);

    system("cls");
    printf("Student added successfully!\n");
    teacher_menu(username1);
}

void view_upcoming_exams() {

}

void view_student_details() {

}

void teacher_menu(char* username) {
    int choice;

    printf("Welcome, Teacher\n\n");
    printf("1. Add Student\n");
    printf("2. Remove Student\n");
    printf("3. Get Student Details\n");
    printf("4. Update Student Details\n");
    printf("5. Add Upcoming Exam/Test\n");
    printf("6. View Students List\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            add_student(username);
            break;
        case 2:
            remove_student();
            break;
        case 3:
            get_student_details();
            break;
        case 4:
            update_student_details();
            break;
        case 5:
            add_upcoming_exam();
            break;
        case 6:
            view_students_List();
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void student_menu(char *username) {
    system("cls");
    int choice;

    printf("Welcome, %s\n", username);
    printf("1. View Details\n");
    printf("2. View Upcoming Exams\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            view_student_details(username);
            break;
        case 2:
            view_upcoming_exams();
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void login() {
    char username[50], password[50], line[300], stored_username[50], stored_password[50], occupation[20];

    printf("Enter username: ");
    fgets(username, 50, stdin);
    strtok(username, "\n");

    printf("Enter password: ");
    fgets(password, 50, stdin);
    strtok(password, "\n");

    FILE *file;
    int found = 0;

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
            system("cls");
            student_menu(username);
        } else if (strcmp(occupation, "teacher") == 0) {
            system("cls");
            teacher_menu(username);
        } else {
            printf("Invalid occupation.\n");
        }
    } else {
        printf("Invalid username or password.\n");
        login();
    }
}

void signup() {
    char username[50], password[50], confirm_password[50], occupation[20];

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

    FILE *file;
    file = fopen("users.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "%s,%s,%s\n", username, password, occupation);
    fclose(file);

    printf("Signup successful!\n");
    if(strcmp(occupation, "teacher") == 0){
        teacher_menu(username);
    }else{
        student_menu(username);
    }
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
    getchar();

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