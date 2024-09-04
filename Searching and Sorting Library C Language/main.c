#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sorting.h"
#include "searching.h"

void start();
void init();
void searching();
void sorting();
void print(int *arr, int n);
void choices();

int n;
int arr[100];

bool check(int *arr, int n) {
    int cnt = 1;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] < arr[i+1]){
            cnt++;
        }
    }
    if(cnt == n) {
        return true;
    }
    else {
        printf("Your array is not sorted first sort array to apply binary search!\n");
        choices();
        return false;
    }
}

void print(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void sorting(){
    printf("==================================================================\n");
    printf("================== You Want To Sorting the array =================\n");
    printf("==================================================================\n\n\n");

    int choice;
    printf("Which sorting technique you want to use?\n");
    printf("1.) Bubble Sort\n");
    printf("2.) Insertion Sort\n");
    printf("3.) Selection Sort\n");
    printf("4.) Exit.\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        // bubble_sort(arr, n);
        print(arr, n);
        break;
        case 2:
        // insertion_sort(arr, n);
        print(arr, n);
        break;
        case 3:
        // selection_sort(arr, n);
        print(arr, n);
        break;
        case 4:
        break;
        default:
        system("cls");
        printf("\nInvalid Input!\n\n");
        sorting();
        break;
    }
}

void searching(){
    printf("==================================================================\n");
    printf("================ You Want To Do Searching in array ===============\n");
    printf("==================================================================\n\n\n");
    int target;
    printf("\nPlease Enter the target element you want to search : ");
    scanf("%d", &target);
    int choice;
    printf("Which searching technique you want to use?\n");
    printf("1.) Linear Search\n");
    printf("2.) Binary Search\n");
    printf("3.) Exit.\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        // linear_search(arr, n, target);
        break;
        case 2:
        if(check(arr, n)) {
            // binary_search(arr, n, target);
        }
        break;
        case 3:
        break;
        default:
        system("cls");
        printf("\nInvalid Input!\n\n");
        searching();
        break;
    }
}

void choices() {
    
    int choice;
    printf("\nWhich operation you want to do on array?\n\n");
    printf("1.) Searching \t\t 2.) Sorting\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1 :
        system("cls");
        searching();
        break;
        case 2 :
        system("cls");
        sorting();
        break;
        default :
        system("cls");
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
    system("cls");
    choices();
}

void start() {
    system("cls");
    printf("==================================================================\n");
    printf("================= Welcome TO Array Manipulator ===================\n");
    printf("==================================================================\n");

    printf("\n\n");
    init();
}

int main() {
    start();
    return 0;
}