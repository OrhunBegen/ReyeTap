#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h> // Include the standard C library

//add function declarations here
void createFoodListFile();




//add functions
void createFoodListFile() {
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "w");
    fclose(file);
}

void createOrdersFile() {
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "w");
    fclose(file);
}

#endif // RESTAURANT_H