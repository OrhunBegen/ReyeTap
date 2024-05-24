#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h> // Include the standard C library
#include <string.h> // Include the string library
#include <stdlib.h> // Include the standard library
#include <ctype.h> // Include the ctype library
#include <windows.h> // Include the windows library

#include "Kitchen.h"

typedef struct AllTimeFood {
    
    int FoodName;
    int FoodPrice;
    int Quantity;

} AllTimeFood;


void AllTimeFoodDat()
{
    FILE *file;
    file = fopen("AllTimeFood.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(file);

}

// Function prototypes
void RestaurantMainMenu();

void createFoodListFile();
void createOrdersFile();

void OpenCustomFoodListFile();
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
void AddTitle();


//order applications

int CheckIfTheFoodIsAtWaitState(int LineNumber);
void BringTheOrdersList();
int AproveOrDeclineSystem();
void DeclineTheOrder(int LineNumber);
void AproveTheOrder(int LineNumber);

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
    }
    
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
    
    printf("\nDo you want to adjust a food from the food list? (1 for yes /0 for no): ");
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

    //enter the food number to adjust
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

    //print the food line that u are making adjustments
    //ask for the food number to adjust
    //if the user enters a non numeric character ask for the food number again or give option to exit by entering "q"

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

    //add 1 to the line from going to remove line because the last line is the "Food Name -- Food Price TL -- Preperation Time (min) -- State"

    int currentFoodNumber = atoi(foodNumber);


    //print the food line that u are making adjustments
    
    FILE *file2;
    file2 = fopen("TextFiles/FoodList.txt", "r");
    
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    int count = 0;
    while (fgets(line, sizeof(line), file2)) {
        count++;
        if (count == atoi(foodNumber)+1) {
            printf("%s", line);
        }
    }
    fclose(file2);

    //ask which part of the food line to adjust
    //1 for food name
    //2 for food price
    //3 for preparation time
    //4 for status
    //non numeric characters are not allowed
    //if the user enters a non numeric character ask for the part again or give option to exit by entering "q"

    char part[10];
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

    //which part to adjust is to integer
    int PartNumber = atoi(part);
    
    //1 for food name
    //2 for food price
    //3 for preparation time
    //4 for status

    if(PartNumber == 1)
    {
        //food name
        //non alphabetic characters are not allowed 
        /*
        it will ask the user to enter another food name 
        if user enters a non alphabetic character ask for the food name again or give option to exit by entering "q"
        */

        char NewfoodName[30];
        int validFoodName = 0;

        while (!validFoodName) {
            printf("Enter the new food name or enter 'q' to cancel the request: ");
            scanf(" %[^\n]", NewfoodName);
            if (strcmp(NewfoodName, "q") == 0) {
                return;
            }
            validFoodName = ScanfOnlyAlphabetic(NewfoodName);
            if (!validFoodName) {
                printf("Non-alphabetic characters are not allowed. Please enter another food name or enter 'q' to cancel the request.\n");
            }
        }

        //from the first "--" sign delete it until the next "--" sign


        FILE *file3;
        file3 = fopen("TextFiles/FoodList.txt", "r");
        if(file3 == NULL) {
            printf("Error: File not found\n");
        }
        FILE *file4;
        file4 = fopen("TextFiles/FoodListTemp.txt", "w");
        if(file4 == NULL) {
            printf("Error: File not found\n");
        }
       
        while (fgets(line, sizeof(line), file3)) {
            int currentFoodNumber;
            char foodName[30];
            char foodPrice[10];
            char preparationTime[5];
            char state[20];

            // Parse the line into different fields
            if (sscanf(line, "%d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^\n]", &currentFoodNumber, foodName, foodPrice, preparationTime, state) == 5) {
                // Check if this is the line to be modified based on currentFoodNumber
                if (currentFoodNumber == atoi(foodNumber)) {
                    // Update the food name with NewfoodName
                    fprintf(file4, "%d -- %s -- %s TL -- %s -- %s\n", currentFoodNumber, NewfoodName, foodPrice, preparationTime, state);
                } else {
                    // Write the unchanged line to the temporary file
                    fprintf(file4, "%s", line);
                }
            }
        }





        fclose(file3);
        fclose(file4);  
        remove("TextFiles/FoodList.txt");
        rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");
}

    if(PartNumber == 2){
    // food price
    // non-numeric characters are not allowed
    /*
    it will ask the user to enter another food price
    if the user enters a non-numeric character, ask for the food price again or give the option to exit by entering "q"
    */
    char NewfoodPrice[10];
    int validFoodPrice = 0;

    while (!validFoodPrice) {
        printf("Enter the new food price or enter 'q' to cancel the request: ");
        scanf("%s", NewfoodPrice);
        if (strcmp(NewfoodPrice, "q") == 0) {
            return;
        }
        validFoodPrice = ScanfOnlyNumeric(NewfoodPrice);
        if (!validFoodPrice) {
            printf("Non-numeric characters are not allowed. Please enter another food price or enter 'q' to cancel the request.\n");
        }
    }

    FILE *file3 = fopen("TextFiles/FoodList.txt", "r");
    if (file3 == NULL) {
        printf("Error: File not found\n");
        return;
    }

    FILE *file4 = fopen("TextFiles/FoodListTemp.txt", "w");
    if (file4 == NULL) {
        printf("Error: Temporary file creation failed\n");
        fclose(file3);
        return;
    }

    char line[100]; 

    
    while (fgets(line, sizeof(line), file3)) {
        int currentFoodNumber;
        char foodName[30];
        char foodPrice[10];
        char preparationTime[5];
        char state[20];


        // Parse the line into different fields
        if (sscanf(line, "%d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^\n]", &currentFoodNumber, foodName, foodPrice, preparationTime, state) == 5) {
            // Check if this is the line to be modified based on currentFoodNumber
            if (currentFoodNumber == atoi(foodNumber)) {
                // Update the food price with NewfoodPrice
                fprintf(file4, "%d -- %s -- %s TL -- %s -- %s\n", currentFoodNumber, foodName, NewfoodPrice, preparationTime, state);
            } else {
                // Write the unchanged line to the temporary file
                fprintf(file4, "%s", line);
            }
        }
    }

    fclose(file3);
    fclose(file4);
    remove("TextFiles/FoodList.txt");
    rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");
    }

    if(PartNumber == 3){
    
    // preparation time
    // non-numeric characters are not allowed
    /*
    it will ask the user to enter another preparation time
    if the user enters a non-numeric character, ask for the preparation time again or give the option to exit by entering "q"
    */
    char NewpreparationTime[5];
    int validPreparationTime = 0;

    while (!validPreparationTime) {
        printf("Enter the new preparation time or enter 'q' to cancel the request: ");
        scanf("%s", NewpreparationTime);
        if (strcmp(NewpreparationTime, "q") == 0) {
            return;
        }
        validPreparationTime = ScanfOnlyNumeric(NewpreparationTime);
        if (!validPreparationTime) {
            printf("Non-numeric characters are not allowed. Please enter another preparation time or enter 'q' to cancel the request.\n");
        }
    }

    FILE *file3 = fopen("TextFiles/FoodList.txt", "r");
    if (file3 == NULL) {
        printf("Error: File not found\n");
        return;
    }

    FILE *file4 = fopen("TextFiles/FoodListTemp.txt", "w");
    if (file4 == NULL) {
        printf("Error: Temporary file creation failed\n");
        fclose(file3);
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file3)) {
        int currentFoodNumber;
        char foodName[30];
        char foodPrice[10];
        char preparationTime[5];
        char state[20];

        // Parse the line into different fields
        if (sscanf(line, "%d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^\n]", &currentFoodNumber, foodName, foodPrice, preparationTime, state) == 5) {
            // Check if this is the line to be modified based on currentFoodNumber
            if (currentFoodNumber == atoi(foodNumber)) {
                // Update the preparation time with NewpreparationTime
                fprintf(file4, "%d -- %s -- %s TL -- %s -- %s\n", currentFoodNumber, foodName, foodPrice, NewpreparationTime, state);
            } else {
                // Write the unchanged line to the temporary file
                fprintf(file4, "%s", line);
            }
        }
    }
    fclose(file3);
    fclose(file4);
    remove("TextFiles/FoodList.txt");
    rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");

}
    if (PartNumber == 4){
    // status
    // enterer can only enter 1 for available or 0 for unavailable
    // non-numeric characters are not allowed
    /*
    it will ask the user to enter another status
    if the user enters a non-numeric character, ask for the status again or give the option to exit by entering "q"
    */

    char Newstatus[20];
    int validStatus = 0;

    while (!validStatus) {
        printf("Enter the new status or enter 'q' to cancel the request (1 for available, 0 for unavailable): ");
        scanf("%s", Newstatus);
        if (strcmp(Newstatus, "q") == 0) {
            return;
        }
        validStatus = ScanfOnlyNumeric(Newstatus) && (strcmp(Newstatus, "0") == 0 || strcmp(Newstatus, "1") == 0);
        if (!validStatus) {
            printf("Non-numeric characters are not allowed. Please enter another status or enter 'q' to cancel the request.\n");
        }
    }

    //convert status to available or unavailable
    if (strcmp(Newstatus, "1") == 0) {
        strcpy(Newstatus, "Available");
    } else {
        strcpy(Newstatus, "Unavailable");
    }

    FILE *file3 = fopen("TextFiles/FoodList.txt", "r");

    if (file3 == NULL) {
        printf("Error: File not found\n");
        return;
    }

    FILE *file4 = fopen("TextFiles/FoodListTemp.txt", "w");

    if (file4 == NULL) {
        printf("Error: Temporary file creation failed\n");
        fclose(file3);
        return;
    }





    char line[100];

    while (fgets(line, sizeof(line), file3)) {
        int currentFoodNumber;
        char foodName[30];
        char foodPrice[10];
        char preparationTime[5];
        char state[20];

        // Parse the line into different fields
        if (sscanf(line, "%d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^\n]", &currentFoodNumber, foodName, foodPrice, preparationTime, state) == 5) {
            // Check if this is the line to be modified based on currentFoodNumber
            if (currentFoodNumber == atoi(foodNumber)) {
                // Update the status with Newstatus
                fprintf(file4, "%d -- %s -- %s TL -- %s -- %s\n", currentFoodNumber, foodName, foodPrice, preparationTime, Newstatus);
            } else {
                // Write the unchanged line to the temporary file
                fprintf(file4, "%s", line);
            }
        }
    }
    fclose(file3);
    fclose(file4);
    remove("TextFiles/FoodList.txt");
    rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");
}
}

