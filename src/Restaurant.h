#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h> // Include the standard C library
#include <string.h> // Include the string library
#include <stdlib.h> // Include the standard library
#include <ctype.h> // Add the missing import statement

//menu functions are here
int MenuForRestaurant();

//add function declarations here
void createFoodListFile();
void createOrdersFile();

void OpenFoodListFile();
void OpenOrdersFile();

void BringTheFoodList();
void BringTheOrdersList();

void CreateASampleFoodList();

int ScanfOnlyAlphabetic(char *str);
int ScanfOnlyNumeric(char *str);

void AddCustomFoodToTheFoodList();
void RemoveTheSelectedFoodFromTheFoodList();
void RenumberTheFoodList();
void AdjustTheSelectedFoodFromTheFoodList();


//add functions
int MenuForRestaurant() {
  
    

}

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

void OpenCustomFoodListFile() {
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if (file == NULL) {
        printf("Error: File not found\n");
    } else {
        printf("File opened successfully\n");
    }
    fclose(file);
}

void OpenOrdersFile() {
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if (file == NULL) {
        printf("Error: File not found\n");
    } else {
        printf("File opened successfully\n");
    }
    fclose(file);
}

void BringTheFoodList() {
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void BringTheOrdersList() {
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void CreateASampleFoodList()
{
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "w");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    fprintf(file, "Food Name -- Food Price TL -- Preperation Time (min) -- State\n");
    fprintf(file, "1 -- Hamburger -- 15 TL -- 10 -- Available\n");
    fprintf(file, "2 -- Cheeseburger -- 20 TL -- 15 -- Available\n");
    fprintf(file, "3 -- Chicken Burger -- 18 TL -- 12 -- Available\n");
    fprintf(file, "4 -- Fish Burger -- 25 TL -- 20 -- Available\n");
    fprintf(file, "5 -- Veggie Burger -- 17 TL -- 13 -- Available\n");
    fprintf(file, "6 -- French Fries -- 10 TL -- 5 -- Available\n");
    fprintf(file, "7 -- Onion Rings -- 12 TL -- 7 -- Available\n");
   
    fclose(file);
}

int ScanfOnlyNumeric(char *str) {
    //check if the string is numeric
    //if it is not numeric return 0
    //if it is numeric return 1
    //cant be negative
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
<<<<<<< Updated upstream
    }
    
=======
    }   
    //return 1 str sayısalsa 
>>>>>>> Stashed changes
}

int ScanfOnlyAlphabetic(char *str) {
       //or space
       // Loop through each character in the string
    while (*str != '\0') {
        // Check if the character is alphabetic or a space
        if (!isalpha(*str) && *str != ' ') {
            // If it's not alphabetic or a space, return 0
            return 0;
        }
        // Move to the next character
        str++;
    }
    // If all characters are alphabetic or spaces, return 1
    return 1;

}




