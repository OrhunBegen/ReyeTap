#include "Customer.h"


int menu()
{
    int secim;
    printf("\n\t SIPARIS UYGULAMASI \n\n");
    printf("\t1-MUSTERI ISLEMLERI \n");
    printf("\t2-RESTORAN ISLEMLERI \n");
    printf("\t0-PROGRAMI KAPAT \n");
    printf("\tSECIMINIZ : ") ; 
    scanf("%d", &secim);
    system("cls");
    return secim;

}

int main(int argc, char *argv[])
{
    int secim;

    baslangic:


    secim  = CustomerMenu();

    if(secim == -1)
    {
        printf("Hatali secim yaptiniz.");
        goto  baslangic;   

    }   
    if(secim == -2)
    {
        printf("hesap oluturuldu\n");
        goto baslangic;

    }
    if(secim == -3)
    {
        printf("login basarisiz");
        goto baslangic;
    }
    else
    {
        MusteriGirisYaptiMenu(secim);
    }
    
    

    


    return 0;

}
    

