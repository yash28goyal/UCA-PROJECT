#include <stdio.h>
#include <stdlib.h>


int n;
int arr[100];

void sorting(){
    int choice;
    system("cls");
    printf("Which sorting technique you want to use?\n");
    printf("1.) Bubble Sort\n");
    printf("2.) Insertion Sort\n");
    printf("3.) Selection Sort\n");
    printf("4.) Exit.\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    
}
void searching(){
    return;
}

void choices() {
    system("cls");
    int choice;
    printf("\nWhich operation you want to do on array?\n\n");
    printf("1.) Searching \t\t 2.) Sorting\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1 :
        searching();
        break;
        case 2 :
        sorting();
        break;
        default :
        printf("Invalid Input!");
        choices();
        break;
    }
}

void init() {
    printf("Please enter the size of array(Max 100) : ");
    scanf("%d", &n);
    printf("Please enter the element of the array : ");
    for(int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);
    }

    choices();
}

void start() {
    system("cls");
    printf("==================================================================\n");
    printf("==================Welcome TO Array Manipulator====================\n");
    printf("==================================================================\n");

    printf("\n\n");
    init();
}

int main() {
    start();
    return 0;
}