#ifndef CREATINY_H
#define CREATINY_H

#include <stdio.h> // Standard Input/Output Library
#include <stdlib.h> // Standard Library

// Function declarations

void OpenFoodListFile();
void OpenOrdersFile();
void CreateAccount();
void Login();


// Function definitions

void OpenFoodListFile() {
    FILE *file = fopen("FoodList.txt", "r");
    if (file == NULL) {
        printf("Error: FoodList.txt file could not be opened.\n");
        exit(1);
    }
    fclose(file);
}
void OpenOrdersFile() {
    FILE *file = fopen("Orders.txt", "r");
    if (file == NULL) {
        printf("Error: Orders.txt file could not be opened.\n");
        exit(1);
    }
    fclose(file);
}

void CreateAccount() {
    /* 
        

     */
}
void Login() {
    /* 
        

     */
}


#endif // CREATINY_H