void AddTitle()
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

    fprintf(file2, "Food Name -- Food Price TL -- Preperation Time (min) -- State\n");

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        fprintf(file2, "%s", line);
    }
    fclose(file);
    fclose(file2);

    remove("TextFiles/FoodList.txt");
    rename("TextFiles/FoodListTemp.txt", "TextFiles/FoodList.txt");

    

    
}





//Order Applications



int CheckIfTheFoodIsAtWaitState(int LineNumber)
{
    // 1 -- 2024/5/24_2 -- Fish Burger  -- 25  TL -- 20  -- mustafa -- Wait
    // 2 -- 2024/5/24_2 -- French Fries  -- 10  TL -- 5  -- mustafa -- Wait
    // 3 -- 2024/5/24_6 -- Fish Burger  -- 25  TL -- 20  -- orhun -- SIP
    // 4 -- 2024/5/24_6 -- Onion Rings  -- 12  TL -- 7  -- orhun -- RED

    //if Wait return 1
    //if not Wait return 0

    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    char Year[5];
    char Month[3];
    char Day[3];
    char FoodName [30];
    char FoodPrice[10];
    char PreparationTime[5];
    char CustomerName[30];
    char State[10];

    int count = 0;


    //parse the line
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == LineNumber) {
            sscanf(line, "%*d -- %[^/] / %[^/] / %[^_] _ %*d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^--] -- %s", Year, Month, Day, FoodName, FoodPrice, PreparationTime, CustomerName, State);
            if (strcmp(State, "Wait") == 0) {
                fclose(file);
                return 1;
            } else {
                fclose(file);
                return 0;
            }
        }
    }


    fclose(file);
}

