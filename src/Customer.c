#include "Customer.h"
#include "Restaurant.h"

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
    int secim=menu();

    while(secim != 0)
    {
        switch(secim)
        {
            case 1: CustomerMenu(); break;
                
        //case 2: MenuForRestaurant(); break;
            case 0: break;
            default : printf("hatali secim yaptiniz \n"); break;
        }
        secim=menu();
    }
    return 0;
}

