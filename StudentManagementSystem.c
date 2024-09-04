#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start();
void login();
void signup();
void student_menu(char* username);
void teacher_menu(char* username);
void view_student_details(char* username);
void view_upcoming_exams();
void add_student(char* username1);
void remove_student(char* username1);
void get_student_details(char* username1);
void update_student_details(char* username1);
void add_upcoming_exam(char* username1);
void view_students_List(char* username1);

void view_students_List(char* username1) {

}

void add_upcoming_exam(char* username1) {
    system("cls");
    char exam_name[50], exam_date[15], exam_time[10];
    FILE *file;

    printf("Enter exam name: ");
    fgets(exam_name, 50, stdin);
    strtok(exam_name, "\n");

    printf("Enter exam date (DD/MM/YYYY): ");
    fgets(exam_date, 15, stdin);
    strtok(exam_date, "\n");

    printf("Enter exam time (HH:MM): ");
    fgets(exam_time, 10, stdin);
    strtok(exam_time, "\n");

    // Open file in append mode to add new examination
    file = fopen("exams.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write examination details to the file
    fprintf(file, "Exam Name: %s, Date: %s, Time: %s\n", exam_name, exam_date, exam_time);
    fclose(file);

    printf("Upcoming examination/test added successfully!\n");
    teacher_menu(username1);

}

void update_student_details(char* username1) {
    system("cls");
    char rollno[10], line[300];
    FILE *file, *temp;
    int found = 0;

    printf("Enter roll number of student to update: ");
    fgets(rollno, 10, stdin);
    strtok(rollno, "\n");

    file = fopen("students.csv", "r");
    temp = fopen("temp.csv", "w");
    if (file == NULL || temp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        char file_rollno[10];
        sscanf(line, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%[^,]", file_rollno);

        if (strcmp(rollno, file_rollno) == 0) {
            found = 1;
            char username[50], password[50], marks[10], attendance[10];
            char father_name[50], mother_name[50], class_name[10], phone[15];
            char age[5], dob[15], mentor_name[50];

            sscanf(line, "%[^,],%[^,],%*[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
                   username, password, marks, attendance, father_name, mother_name, class_name, phone, rollno, age, dob, mentor_name);

            printf("Enter new marks: ");
            fgets(marks, 10, stdin);
            strtok(marks, "\n");

            printf("Enter new attendance: ");
            fgets(attendance, 10, stdin);
            strtok(attendance, "\n");

            printf("Enter new father's name: ");
            fgets(father_name, 50, stdin);
            strtok(father_name, "\n");

            printf("Enter new mother's name: ");
            fgets(mother_name, 50, stdin);
            strtok(mother_name, "\n");

            printf("Enter new class: ");
            fgets(class_name, 10, stdin);
            strtok(class_name, "\n");

            printf("Enter new phone number: ");
            fgets(phone, 15, stdin);
            strtok(phone, "\n");

            printf("Enter new age: ");
            fgets(age, 5, stdin);
            strtok(age, "\n");

            printf("Enter new date of birth (DOB): ");
            fgets(dob, 15, stdin);
            strtok(dob, "\n");

            printf("Enter new mentor name: ");
            fgets(mentor_name, 50, stdin);
            strtok(mentor_name, "\n");

            fprintf(temp, "%s,%s,student,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", username, password, marks, attendance, father_name, mother_name, class_name, phone, rollno, age, dob, mentor_name);
        } else {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.csv");
    rename("temp.csv", "students.csv");

    if (found) {
        printf("Student details updated successfully!\n");
    } else {
        printf("Student not found.\n");
    }
    teacher_menu(username1);
}

void get_student_details(char* username1) {
    system("cls");
    char rollno[10], line[300];
    FILE *file;
    int found = 0;

    printf("Enter roll number of student to get details: ");
    fgets(rollno, 10, stdin);
    strtok(rollno, "\n");

    file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        char file_rollno[10];
        sscanf(line, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%[^,]", file_rollno);

        if (strcmp(rollno, file_rollno) == 0) {
            char username[50], marks[10], attendance[10], father_name[50], mother_name[50];
            char class_name[10], phone[15], age[5], dob[15], mentor_name[50];

            sscanf(line, "%[^,],%*[^,],%*[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
                   username, marks, attendance, father_name, mother_name, class_name, phone, rollno, age, dob, mentor_name);

            printf("Username: %s\n", username);
            printf("Marks: %s\n", marks);
            printf("Attendance: %s\n", attendance);
            printf("Father's Name: %s\n", father_name);
            printf("Mother's Name: %s\n", mother_name);
            printf("Class: %s\n", class_name);
            printf("Phone Number: %s\n", phone);
            printf("Roll Number: %s\n", rollno);
            printf("Age: %s\n", age);
            printf("Date of Birth: %s\n", dob);
            printf("Mentor Name: %s\n", mentor_name);
            printf("\n");
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Student not found.\n");
    }
    teacher_menu(username1);
}

void remove_student(char* username1) {
    system("cls");
    char rollno[10], line[300];
    FILE *file, *temp;
    int found = 0;

    printf("Enter roll number of student to remove: ");
    fgets(rollno, sizeof(rollno), stdin);
    strtok(rollno, "\n");  // Remove trailing newline character

    file = fopen("students.csv", "r");
    temp = fopen("temp.csv", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read each line in the students.csv file
    while (fgets(line, sizeof(line), file)) {
        // Break the line into tokens to extract the roll number
        char *token;
        char *file_rollno = NULL;
        int column = 0;

        // Tokenize the line
        token = strtok(line, ",");
        while (token != NULL) {
            column++;
            if (column == 9) {  // Assuming roll number is the 9th column
                file_rollno = token;
                break;
            }
            token = strtok(NULL, ",");
        }

        // Compare the roll numbers
        if (file_rollno != NULL && strcmp(rollno, file_rollno) != 0) {
            // If not a match, write the line to the temp file
            fputs(line, temp);
        } else if (file_rollno != NULL && strcmp(rollno, file_rollno) == 0) {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    // Replace the original file with the updated temp file
    remove("students.csv");
    rename("temp.csv", "students.csv");

    if (found) {
        printf("Student removed successfully!\n");
    } else {
        printf("Student not found.\n");
    }

    teacher_menu(username1);
}

void add_student(char* username1) {
    system("cls");
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
    system("cls");
    char line[100];
    FILE *file;

    file = fopen("exams.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Upcoming Exams/Tests:\n");

    while (fgets(line, sizeof(line), file)) {
        char exam_name[50], exam_date[15];
        sscanf(line, "%[^,],%s", exam_name, exam_date);

        printf("Exam/Test: %s, Date: %s\n", exam_name, exam_date);
    }

    fclose(file);
}

void view_student_details(char* username) {
    system("cls");
    char line[300];
    FILE *file;
    int found = 0;

    file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        char file_username[50];
        sscanf(line, "%[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,]", file_username);

        if (strcmp(username, file_username) == 0) {
            char marks[10], attendance[10], father_name[50], mother_name[50], class_name[10];
            char phone[15], rollno[10], age[5], dob[15], mentor_name[50];

            sscanf(line, "%*[^,],%*[^,],%*[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
                   marks, attendance, father_name, mother_name, class_name, phone, rollno, age, dob, mentor_name);

            printf("Marks: %s\n", marks);
            printf("Attendance: %s\n", attendance);
            printf("Father's Name: %s\n", father_name);
            printf("Mother's Name: %s\n", mother_name);
            printf("Class: %s\n", class_name);
            printf("Phone Number: %s\n", phone);
            printf("Roll Number: %s\n", rollno);
            printf("Age: %s\n", age);
            printf("Date of Birth: %s\n", dob);
            printf("Mentor Name: %s\n", mentor_name);
            printf("\n");
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Student details not found.\n");
    }
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
            remove_student(username);
            break;
        case 3:
            get_student_details(username);
            break;
        case 4:
            update_student_details(username);
            break;
        case 5:
            add_upcoming_exam(username);
            break;
        case 6:
            view_students_List(username);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void student_menu(char* username) {
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
        system("cls");
        teacher_menu(username);
    }else{
        system("cls");
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