void BringTheOrderList()
{  
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

int AproveOrDeclineSystem()
{
    // 1 -- 2024/5/24_2 -- Fish Burger  -- 25  TL -- 20  -- mustafa -- Wait
    // 2 -- 2024/5/24_2 -- French Fries  -- 10  TL -- 5  -- mustafa -- Wait
    // 3 -- 2024/5/24_6 -- Fish Burger  -- 25  TL -- 20  -- orhun -- SIP
    // 4 -- 2024/5/24_6 -- Onion Rings  -- 12  TL -- 7  -- orhun -- RED

    //if the food is in the Wait state ask for the user to aprove or decline the order
    //if the food is in the SIP or RED state do not ask for the user to aprove or decline the order
    //if the user aproves the order return 1
    //if the user declines the order return 0

    BringTheOrderList();
    printf("\nDo you want to aprove or decline an order? (1 for yes /0 for no): ");
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
        return 0;
    }

    char orderNumber[10];
    //enter the order number to aprove or decline
    //non numeric characters are not allowed
    /*
    it will ask the user to enter another order number
    if user enters a non numeric character ask for the order number again or give option to exit by entering "q"
    */
   
    int validOrderNumber = 0;
    while (!validOrderNumber) {
        printf("Enter the order number to aprove or decline or enter 'q' to cancel the request: ");
        scanf("%s", orderNumber);
        if (strcmp(orderNumber, "q") == 0) {
            return 0;
        }
        validOrderNumber = ScanfOnlyNumeric(orderNumber);
        if (!validOrderNumber) {
            printf("Non-numeric characters are not allowed. Please enter another order number or enter 'q' to cancel the request.\n");
        }
    }

    //check if the food is in the Wait state
    
    int waitState = CheckIfTheFoodIsAtWaitState(atoi(orderNumber));

    if (waitState == 0) {
        printf("The food is not in the Wait state. You can not aprove or decline the order.\n");
        return 0;
    }

    //ask for the user to aprove or decline the order
    //1 for aprove
    //0 for decline
    //then it will call the AproveOrder() or DeclineOrder() function

    char answer2[2];

    int validAnswer2 = 0;
    while (!validAnswer2) {
        printf("Do you want to aprove or decline the order? (1 for aprove, 0 for decline): ");
        scanf("%s", answer2);
        validAnswer2 = ScanfOnlyNumeric(answer2) && (strcmp(answer2, "0") == 0 || strcmp(answer2, "1") == 0);
        if (!validAnswer2) {
            printf("Non-numeric characters are not allowed. Please enter 1 for aprove or 0 for decline.\n");
        }
    }
    
    int orderNumberInt = atoi(orderNumber);

    if (strcmp(answer2, "0") == 0) {
        DeclineTheOrder(orderNumberInt);
    } else {
        AproveTheOrder(orderNumberInt);
    }
}

