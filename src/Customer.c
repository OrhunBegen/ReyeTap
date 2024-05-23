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

    

    int a =LoginCustomerReturnID();

    MakeAOrderByID(a);


    return 0;

}
    