void AddCustomFoodToTheFoodList()
{

    BringTheFoodList();

    printf("\nDo you want to add a new food to the food list? (1 for yes /0 for no): ");
    //non numeric characters are not allowed
    //if user enters a non numeric character ask for the answer again
    char answer[2];
    int validAnswer = 0;
    while (!validAnswer) {
        scanf("%s", answer);
        validAnswer = ScanfOnlyNumeric(answer) && (strcmp(answer, "0") == 0 || strcmp(answer, "1") == 0);
        if (!validAnswer) {
            printf("Non-numeric characters are not allowed. Please enter 1 for yes or 0 for no.\n");
        }
    }
    if (strcmp(answer, "0") == 0)
    {
        return;
    }
    else 
    {
        system("cls");
    }
    
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "a");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
  
    //food list name max 20 characters
    //food price max 10 characters only numbers
    //preparation time max 5 characters only numbers
    //status max 20 characters

    char foodName[30];
    char foodPrice[10];
    char preparationTime[5];
    char status[20];

    //food name
    //non alphabetic characters are not allowed 
    /*
    it will ask the user to enter another food name 
    if user enters a non alphabetic character ask for the food name again or give option to exit by entering "q"
    */

    int validFoodName = 0;
    while (!validFoodName) {
        printf("Enter the food name or enter 'q' to cancel the request: ");
        
        scanf(" %[^\n]", foodName);
        
        if (strcmp(foodName, "q") == 0) {
            fclose(file);
            return;
        }
        validFoodName = ScanfOnlyAlphabetic(foodName);
        if (!validFoodName) {
            printf("Non-alphabetic characters are not allowed. Please enter another food name or enter 'q' to cancel the request.\n");
        }
    }
   
    
    //food price
    //non numeric characters are not allowed
    /*
    it will ask the user to enter another food price
    if user enters a non numeric character ask for the food price again or give option to exit by entering "q"
    */

    int validFoodPrice = 0;
    while (!validFoodPrice) {
        printf("Enter the food price or enter 'q' to cancel the request ");
        scanf("%s", foodPrice);
        if (strcmp(foodPrice, "q") == 0) {
            fclose(file);
            return;
        }
        validFoodPrice = ScanfOnlyNumeric(foodPrice);
        if (!validFoodPrice) {
            printf("Non-numeric characters are not allowed. Please enter another food price or enter 'q' to cancel the request.\n");
        }
    }

    //preparation time
    //non numeric characters are not allowed
    /*
    it will ask the user to enter another preparation time
    if user enters a non numeric character ask for the preparation time again or give option to exit by entering "q"
    */

    int validPreparationTime = 0;
    while (!validPreparationTime) {
        printf("Enter the preparation time or enter 'q' to cancel the request: ");
        scanf("%s", preparationTime);
        if (strcmp(preparationTime, "q") == 0) {
            fclose(file);
            return;
        }
        validPreparationTime = ScanfOnlyNumeric(preparationTime);
        if (!validPreparationTime) {
            printf("Non-numeric characters are not allowed. Please enter another preparation time or enter 'q' to cancel the request.\n");
        }
    }

    //status
    //enterer can only enter 1 for available or 0 for unavailable
    //non numeric characters are not allowed
    /*
    it will ask the user to enter another status
    if user enters a non numeric character ask for the status again or give option to exit by entering "q"
    */

    int validStatus = 0;
    while (!validStatus) {
        printf("Enter the status or enter 'q' to cancel the request (1 for available, 0 for unavailable): ");
        scanf("%s", status);
        if (strcmp(status, "q") == 0) {
            fclose(file);
            return;
        }
        validStatus = ScanfOnlyNumeric(status) && (strcmp(status, "0") == 0 || strcmp(status, "1") == 0);
        if (!validStatus) {
            printf("Non-numeric characters are not allowed. Please enter another status or enter 'q' to cancel the request.\n");
        }
    }
    //convert status to available or unavailable
    if (strcmp(status, "1") == 0) {
        strcpy(status, "Available");
    } else {
        strcpy(status, "Unavailable");
    }
    
    //find how many foods are in the FoodList.txt by the 1- 2- 3- 4- 5-
    FILE *file2;
    file2 = fopen("TextFiles/FoodList.txt", "r");
    if(file2 == NULL) {
        printf("Error: File not found\n");
        
    }
    int lineCount = 0;
    char line[100];
    while (fgets(line, sizeof(line), file2)) {
        lineCount++;
    }
    fclose(file2);

    //add the new food to the FoodList.txt
    fprintf(file, "%d -- %s -- %s TL -- %s -- %s\n", lineCount, foodName, foodPrice, preparationTime, status);
    
    //succsess message
    printf("The food has been added to the food list.\n");
    fclose(file);
    system("cls");
}

