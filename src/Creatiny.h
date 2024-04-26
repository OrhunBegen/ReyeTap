#ifndef CREATINY_H
#define CREATINY_H

#include <stdio.h> // Standard Input/Output Library
#include <stdlib.h> // Standard Library
#include <windows.h> // Windows Library
#include <string.h> // String Library

// Function declarations
void OpenFoodListFile();
void OpenOrdersFile();




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


#endif // CREATINY_H