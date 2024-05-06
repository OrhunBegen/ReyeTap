#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

int menu()
{
    int secim;
    printf("\n\t SIPARIS UYGULAMASI \n\n");
    printf("\t1-MUSTERI ISLEMLERI \n");
    printf("\t2-RESTORAN ISLEMLERI \n");
    printf("\t0-PROGRAMI KAPAT \n");
    printf("\tSECIMINIZ : ") ; scanf("%d", &secim);
    system("cls");
    return secim;

}

int main(int argc, char *argv[]){

    int secim=menu();
    while(secim != 0)
    {
        switch(secim)
        {
            case 1: MenuForCustomer(); break;
            case 2: MenuForRestaurant(); break;
            case 0: break;
            default : printf("hatali secim yaptiniz \n"); break;
        }
        secim=menu();
    }
    return 0;
}
void MenuForCustomer();
    void CustomerMenu(){
        int secim;
        printf("\n\t MUSTERI ISLEMLERI \n\n");
        printf("\t1-MUSTERI EKLE \n");
        printf("\t2-MUSTERI LISTELE \n");
        printf("\t3-MUSTERI GUNCELLE \n");
        printf("\t4-MUSTERI SIL \n");
        printf("\t0-ANA MENU \n");
        printf("\tSECIMINIZ : ");
        scanf("%d", &secim);
        system("cls");
        while (secim != 0) {
            switch (secim) {
                case 1:
                    addCustomer();
                    break;
                case 2:
                    CustomerList();
                    break;
                case 3:
                    updateCustomer();
                    break;
                case 4:
                    deleteCustomer();
                    break;
                case 0:
                    break;
                default:
                    printf("hatali secim yaptiniz \n");
                    break;
            }
            secim=CustomerMenu();
        }
    }
