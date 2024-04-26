#ifndef CREATINY_H
#define CREATINY_H

#include <stdio.h> // Standard Input/Output Library
#include <stdlib.h> // Standard Library
#include <windows.h> // Windows Library
#include <string.h> // String Library

// Function declarations
void OpenFoodListFile();
void OpenOrdersFile();

//Functions for Restaurant
void WriteRestaurantMainMenu();


//just for the first time to create a sample food list and testing
void CreateASampleFoodList();


void EditFoodListMenu();
void AddFood();
void RemoveFood();


void EditAvailabilityOfFoods();
void EditPriceOfFoods();
void EditPreparationTimeOfFoods();






//Functions for Customer
void WriteCustomerMainMenu();

//Functions for Kitchen




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

//Main oppening screen for customer
void WriteCustomerMainMenu() {
    printf("          REYETAP CUSTOMER MAIN MENU        \nPress : 1 for Ordering\nPress : 2 for Reviewing Active Order\nPress : 3 for viewing the Past Orders\n");
}

//Main oppening screen for restaurant
void WriteRestaurantMainMenu() {
    printf("          REYETAP RESTAURANT MAIN MENU        \nPress : 1 for Viewing the Orders\nPress : 2 for Viewing the Food List\nPress : 3 for Viewing the Active Orders\nPress : 4 for Viewing the Past Orders\nPress : 5 for Viewing the Kitchen\n");    
}

void CreateASampleFoodList(){
    //Creating a sample food list
    //foods have name , price and preparation time 
    //food list will be stored in a file called FoodList.txt
    FILE *file = fopen("FoodList.txt", "w");
    if (file == NULL) {
        printf("Error: FoodList.txt file could not be opened.\n");
        exit(1);
    }
    fprintf(file, "1. Hamburger - 15$ - Expected Preperation Iime = 10min  -   Available = Yes\n");
    fprintf(file, "2. Pizza - 20$ - Expected Preperation Iime = 15min  -   Available = Yes\n");
    fprintf(file, "3. Spaghetti - 10$ - Expected Preperation Iime = 8min  -   Available = Yes\n");
    fprintf(file, "4. Salad - 5$ - Expected Preperation Iime = 5min  -   Available = Yes\n");
    fprintf(file, "5. Soup - 7$ - Expected Preperation Iime = 6min  -   Available = Yes\n");

    fclose(file);                      
}





#endif // CREATINY_H