void RemoveTheSelectedFoodFromTheFoodList()
{
  BringTheFoodList();
    printf("\nDo you want to remove a food from the food list? (1 for yes /0 for no): ");
    //non numeric characters are not allowed
    //if user enters a non numeric character ask for the answer again
    char answer[2];
    int validAnswer = 0;
    while (!validAnswer) {
        scanf("%s", answer);
        validAnswer = ScanfOnlyNumeric(answer) && (strcmp(answer, "0") == 0 || strcmp(answer, "1") == 0);
        if (!validAnswer) {
            printf("Non-numeric characters are not allowed. Please enter 1 for yes or 0 for no.\n");
        }
    }
    if (strcmp(answer, "0") == 0)
    {
        return;
    }

    //enter the food number to remove
    //non numeric characters are not allowed
    /*
    it will ask the user to enter another food number
    if user enters a non numeric character ask for the food number again or give option to exit by entering "q"
    */

    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    int lineCount = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }
    fclose(file);
    

    //ask for the food number to remove
    //if the user enters a non numeric character ask for the food number again or give option to exit by entering "q"

    char foodNumber[10];
    int validFoodNumber = 0;

    while (!validFoodNumber) {
        printf("Enter the food number to remove or enter 'q' to cancel the request: ");
        scanf("%s", foodNumber);
        if (strcmp(foodNumber, "q") == 0) {
            return;
        }
        validFoodNumber = ScanfOnlyNumeric(foodNumber) && atoi(foodNumber) > 0 && atoi(foodNumber) < lineCount;
        if (!validFoodNumber) {
            printf("Non-numeric characters are not allowed. Please enter another food number or enter 'q' to cancel the request.\n");
        }
    }    
    
    //add 1 to the line from going to remove line because the last line is the "Food Name -- Food Price TL -- Preperation Time (min) -- State"
    
    int currentFoodNumber = atoi(foodNumber);
    currentFoodNumber++;
    sprintf(foodNumber, "%d", currentFoodNumber);

    
    //remove the selected food from the FoodList.txt
    FILE *file2;
    file2 = fopen("TextFiles/FoodList.txt", "r");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    FILE *file3;
    file3 = fopen("TextFiles/FoodListTemp.txt", "w");
    if(file3 == NULL) {
        printf("Error: File not found\n");
    }
    int count = 0;
    while (fgets(line, sizeof(line), file2)) {
        count++;
        if (count != atoi(foodNumber)) {
            fprintf(file3, "%s", line);
        }
    }
    fclose(file2);
    fclose(file3);
    remove("TextFiles/FoodList.txt");
    rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");

}

void RenumberTheFoodList()
{
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    FILE *file2;
    file2 = fopen("TextFiles/FoodListTemp.txt", "w");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == 1) {
            fprintf(file2, "%s", line);
        } else {
            fprintf(file2, "%d -- %s", count - 1, line + 4);
        }
    }
    fclose(file);
    fclose(file2);
    remove("TextFiles/FoodList.txt");
    rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");
}

void AdjustTheSelectedFoodFromTheFoodList()
{
    //bring the food list
    BringTheFoodList();

    //ask for the food number to adjust
    //if the user enters a non numeric character ask for the food number again or give option to exit by entering "q"

    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    int lineCount = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }
    fclose(file);

    //ask for the food number to adjust
    char foodNumber[10];
    int validFoodNumber = 0;

    while (!validFoodNumber) {
        printf("Enter the food number to adjust or enter 'q' to cancel the request: ");
        scanf("%s", foodNumber);
        if (strcmp(foodNumber, "q") == 0) {
            return;
        }
        validFoodNumber = ScanfOnlyNumeric(foodNumber) && atoi(foodNumber) > 0 && atoi(foodNumber) < lineCount;
        if (!validFoodNumber) {
            printf("Non-numeric characters are not allowed. Please enter another food number or enter 'q' to cancel the request.\n");
        }
    }

    //print the selected food
    FILE *file2;
    file2 = fopen("TextFiles/FoodList.txt", "r");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    int currentFoodNumber = atoi(foodNumber);
    currentFoodNumber++;
    sprintf(foodNumber, "%d", currentFoodNumber);
    int count = 0;
    while (fgets(line, sizeof(line), file2)) {
        count++;
        if (count == atoi(foodNumber)) {
            printf("%s", line);
        }
    }
    fclose(file2);


    //ask which part of the food to adjust
    //1 for food name
    //2 for food price
    //3 for preparation time
    //4 for status
    //if the user enters a non numeric character ask for the part again or give option to exit by entering "q"
    
    char part[2];
    int validPart = 0;

    while (!validPart) {
        printf("Enter the part to adjust (1 for food name, 2 for food price, 3 for preparation time, 4 for status) or enter 'q' to cancel the request: ");
        scanf("%s", part);
        if (strcmp(part, "q") == 0) {
            return;
        }
        validPart = ScanfOnlyNumeric(part) && (strcmp(part, "1") == 0 || strcmp(part, "2") == 0 || strcmp(part, "3") == 0 || strcmp(part, "4") == 0);
        if (!validPart) {
            printf("Non-numeric characters are not allowed. Please enter another part or enter 'q' to cancel the request.\n");
        }
    }

    //if the user enters 1 for food name
    //if the user enters 2 for food price
    //if the user enters 3 for preparation time
    //if the user enters 4 for status
    int currentPart = atoi(part);
        
    if (currentPart == 1) {
 
    } 
    else if (currentPart == 2){
  
    }
    else if (currentPart == 3) {
        
    }
    else if (currentPart == 4) {
        
    }
    else {
        printf("Invalid part number. Please enter a valid part number.\n");
    }

}




#endif // RESTAURANT_H