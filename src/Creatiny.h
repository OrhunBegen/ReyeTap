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

void EditFoodNameOfFoods();
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
    printf("          REYETAP RESTAURANT MAIN MENU        \nPress : 1 for Viewing the Orders\nPress : 2 for Viewing the Food List\nPress : 3 for Viewing the Active Orders\nPress : 4 for Viewing the Past Orders\nPress : 5 for changing the Food List.txt\n");    
}

//Food List Editing Menu
void EditFoodListMenu(){
    printf("          REYETAP RESTAURANT MAIN MENU        \nPress : 1 for Adding a Food\nPress : 2 for Removing a Food\nPress : 3 for Editing the Availability of Foods\nPress : 4 for Editing the Price of Foods\nPress : 5 for Editing the Preparation Time of Foods\n");
}

//Adding random foods to the food list
void CreateASampleFoodList()
{
    FILE *file = fopen("FoodList.txt", "w");
    if (file == NULL) {
        printf("Error: FoodList.txt file could not be opened.\n");
        exit(1);
    }
    fprintf(file, "1. Hamburger - 15$ - Expected Preperation Iime =1 hour 10 min  -   Available = Yes\n");
    fprintf(file, "2. Pizza - 20$ - Expected Preperation Iime =1 hour 30 min  -   Available = Yes\n");
    fprintf(file, "3. Spaghetti - 10$ - Expected Preperation Iime =1 hour 20 min  -   Available = Yes\n");
    fprintf(file, "4. Salad - 5$ - Expected Preperation Iime =1 hour 10 min  -   Available = Yes\n");
    fprintf(file, "5. Soup - 7$ - Expected Preperation Iime =1 hour 10 min  -   Available = Yes\n");
    fprintf(file, "6. Kebab - 25$ - Expected Preperation Iime =1 hour 40 min  -   Available = Yes\n");
    fprintf(file, "7. Meatball - 15$ - Expected Preperation Iime =1 hour 20 min  -   Available = Yes\n");

    fclose(file);                      
}


//Adding a food to the food list
void AddFood(){
    //This code Does not work properly
    // FILE *file = fopen("FoodList.txt", "a");
    // if (file == NULL) {
    //     printf("Error: FoodList.txt file could not be opened.\n");
    //     exit(1);
    // }
    // char foodName[100];
    // char price[100];
    // char prepTime[100];
    // char available[100];
    // printf("Enter the name of the food: ");
    // scanf("%s", foodName);
    // printf("Enter the price of the food: ");
    // scanf("%s", price);
    // printf("Enter the preparation time of the food: ");
    // scanf("%s", prepTime);
    // printf("Enter the availability of the food: ");
    // scanf("%s", available);
    
    // fprintf(file, "%s - %s$ - Expected Preperation Iime =%s  -   Available = %s\n", foodName, price, prepTime, available);
    // fclose(file);
}

void RemoveFood(){
    //This code Does not work properly
    // FILE *file = fopen("FoodList.txt", "r");
    // if (file == NULL) {
    //     printf("Error: FoodList.txt file could not be opened.\n");
    //     exit(1);
    // }
    // char foodName[100];
    // printf("Enter the name of the food you want to remove: ");
    // scanf("%s", foodName);
    // char line[100];
    // while (fgets(line, sizeof(line), file)) {
    //     if (strstr(line, foodName) == NULL) {
    //         fprintf(file, "%s", line);
    //     }
    // }
    // fclose(file);
}

void EditFoodNameOfTheFoods(){
    //This code Does not work properly
    // FILE *file = fopen("FoodList.txt", "r");
    // if (file == NULL) {
    //     printf("Error: FoodList.txt file could not be opened.\n");
    //     exit(1);
    // }
    // char foodName[100];
    // printf("Enter the name of the food you want to edit: ");
    // scanf("%s", foodName);
    // char line[100];
    // while (fgets(line, sizeof(line), file)) {
    //     if (strstr(line, foodName) != NULL) {
    //         char newFoodName[100];
    //         printf("Enter the new name of the food: ");
    //         scanf("%s", newFoodName);
    //         fprintf(file, "%s\n", newFoodName);
    //     }
    // }
    // fclose(file);

}

void EditAvailabilityOfFoods(){
    //This code Does not work properly
    // FILE *file = fopen("FoodList.txt", "r");
    // if (file == NULL) {
    //     printf("Error: FoodList.txt file could not be opened.\n");
    //     exit(1);
    // }
    // char foodName[100];
    // printf("Enter the name of the food you want to edit the availability: ");
    // scanf("%s", foodName);
    // char line[100];
    // while (fgets(line, sizeof(line), file)) {
    //     if (strstr(line, foodName) != NULL) {
    //         char available[100];
    //         printf("Enter the availability of the food: ");
    //         scanf("%s", available);
    //         fprintf(file, "%s\n", available);
    //     }
    // }
    // fclose(file);
}

void EditPriceOfFoods(){
    //This code Does not work properly
    // FILE *file = fopen("FoodList.txt", "r");
    // if (file == NULL) {
    //     printf("Error: FoodList.txt file could not be opened.\n");
    //     exit(1);
    // }
    // char foodName[100];
    // printf("Enter the name of the food you want to edit the price: ");
    // scanf("%s", foodName);
    // char line[100];
    // while (fgets(line, sizeof(line), file)) {
    //     if (strstr(line, foodName) != NULL) {
    //         char price[100];
    //         printf("Enter the price of the food: ");
    //         scanf("%s", price);
    //         fprintf(file, "%s\n", price);
    //     }
    // }
    // fclose(file);
}

void EditPreparationTimeOfFoods(){
    //This code Does not work properly
    // FILE *file = fopen("FoodList.txt", "r");
    // if (file == NULL) {
    //     printf("Error: FoodList.txt file could not be opened.\n");
    //     exit(1);
    // }
    // char foodName[100];
    // printf("Enter the name of the food you want to edit the preparation time: ");
    // scanf("%s", foodName);
    // char line[100];
    // while (fgets(line, sizeof(line), file)) {
    //     if (strstr(line, foodName) != NULL) {
    //         char prepTime[100];
    //         printf("Enter the preparation time of the food: ");
    //         scanf("%s", prepTime);
    //         fprintf(file, "%s\n", prepTime);
    //     }
    // }
    // fclose(file);
}




#endif // CREATINY_H