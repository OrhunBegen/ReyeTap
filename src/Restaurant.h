#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h> // Include the standard C library
#include <string.h> // Include the string library
#include <stdlib.h> // Include the standard library
#include <ctype.h> // Include the ctype library
#include <windows.h> // Include the windows library

#include "Kitchen.h"

typedef struct FoodList
{
    int FoodQuantity;
    int FoodPrice;
    char FoodName[30];
}FoodList;


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

void AllTimeFoodDat();

//order applications

int CheckIfTheFoodIsAtWaitState(int LineNumber);
void BringTheOrdersList();
int AproveOrDeclineSystem();
void DeclineTheOrder(int LineNumber);
void AproveTheOrder(int LineNumber);

void BetweenTwoDatesGetTheTotalSellMoney();
void DailyTotalSellMoney();


void BetweenTwoDatesGetTheTotalSellMoney()
{
  
    printf("Enter the year: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the year again
    char year[5];
    int validYear = 0;
    while (!validYear) {
        scanf("%s", year);
        validYear = ScanfOnlyNumeric(year) && atoi(year) > 0;
        if (!validYear) {
            printf("Non-numeric characters are not allowed. Please enter the year again.\n");
        }
    }

    printf("Enter the month: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the month again
    char month[3];
    int validMonth = 0;
    while (!validMonth) {
        scanf("%s", month);
        validMonth = ScanfOnlyNumeric(month) && atoi(month) > 0 && atoi(month) < 13;
        if (!validMonth) {
            printf("Non-numeric characters are not allowed. Please enter the month again.\n");
        }
    }

    printf("Enter the day: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the day again
    char day[3];
    int validDay = 0;
    while (!validDay) {
        scanf("%s", day);
        validDay = ScanfOnlyNumeric(day) && atoi(day) > 0 && atoi(day) < 32;
        if (!validDay) {
            printf("Non-numeric characters are not allowed. Please enter the day again.\n");
        }
    }

    printf("Enter the year1: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the year1 again
    char year1[5];
    int validYear1 = 0;
    while (!validYear1) {
        scanf("%s", year1);
        validYear1 = ScanfOnlyNumeric(year1) && atoi(year1) > 0;
        if (!validYear1) {
            printf("Non-numeric characters are not allowed. Please enter the year1 again.\n");
        }
    }

    printf("Enter the month1: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the month1 again
    char month1[3];
    int validMonth1 = 0;
    while (!validMonth1) {
        scanf("%s", month1);
        validMonth1 = ScanfOnlyNumeric(month1) && atoi(month1) > 0 && atoi(month1) < 13;
        if (!validMonth1) {
            printf("Non-numeric characters are not allowed. Please enter the month1 again.\n");
        }
    }

    printf("Enter the day1: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the day1 again
    char day1[3];
    int validDay1 = 0;
    while (!validDay1) {
        scanf("%s", day1);
        validDay1 = ScanfOnlyNumeric(day1) && atoi(day1) > 0 && atoi(day1) < 32;
        if (!validDay1) {
            printf("Non-numeric characters are not allowed. Please enter the day1 again.\n");
        }
    }
    //year-month-day.txt  year1-month1-day1.txt between these two dates
    //find the total sell money
    //print the total sell money

    if(year1 < year)
    {
        printf("Invalid date range\n");
        return;
    }
    if(year1 == year && month1 < month)
    {
        printf("Invalid date range\n");
        return;
    }
    if(year1 == year && month1 == month && day1 < day)
    {
        printf("Invalid date range\n");
        return;
    }

}

void DailyTotalSellMoney()
{
    int OrderNumber;
    int Year;
    int Month;
    int Day;
    int CustomerID;

    char FoodName[50];
    char Price[50];
    char PrepTime[50];
    char UserName[50];
    char State[50];

    int AcceptYear;
    int AcceptMonth;
    int AcceptDay;
    int AcceptHour;
    int AcceptMinute;

    int ReadyYear;
    int ReadyMonth;
    int ReadyDay;
    int ReadyHour;
    int ReadyMinute;

    char CooksID[4];

    //can only enter numbers cant be negative
    printf("Enter the year: ");
    //if the user enters a non-numeric character ask for the year again
    char year[5];
    int validYear = 0;
    while (!validYear) {
        scanf("%s", year);
        validYear = ScanfOnlyNumeric(year) && atoi(year) > 0;
        if (!validYear) {
            printf("Non-numeric characters are not allowed. Please enter the year again.\n");
        }
    }

    printf("Enter the month: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the month again
    char month[3];
    int validMonth = 0;
    while (!validMonth) {
        scanf("%s", month);
        validMonth = ScanfOnlyNumeric(month) && atoi(month) > 0 && atoi(month) < 13;
        if (!validMonth) {
            printf("Non-numeric characters are not allowed. Please enter the month again.\n");
        }
    }

    printf("Enter the day: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the day again
    char day[3];
    int validDay = 0;
    while (!validDay) {
        scanf("%s", day);
        validDay = ScanfOnlyNumeric(day) && atoi(day) > 0 && atoi(day) < 32;
        if (!validDay) {
            printf("Non-numeric characters are not allowed. Please enter the day again.\n");
        }
    }

    //if the file is not found print "No orders have been made on this date or date is wrong."
    //find the total sell money

    //print the total sell money
    
    //year-month-day.txt open this file

    FILE *file;
    char fileName[20];
    sprintf(fileName, "TextFiles/%s-%s-%s.txt", year, month, day);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("No orders have been made on this date or date is wrong.\n");
        return;
    }

    char line[100];
    int totalSellMoney = 0;
    
    //parse the lines and
    //find the total sell money

     while (fgets(line, sizeof(line), file)) 
    {
        sscanf(line, "%d-%d/%d/%d_%d-%[^-]-%[^TL]TL-%[^-]-%[^-]-%[^-]-%d/%d/%d_%d:%d-%d/%d/%d_%d:%d-%[^-]", 
        &OrderNumber, &Year, &Month, &Day, &CustomerID, FoodName, Price, PrepTime, UserName, State, 
        &AcceptYear, &AcceptMonth, &AcceptDay, &AcceptHour, &AcceptMinute, 
        &ReadyYear, &ReadyMonth, &ReadyDay, &ReadyHour, &ReadyMinute, CooksID);

        if (strcmp(State, "SIP") == 0) \
        {
            totalSellMoney += atoi(Price);
        }
    }

    printf("The sell money is %d TL.\n", totalSellMoney);

    fclose(file);



}

void MonthlySellMoney()
{
    char year[5];
    char month[3];

    printf("Enter the year: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the year again
    int validYear = 0;
    while (!validYear) {
        scanf("%s", year);
        validYear = ScanfOnlyNumeric(year) && atoi(year) > 0;
        if (!validYear) {
            printf("Non-numeric characters are not allowed. Please enter the year again.\n");
        }
    }

    printf("Enter the month: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the month again
    int validMonth = 0;
    while (!validMonth) {
        scanf("%s", month);
        validMonth = ScanfOnlyNumeric(month) && atoi(month) > 0 && atoi(month) < 13;
        if (!validMonth) {
            printf("Non-numeric characters are not allowed. Please enter the month again.\n");
        }
    }

    //year-month-day.txt open this file
    //day start from 1 and end at 31

    int totalSellMoney = 0;
    int YearInt = atoi(year);
    int MonthInt = atoi(month);

    for (int i = 1; i < 32; i++)
    {
        
        FILE *file;
        char fileName[20];
        sprintf(fileName, "TextFiles/%d-%d-%d.txt", YearInt, MonthInt, i);
        file = fopen(fileName, "r");
        
        char line[100];
        while (fgets(line, sizeof(line), file))
        {
            int OrderNumber;
            int Year;
            int Month;
            int Day;
            int CustomerID;
            char FoodName[50];
            char Price[50];
            char PrepTime[50];
            char UserName[50];
            char State[50];
            int AcceptYear;
            int AcceptMonth;
            int AcceptDay;
            int AcceptHour;
            int AcceptMinute;
            int ReadyYear;
            int ReadyMonth;
            int ReadyDay;
            int ReadyHour;
            int ReadyMinute;
            char CooksID[4];

            sscanf(line, "%d-%d/%d/%d_%d-%[^-]-%[^TL]TL-%[^-]-%[^-]-%[^-]-%d/%d/%d_%d:%d-%d/%d/%d_%d:%d-%[^-]", 
            &OrderNumber, &Year, &Month, &Day, &CustomerID, FoodName, Price, PrepTime, UserName, State, 
            &AcceptYear, &AcceptMonth, &AcceptDay, &AcceptHour, &AcceptMinute, 
            &ReadyYear, &ReadyMonth, &ReadyDay, &ReadyHour, &ReadyMinute, CooksID);
            if (strcmp(State, "SIP") == 0)
            {
                totalSellMoney += atoi(Price);
            }
        }
        fclose(file);
    }
    printf("The total sell money on %s-%s is %d TL.\n", year, month, totalSellMoney);

}

void DatesBetweenGetTheSellMoney()
{
    char year[5];
    char month[3];
    char day[3];
    char year1[5];
    char month1[3];
    char day1[3];

    printf("Enter the year: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the year again
    int validYear = 0;
    while (!validYear) {
        scanf("%s", year);
        validYear = ScanfOnlyNumeric(year) && atoi(year) > 0;
        if (!validYear) {
            printf("Non-numeric characters are not allowed. Please enter the year again.\n");
        }
    }

    printf("Enter the month: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the month again
    int validMonth = 0;
    while (!validMonth) {
        scanf("%s", month);
        validMonth = ScanfOnlyNumeric(month) && atoi(month) > 0 && atoi(month) < 13;
        if (!validMonth) {
            printf("Non-numeric characters are not allowed. Please enter the month again.\n");
        }
    }

    printf("Enter the day: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the day again
    int validDay = 0;
    while (!validDay) {
        scanf("%s", day);
        validDay = ScanfOnlyNumeric(day) && atoi(day) > 0 && atoi(day) < 32;
        if (!validDay) {
            printf("Non-numeric characters are not allowed. Please enter the day again.\n");
        }
    }

    printf("Enter the year1: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the year1 again
    int validYear1 = 0;
    while (!validYear1) {
        scanf("%s", year1);
        validYear1 = ScanfOnlyNumeric(year1) && atoi(year1) > 0;
        if (!validYear1) {
            printf("Non-numeric characters are not allowed. Please enter the year1 again.\n");
        }
    
    }

    printf("Enter the month1: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the month1 again
    int validMonth1 = 0;
    while (!validMonth1) {
        scanf("%s", month1);
        validMonth1 = ScanfOnlyNumeric(month1) && atoi(month1) > 0 && atoi(month1) < 13;
        if (!validMonth1) {
            printf("Non-numeric characters are not allowed. Please enter the month1 again.\n");
        }
    
    }

    printf("Enter the day1: ");
    //can only enter numbers cant be negative
    //if the user enters a non-numeric character ask for the day1 again
    int validDay1 = 0;
    while (!validDay1) {
        scanf("%s", day1);
        validDay1 = ScanfOnlyNumeric(day1) && atoi(day1) > 0 && atoi(day1) < 32;
        if (!validDay1) {
            printf("Non-numeric characters are not allowed. Please enter the day1 again.\n");
        }
    }

    //if month1 < month or year1 < year or day1 < day print "Invalid date range"

    if (atoi(year1) < atoi(year) || (atoi(year1) == atoi(year) && atoi(month1) < atoi(month)) || (atoi(year1) == atoi(year) && atoi(month1) == atoi(month) && atoi(day1) < atoi(day)))
    {
        printf("Invalid date range\n");
        return;
    }

    int totalSellMoney = 0;

    int YearInt = atoi(year);
    int MonthInt = atoi(month);
    int DayInt = atoi(day);

    int YearInt1 = atoi(year1);
    int MonthInt1 = atoi(month1);
    int DayInt1 = atoi(day1);

    //from the start of the YearInt-MonthInt-DayInt.txt to the end of the YearInt1-MonthInt1-DayInt1.txt
    //find the total sell money
    //while incrementing the day if day is bigger than 31 increment the month and set the day to 1
    //if month is bigger than 12 increment the year and set the month to 1

    for (int i = YearInt; i <= YearInt1; i++)
    {
        for (int j = MonthInt; j <= 12; j++)
        {
            for (int k = DayInt; k <= 31; k++)
            {
                FILE *file;
                char fileName[20];
                sprintf(fileName, "TextFiles/%d-%d-%d.txt", i, j, k);
                file = fopen(fileName, "r");
                if (file == NULL)
                {
                    continue;
                }
                char line[100];
                while (fgets(line, sizeof(line), file))
                {
                    int OrderNumber;
                    int Year;
                    int Month;
                    int Day;
                    int CustomerID;
                    char FoodName[50];
                    char Price[50];
                    char PrepTime[50];
                    char UserName[50];
                    char State[50];
                    int AcceptYear;
                    int AcceptMonth;
                    int AcceptDay;
                    int AcceptHour;
                    int AcceptMinute;
                    int ReadyYear;
                    int ReadyMonth;
                    int ReadyDay;
                    int ReadyHour;
                    int ReadyMinute;
                    char CooksID[4];

                    sscanf(line, "%d-%d/%d/%d_%d-%[^-]-%[^TL]TL-%[^-]-%[^-]-%[^-]-%d/%d/%d_%d:%d-%d/%d/%d_%d:%d-%[^-]", 
                    &OrderNumber, &Year, &Month, &Day, &CustomerID, FoodName, Price, PrepTime, UserName, State, 
                    &AcceptYear, &AcceptMonth, &AcceptDay, &AcceptHour, &AcceptMinute, 
                    &ReadyYear, &ReadyMonth, &ReadyDay, &ReadyHour, &ReadyMinute, CooksID);
                    if (strcmp(State, "SIP") == 0)
                    {
                        totalSellMoney += atoi(Price);
                    }
                }
                fclose(file);
            }
            DayInt = 1;
        }
        MonthInt = 1;
    }

    printf("The total sell money between  %d TL.\n", totalSellMoney);



}
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
    //check in the Line if there is a "Wait" word
    //if there is a "Wait" word return 1
    //if there is not a "Wait" word return 0

    char line[100];
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == LineNumber) {
            if (strstr(line, "Wait") != NULL) {
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    return 0;

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
    int x;
    int Year;
    int Month;
    int Day;
    int CustomerID;
    char FoodName [30];
    char FoodPrice[10];
    int PreparationTime;
    char CustomerName[30];
    char State[10];

    int CurrentYear;
    int CurrentMonth;
    int CurrentDay;
    int CurrentHour;
    int CurrentMinute;

    int ReadyYear;
    int ReadyMonth;
    int ReadyDay;
    int ReadyHour;
    int ReadyMinute;

    // 1-2024/5/25_4-Fish Burger -25 TL-20 -mustafa-Wait
    // 2-2024/5/25_4-Veggie Burger -17 TL-13 -mustafa-Wait
    // 3-2024/5/25_4-Onion Rings -12 TL-7 -mustafa-Wait
    // 4-2024/5/25_4-French Fries -10 TL-5 -mustafa-Wait
    // 5-2024/5/25_4-Veggie Burger -17 TL-13 -mustafa-Wait

    //Parse the line into different fields
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == orderNumber) {
            if (sscanf(line, "%d-%d/%d/%d_%d-%[^-] -%[^TL] TL-%d -%[^-] -%s", &x, &Year, &Month, &Day, &CustomerID, FoodName, FoodPrice, &PreparationTime, CustomerName, State) == 10) {
                break;
            }
        }
    }
    fclose(file);


    //change the state to RED

    FILE *file2;
    file2 = fopen("TextFiles/OrderListTemp.txt", "w");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }
    FILE *file3;
    file3 = fopen("TextFiles/OrderList.txt", "r");
    if(file3 == NULL) {
        printf("Error: File not found\n");
    }
    int count2 = 0;
    while (fgets(line, sizeof(line), file3)) {
        count2++;
        if (count2 == orderNumber) {
            fprintf(file2, "%d-%d/%d/%d_%d-%s -%s TL-%d -%s -RED\n", x, Year, Month, Day, CustomerID, FoodName, FoodPrice, PreparationTime, CustomerName);
        } else {
            fprintf(file2, "%s", line);
        }
    }

    fclose(file2);
    fclose(file3);
    remove("TextFiles/OrderList.txt");
    rename("TextFiles/OrderListTemp.txt", "TextFiles/OrderList.txt");
    printf("The order has been declined.\n");
   
}

void AproveTheOrder(int orderNumber)
{
    //then change the state to SIP
    
    int x;
    int Year;
    int Month;
    int Day;
    int CustomerID;
    char FoodName [30];
    char FoodPrice[10];
    int PreparationTime;
    char CustomerName[30];
    char State[10];

    int CurrentYear;
    int CurrentMonth;
    int CurrentDay;
    int CurrentHour;
    int CurrentMinute;

    int ReadyYear;
    int ReadyMonth;
    int ReadyDay;
    int ReadyHour;
    int ReadyMinute;

    // 1-2024/5/25_4-Fish Burger -25 TL-20 -mustafa-Wait
    // 2-2024/5/25_4-Veggie Burger -17 TL-13 -mustafa-Wait
    // 3-2024/5/25_4-Onion Rings -12 TL-7 -mustafa-Wait
    // 4-2024/5/25_4-French Fries -10 TL-5 -mustafa-Wait
    // 5-2024/5/25_4-Veggie Burger -17 TL-13 -mustafa-Wait

    //Parse the line into different fields
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == orderNumber) {
            if (sscanf(line, "%d-%d/%d/%d_%d-%[^-] -%[^TL] TL-%d -%[^-] -%s", &x, &Year, &Month, &Day, &CustomerID, FoodName, FoodPrice, &PreparationTime, CustomerName, State) == 10) {
                break;
            }
        }
    }
    fclose(file);

    //get the current date and time windows.h :]

    SYSTEMTIME t;
    GetLocalTime(&t);
    CurrentYear = t.wYear;
    CurrentMonth = t.wMonth;
    CurrentDay = t.wDay;
    CurrentHour = t.wHour;
    CurrentMinute = t.wMinute;

    //calculate the ready time
    //if the current minute + the preparation time is greater than 60
    //add 1 to the hour and subtract 60 from the minute
    //if the current hour + the hour is greater than 24
    //add 1 to the day and subtract 24 from the hour
    //if the current day + the day is greater than 30
    //add 1 to the month and subtract 30 from the day
    //if the current month + the month is greater than 12
    //add 1 to the year and subtract 12 from the month

    ReadyYear = CurrentYear;
    ReadyMonth = CurrentMonth;
    ReadyDay = CurrentDay;
    ReadyHour = CurrentHour;
    ReadyMinute = CurrentMinute + PreparationTime;

    if (ReadyMinute >= 60) {
        ReadyHour++;
        ReadyMinute -= 60;
    }
    if (ReadyHour >= 24) {
        ReadyDay++;
        ReadyHour -= 24;
    }
    if (ReadyDay >= 30) {
        ReadyMonth++;
        ReadyDay -= 30;
    }
    if (ReadyMonth >= 12) {
        ReadyYear++;
        ReadyMonth -= 12;
    }

    //check the Available Cooks
    //if the cooks Year month day .... is smaller than the Ready Time cook is available
    //if the cooks Year month day .... is greater than the Ready Time cook is not available
    //if there is no available cook return 0
    
    //loop through the cooks
    int CookID;
    int CookYear;
    int CookMonth;
    int CookDay;
    int CookHour;
    int CookMinute;

    FILE *file2;
    file2 = fopen("Cooks.dat", "rb");
    if (file2 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    Cook cook;
    int available = 0;
    while (fread(&cook, sizeof(Cook), 1, file2))
    {
        CookID = atoi(cook.ID);
        CookYear = atoi(cook.Year);
        CookMonth = atoi(cook.Month);
        CookDay = atoi(cook.Day);
        CookHour = atoi(cook.Hour);
        CookMinute = atoi(cook.Minute);
        if (CookYear < ReadyYear) {
            available = 1;
            break;
        } else if (CookYear == ReadyYear) {
            if (CookMonth < ReadyMonth) {
                available = 1;
                break;
            } else if (CookMonth == ReadyMonth) {
                if (CookDay < ReadyDay) {
                    available = 1;
                    break;
                } else if (CookDay == ReadyDay) {
                    if (CookHour < ReadyHour) {
                        available = 1;
                        break;
                    } else if (CookHour == ReadyHour) {
                        if (CookMinute < ReadyMinute) {
                            available = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    fclose(file2);

    if (available == 0) {
        printf("There is no available cook. The order can not be approved.\n");
        return;
    }
    //change the Cooks Year month day .... to the Ready Time

    FILE *file5;
    file5 = fopen("Cooks.dat", "rb");
    if (file5 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    FILE *file6;
    file6 = fopen("CooksTemp.dat", "wb");
    if (file6 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    Cook cook2;
    while (fread(&cook2, sizeof(Cook), 1, file5))
    {
        if (CookID == atoi(cook2.ID)) {
            sprintf(cook2.Year, "%d", ReadyYear);
            sprintf(cook2.Month, "%d", ReadyMonth);
            sprintf(cook2.Day, "%d", ReadyDay);
            sprintf(cook2.Hour, "%d", ReadyHour);
            sprintf(cook2.Minute, "%d", ReadyMinute+1);
        }
        fwrite(&cook2, sizeof(Cook), 1, file6);
    }
    fclose(file5);
    fclose(file6);
    remove("Cooks.dat");
    rename("CooksTemp.dat", "Cooks.dat");



    
    //if there is an available cook
    // 1-2024/5/25_4-Fish Burger -25 TL-20 -mustafa-SIP-CurreYear/CurrentMonth/CurrentDay_CurrentHour:CurrentMinute-ReadyYear/ReadyMonth/ReadyDay_ReadyHour:ReadyMinute -CookIDA

    //change the state to SIP

    FILE *file3;
    file3 = fopen("TextFiles/OrderList.txt", "r");
    if(file3 == NULL) {
        printf("Error: File not found\n");
    }
    FILE *file4;
    file4 = fopen("TextFiles/OrderListTemp.txt", "w");
    if(file4 == NULL) {
        printf("Error: File not found\n");
    }

    count = 0;
    while (fgets(line, sizeof(line), file3)) {
        count++;
        if (count == orderNumber) {
            fprintf(file4, "%d-%d/%d/%d_%d-%s-%sTL-%d-%s-SIP-%d/%d/%d_%d:%d-%d/%d/%d_%d:%d -%d\n", 
            x, Year, Month, Day, CustomerID, FoodName, FoodPrice, PreparationTime, CustomerName, 
            CurrentYear, CurrentMonth, CurrentDay, CurrentHour, CurrentMinute,
            ReadyYear, ReadyMonth, ReadyDay, ReadyHour, ReadyMinute, CookID);
        } else {
            fprintf(file4, "%s", line);
        }
    }
   
    fclose(file3);
    fclose(file4);
    remove("TextFiles/OrderList.txt");
    rename("TextFiles/OrderListTemp.txt", "TextFiles/OrderList.txt");

    printf("The order has been approved.\n");


    //open all time food txt
    //FoodName-FoodPrice-Quantity
    //if the food is in the txt increase the quantity
    //if the food is not in the txt add the food to the txt
    
    int FoodListQuantity;
    int FoodListFoodPrice;
    char FoodListFoodName[30];

    FILE *file7;
    file7 = fopen("TextFiles/AllTimeFood.txt", "r");
    if(file7 == NULL) {
        printf("Error: File not found\n");
    }
    FILE *file8;
    file8 = fopen("TextFiles/AllTimeFoodTemp.txt", "w");
    if(file8 == NULL) {
        printf("Error: File not found\n");
    }

    int found = 0;
    while (fscanf(file7, "%[^-]-%d TL-%d\n", FoodListFoodName, &FoodListFoodPrice, &FoodListQuantity) == 3) {
        if (strcmp(FoodListFoodName, FoodName) == 0) {
            found = 1;
            fprintf(file8, "%s-%d TL-%d\n", FoodListFoodName, FoodListFoodPrice, FoodListQuantity+1);
        } else {
            fprintf(file8, "%s-%d TL-%d\n", FoodListFoodName, FoodListFoodPrice, FoodListQuantity);
        }
    }
    if (found == 0) {
        fprintf(file8, "%s-%d TL-%d\n", FoodName, atoi(FoodPrice), 1);
    }
    fclose(file7);
    fclose(file8);
    remove("TextFiles/AllTimeFood.txt");
    rename("TextFiles/AllTimeFoodTemp.txt", "TextFiles/AllTimeFood.txt");


    //do the same for the AllTimeFood.dat from the FoodList struct

    FILE *file9;
    file9 = fopen("AllTimeFood.dat", "rb");
    if (file9 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    FILE *file10;
    file10 = fopen("AllTimeFoodTemp.dat", "wb");
    if (file10 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    FoodList foodList;
    found = 0;
    while (fread(&foodList, sizeof(FoodList), 1, file9))
    {
        if (strcmp(foodList.FoodName, FoodName) == 0) {
            found = 1;
            foodList.FoodQuantity++;
        }
        fwrite(&foodList, sizeof(FoodList), 1, file10);
    }
    if (found == 0) {
        strcpy(foodList.FoodName, FoodName);
        foodList.FoodPrice = atoi(FoodPrice);
        foodList.FoodQuantity = 1;
        fwrite(&foodList, sizeof(FoodList), 1, file10);
    }
    fclose(file9);
    fclose(file10);
    remove("AllTimeFood.dat");
    rename("AllTimeFoodTemp.dat", "AllTimeFood.dat");

}

void Cooks()
{
    FILE *file;
    file = fopen("Cooks.dat", "rb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    Cook cook;
    while (fread(&cook, sizeof(Cook), 1, file))
    {
        printf("ID: %s\n", cook.ID);
        printf("Year: %s\n", cook.Year);
        printf("Month: %s\n", cook.Month);
        printf("Day: %s\n", cook.Day);
        printf("Hour: %s\n", cook.Hour);
        printf("Minute: %s\n", cook.Minute);
        printf("Second: %s\n", cook.Second);
    }
    fclose(file);










}

void CreateAllTimeFoodTxt()
{
   
    FILE *file2;
    file2 = fopen("TextFiles/AllTimeFood.txt", "w");
    if(file2 == NULL) {
        printf("Error: File not found\n");
    }

    fclose(file2);   

}

void DailyCreationOfTxt()
{   

    //in this function we will compare int Year int Month int Day with the current date
    //if the current date is Bigger than the int Year int Month int Day we will create a new txt file
    //and print inside the txt file these lines

    int OrderNumber;
    int Year;
    int Month;
    int Day;
    int CustomerID;

    char FoodName[50];
    char Price[50];
    char PrepTime[50];
    char UserName[50];
    char State[50];

    int AcceptYear;
    int AcceptMonth;
    int AcceptDay;
    int AcceptHour;
    int AcceptMinute;

    int ReadyYear;
    int ReadyMonth;
    int ReadyDay;
    int ReadyHour;
    int ReadyMinute;

    char CooksID[4];
    
    //by windows.h get the current date and time
    int CurrentYear;
    int CurrentMonth;
    int CurrentDay;
    int CurrentHour;
    int CurrentMinute;

    SYSTEMTIME t;
    GetLocalTime(&t);
    CurrentYear = t.wYear;
    CurrentMonth = t.wMonth;
    CurrentDay = t.wDay;
    CurrentHour = t.wHour;
    CurrentMinute = t.wMinute;

    char NewFileName[50];

    //parse the line and check if the ID is the same as the customer's ID
    //if it is then in line check if State is SIP
    
    FILE *file;
    file = fopen("TextFiles/OrderList.txt", "r");
    if(file == NULL) 
    {
        printf("Error: File not found\n");
    }

    char line[100];
  
    while (fgets(line, sizeof(line), file)) 
    {
        //here what happens will be happened

        sscanf(line, "%d-%d/%d/%d_%d-%[^-]-%[^TL]TL-%[^-]-%[^-]-%[^-]-%d/%d/%d_%d:%d-%d/%d/%d_%d:%d-%[^\n]", 
        &OrderNumber, &Year, &Month, &Day, &CustomerID, FoodName, Price, PrepTime, UserName, State, 
        &AcceptYear, &AcceptMonth, &AcceptDay, &AcceptHour, &AcceptMinute, 
        &ReadyYear, &ReadyMonth, &ReadyDay, &ReadyHour, &ReadyMinute, CooksID);

        // Check if the current date is greater than the date in the file
        if (CurrentYear > Year || 
            (CurrentYear == Year && CurrentMonth > Month) || 
            (CurrentYear == Year && CurrentMonth == Month && CurrentDay > Day)) 
        {
          
        //if the current date is bigger than the date in the line
        //then we will create a new txt file by tne name of the current date like 2024/5/25.txt
        //and we will print the lines that only contain SIP inside the txt file

        //if it does not exist create a new file
        //if it exists open the file and write inside the file
        //check if the txt exists
        //if it does not exist create a new file
        //if it exists open the file and write inside the file

        sprintf(NewFileName, "TextFiles/%d-%d-%d.txt", Year, Month, Day);
        FILE *file2;
        file2 = fopen(NewFileName, "a");
        if(file2 == NULL) {
            printf("Error: File not found\n");
        }

        //if the there is a SIP in the line print the line inside the txt file
        if (strcmp(State, "SIP") == 0) {
            fprintf(file2, "%d-%d/%d/%d_%d-%s-%sTL-%s-%s-%s-%d/%d/%d_%d:%d-%d/%d/%d_%d:%d-%s\n", 
            OrderNumber, Year, Month, Day, CustomerID, FoodName, Price, PrepTime, UserName, State, 
            AcceptYear, AcceptMonth, AcceptDay, AcceptHour, AcceptMinute, 
            ReadyYear, ReadyMonth, ReadyDay, ReadyHour, ReadyMinute, CooksID);
        }
        fclose(file2);
        }    
    }
    fclose(file);


    //Remove the OrderList.txt
    //Create a new OrderList.txt

    remove("TextFiles/OrderList.txt");
    FILE *file3;
    file3 = fopen("TextFiles/OrderList.txt", "w");
    if(file3 == NULL) {
        printf("Error: File not found\n");
    }
    fclose(file3);


}

void BringTheAllTimeFoodTxt()
{
    FILE *file;
    file = fopen("TextFiles/AllTimeFood.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void CreateTheAllTimeFoodData()
{

    //create  AllTimeFood.dat

    FILE *file;
    file = fopen("AllTimeFood.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(file);

}

void BringTheAllTimeFoodData()
{
    FILE *file;
    file = fopen("AllTimeFood.dat", "rb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    FoodList foodList;
    while (fread(&foodList, sizeof(FoodList), 1, file))
    {
        printf("Food Name: %s\n", foodList.FoodName);
        printf("Food Price: %d\n", foodList.FoodPrice);
        printf("Food Quantity: %d\n", foodList.FoodQuantity);
    }
    fclose(file);
}

void BringTheMostProfitFood()
{
    //open the AllTimeFood.dat
    //read the file
    //find the most profit food
    //print the most profit food
    //print the profit and the quantity

    FILE *file;
    file = fopen("AllTimeFood.dat", "rb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    FoodList foodList;
    int maxProfit = 0;
    char mostProfitFood[30];
    int mostProfitQuantity = 0;
    while (fread(&foodList, sizeof(FoodList), 1, file))
    {
        if (foodList.FoodPrice * foodList.FoodQuantity > maxProfit) {
            maxProfit = foodList.FoodPrice * foodList.FoodQuantity;
            strcpy(mostProfitFood, foodList.FoodName);
            mostProfitQuantity = foodList.FoodQuantity;
        }
    }
    fclose(file);
    printf("The most profit food is %s with a profit of %d TL and a quantity of %d\n", mostProfitFood, maxProfit, mostProfitQuantity);

}

void BringTheLeastProfitFood()
{
    //open the AllTimeFood.dat
    //read the file
    //find the least profit food
    //print the least profit food
    //print the profit and the quantity

    FILE *file;
    file = fopen("AllTimeFood.dat", "rb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    FoodList foodList;
    int minProfit = 1000000;
    char leastProfitFood[30];
    int leastProfitQuantity = 0;
    while (fread(&foodList, sizeof(FoodList), 1, file))
    {
        if (foodList.FoodPrice * foodList.FoodQuantity < minProfit) {
            minProfit = foodList.FoodPrice * foodList.FoodQuantity;
            strcpy(leastProfitFood, foodList.FoodName);
            leastProfitQuantity = foodList.FoodQuantity;
        }
    }
    fclose(file);
    printf("The least profit food is %s with a profit of %d TL and a quantity of %d\n", leastProfitFood, minProfit, leastProfitQuantity);
}


#endif // RESTAURANT_H