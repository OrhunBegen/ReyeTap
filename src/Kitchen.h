#ifndef KITCHEN_H
#define KITCHEN_H

//this is a c library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

//struct for the cooks
typedef struct Cook {
    char ID[5];
    char Year[5];
    char Month[3];
    char Day[3];
    char Hour[3];
    char Minute[3];
    char Second[3];

} Cook;

void CreateCooksDatFile()
{   
    FILE *file;
    file = fopen("Cooks.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(file);

}

void CreateSampleCooks()
{
    FILE *file;
    file = fopen("Cooks.dat", "ab");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    Cook cook;
    int i;
    for (i = 0; i < 10; i++)
    {
        sprintf(cook.ID, "%d", i);
        strcpy(cook.Year, "1970");
        strcpy(cook.Month, "01");
        strcpy(cook.Day, "01");
        strcpy(cook.Hour, "00");
        strcpy(cook.Minute, "00");
        strcpy(cook.Second, "00");
        fwrite(&cook, sizeof(Cook), 1, file);
    }
    fclose(file);







}

void AdjustTheCook(int s)
{
    FILE *file;
    file = fopen("Cooks.dat", "ab");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    Cook cook;

    



    






}


void PrintTheCooks()
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


void AdjustTheCooksNumero()
{

    int Numero;

    printf("Enter the number of cooks: ");
    scanf("%d", &Numero);
    


    //this function will adjust the number of cooks in the cooks.dat file
    FILE *file;
    file = fopen("Cooks.dat", "ab");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    Cook cook;

    int i;

    for (i = 0; i < Numero; i++)
    {
        sprintf(cook.ID, "%d", i);
        strcpy(cook.Year, "1970");
        strcpy(cook.Month, "01");
        strcpy(cook.Day, "01");
        strcpy(cook.Hour, "00");
        strcpy(cook.Minute, "00");
        strcpy(cook.Second, "00");
        fwrite(&cook, sizeof(Cook), 1, file);
    }

    fclose(file);

    printf("The number of cooks has been adjusted to %d\n", Numero);


} 

void ChangeTheCooksYearTo2025(int ID)
{
  
    FILE *file;
    file = fopen("Cooks.dat", "rb+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    Cook cook;
    while (fread(&cook, sizeof(Cook), 1, file))
    {
        if (atoi(cook.ID) == ID)
        {
            strcpy(cook.Year, "2025");
            fseek(file, -sizeof(Cook), SEEK_CUR);
            fwrite(&cook, sizeof(Cook), 1, file);
            break;
        }
    }
    fclose(file);

  

}

void CleanEverythingInsideCooksDatFile()
{
    remove("Cooks.dat");
    FILE *file;
    file = fopen("Cooks.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fclose(file);
    

}


#endif // KITCHEN_H