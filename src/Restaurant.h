#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h> // Include the standard C library

//add function declarations here
void createFoodListFile();
void createOrdersFile();

void OpenFoodListFile();
void OpenOrdersFile();

void CreateASampleFoodList();


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


void OpenFoodListFile() {
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

/*
    Yemek Adı Yemek Fiyatı Hazırlanma Süresi (dk) Durum
    Lahmacun 75 TL 20 Mevcut
    Hamburger 250 TL 30 Mevcut
    Mantı 170 TL 45 Mevcut Değil
    Tost 60 TL 10 Mevcut
    Tavuk Dürüm 80 TL 15 Mevcut
    Et Dürüm 160 TL 15 Mevcut Değil
*/
void CreateASampleFoodList()
{
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "w");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    fprintf(file, "Yemek Adı Yemek Fiyatı Hazırlanma Süresi (dk) Durum\n");
    fprintf(file, "Lahmacun -- 75 TL -- 20 -- Mevcut\n");
    fprintf(file, "Hamburger -- 250 TL -- 30 -- Mevcut\n");
    fprintf(file, "Mantı -- 170 TL -- 45 -- Mevcut Değil\n");
    fprintf(file, "Tost -- 60 TL -- 10 -- Mevcut\n");
    fprintf(file, "Tavuk Dürüm -- 80 TL -- 15 -- Mevcut\n");
    fprintf(file, "Et Dürüm -- 160 TL -- 15 -- Mevcut Değil\n");
    fclose(file);
}

#endif // RESTAURANT_H