void DeclineTheOrder(int orderNumber)
{
    //then change the state to RED
    char line[100];
    char Year[5];
    char Month[3];
    char Day[3];
    char FoodName [30];
    char FoodPrice[10];
    char PreparationTime[5];
    char CustomerName[30];
    char State[10];

    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    FILE *file2;
    file2 = fopen("TextFiles/OrderListTemp.txt", "w");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == orderNumber) {
            sscanf(line, "%*d -- %[^/] / %[^/] / %[^_] _ %*d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^--] -- %s", Year, Month, Day, FoodName, FoodPrice, PreparationTime, CustomerName, State);
            fprintf(file2, "%d -- %s/%s/%s_%d -- %s-- %sTL -- %s-- %s-- RED\n", count, Year, Month, Day, orderNumber, FoodName, FoodPrice, PreparationTime, CustomerName);
        } else {
            fprintf(file2, "%s", line);
        }
    }
    fclose(file);
    fclose(file2);
    remove("TextFiles/OrderList.txt");
    rename("TextFiles/OrderListTemp.txt", "TextFiles/OrderList.txt");
    printf("The order has been declined.\n");

}

void AproveTheOrder(int orderNumber)
{
    //then change the state to SIP
    char line[100];
    
    char Year[5];
    char Month[3];
    char Day[3];
    char ID[5];

    char FoodName [30];
    char FoodPrice[10];
    char PreparationTime[5];
    char CustomerName[30];
    char State[10];

    int CurrentMinute;
    int CurrentHour;
    int CurrentDay;
    int CurrentMonth;
    int CurrentYear;

    int ReadyMinute;
    int ReadyHour;
    int ReadyDay;
    int ReadyMonth;
    int ReadyYear;

    //get the current time

    SYSTEMTIME t;
    GetLocalTime(&t);
    CurrentMinute = t.wMinute;
    CurrentHour = t.wHour;
    CurrentDay = t.wDay;
    CurrentMonth = t.wMonth;
    CurrentYear = t.wYear;



    //from the file get The Prep time and CurrentTime's + PreparationTime = ReadyTime
    //if the ReadyTime is bigger than 60 add 1 to the hour and make the ReadyTime - 60
    //if the ReadyTime is bigger than 24 add 1 to the day and make the ReadyTime - 24
    //if the ReadyTime is bigger than 12 add 1 to the month and make the ReadyTime - 12
    //if the ReadyTime is bigger than 2024 add 1 to the year and make the ReadyTime - 2024

    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    //parse the line
     //line -- Year/Month/Day_ID -- FoodName -- FoodPrice TL -- PreparationTime -- CustomerName -- State -- CurrentTime -- ReadyTime
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%*d -- %[^/] / %[^/] / %[^_] _ %[^--] -- %[^--] -- %[^TL] TL -- %[^--] -- %[^--] -- %s", Year, Month, Day, ID, FoodName, FoodPrice, PreparationTime, CustomerName, State);
        if (atoi(ID) == orderNumber) {
            ReadyMinute = CurrentMinute + atoi(PreparationTime);
            ReadyHour = CurrentHour;
            ReadyDay = CurrentDay;
            ReadyMonth = CurrentMonth;
            ReadyYear = CurrentYear;
            if (ReadyMinute >= 60) {
                ReadyHour++;
                ReadyMinute -= 60;
            }
            if (ReadyHour >= 24) {
                ReadyDay++;
                ReadyHour -= 24;
            }
            if (ReadyDay >= 31) {
                ReadyMonth++;
                ReadyDay -= 31;
            }
            if (ReadyMonth >= 12) {
                ReadyYear++;
                ReadyMonth -= 12;
            }
            break;
        }
    }
    fclose(file);

    //From The Cooks.dat loop through the file and get the first AsciID that has smaller time than the current time




    int AsciID = -1;
    FILE *file8;
    file8 = fopen("TextFiles/Cooks.dat", "r");
    if(file8 == NULL) {
        printf("Error: File not found\n");
    }
    int AsciIDTemp;
    int CookMinute;
    int CookHour;
    int CookDay;
    int CookMonth;
    int CookYear;


    while (fread(&AsciIDTemp, sizeof(int), 1, file8)) {
        fread(&CookMinute, sizeof(int), 1, file8);
        fread(&CookHour, sizeof(int), 1, file8);
        fread(&CookDay, sizeof(int), 1, file8);
        fread(&CookMonth, sizeof(int), 1, file8);
        fread(&CookYear, sizeof(int), 1, file8);
        if (CookYear < CurrentYear) {
            AsciID = AsciIDTemp;
            break;
        } else if (CookYear == CurrentYear) {
            if (CookMonth < CurrentMonth) {
                AsciID = AsciIDTemp;
                break;
            } else if (CookMonth == CurrentMonth) {
                if (CookDay < CurrentDay) {
                    AsciID = AsciIDTemp;
                    break;
                } else if (CookDay == CurrentDay) {
                    if (CookHour < CurrentHour) {
                        AsciID = AsciIDTemp;
                        break;
                    } else if (CookHour == CurrentHour) {
                        if (CookMinute < CurrentMinute) {
                            AsciID = AsciIDTemp;
                            break;
                        }
                    }
                }
            }
        }
    }
    fclose(file8);

    if (AsciID == -1) {
        printf("There is no cook available to prepare the food.\n");
        return;
    }



    //change the state to SIP

    FILE *file2;
    file2 = fopen("TextFiles/OrderListTemp.txt", "w");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == orderNumber) {
            fprintf(file2, "%d -- %s/%s/%s_%s -- %s-- %sTL -- %s-- %s-- SIP -- %d/%d/%d_%d:%d -- %d/%d/%d_%d:%d -- %sA\n",
            count, Year, Month, Day, ID, FoodName, FoodPrice, PreparationTime, CustomerName,
            CurrentYear, CurrentMonth, CurrentDay, CurrentHour, CurrentMinute, 
            ReadyYear, ReadyMonth, ReadyDay, ReadyHour, ReadyMinute, AsciID);
        } else {
            fprintf(file2, "%s", line);
        }
    }

    fclose(file);
    fclose(file2);
    remove("TextFiles/OrderList.txt");
    rename("TextFiles/OrderListTemp.txt", "TextFiles/OrderList.txt");
    printf("The order has been aproved.\n");
}



#endif // RESTAURANT_H


