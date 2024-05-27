#include "Kitchen.h"
// Elif yaren Şakar 434335
// Rümeysa Yurdakul 425487
// Orhun Begen 402520

int menu();

int main()
{
    int rum = menu();

    if(rum == 1)
    {
        PrintTheCooks();
    }
    else if(rum == 2)
    {
        CleanEverythingInsideCooksDatFile();
        AdjustTheCooksNumero();
    }
    else if(rum == 0)
    {
        return 0;
    }
    else
    {
        printf("Hatali secim yaptiniz.");
    }
    return 0;
}

int menu()
{
    int secim;
    printf("\t1-Yazdir Asciler\n");
    printf("\t2-Asci sayisini duzenle\n");
    printf("\t0-PROGRAMI KAPAT \n");
    printf("\tSECIMINIZ : ") ; 
    scanf("%d", &secim);
    system("cls");
    return secim;
}