#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void start();
void addStudent();
void studentRecord();
void searchStudent();
void deleteStudent();

struct Student {
    char firstName[50];
    char lastName[50];
    int rollNo;
    char class[10];
    char address[50];
    long long int phoneNO;
};

typedef struct Student Student;

void addStudent() {

    char more;
    FILE* fp;
    Student info;

    do {
        system("cls");
        printf("*=======Add Student Information=======*\n\n\n");
        fp = fopen("student_data.txt", "a");
        printf("\nEnter the first name : ");
        scanf("%s", &info.firstName);
        printf("\nEnter the last name  : ");
        scanf("%s", &info.lastName);
        printf("\nEnter the roll no.   : ");
        scanf("%d", &info.rollNo);
        printf("\nEnter the class      : ");
        scanf("%s", &info.class);
        printf("\nEnter the city       : ");
        scanf("%s", &info.address);
        printf("\nEnter the phone no.  : ");
        scanf("%d", &info.phoneNO);
        printf("\n__________________________________________________\n");

        if(fp == NULL) {
            fprintf(stderr, "File doesn't exist\n\n");
        } else {
            printf("\nRecord stored successfully\n");
        }

        fwrite(&info, sizeof(Student), 1, fp);
        fclose(fp);

        printf("\nDo you want to add another record? (y/n) : ");
        scanf("%s", &more);
    } while(more == 'y' || more == 'Y');
}

void start() {
    system("cls");
    int choice;

    while(choice != 5) {
        printf("*=======Student Database Management System=======*");
        printf("\n1.) Add Student Record.");
        printf("\n2.) Show Student Record.");
        printf("\n3.) Search Student Record.");
        printf("\n4.) Delete Student Record.");
        printf("\n5.) Exit.");
        printf("\n__________________________________________________\n");
        printf("\nEnter the choice : ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            addStudent();
            system("cls");
            break;
        default:
            break;
        }
    }
}

int main() {

    start();
    return 0;

}