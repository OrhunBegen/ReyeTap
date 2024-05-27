#include "Customer.h"
// Elif yaren Şakar 434335
// Rümeysa Yurdakul 425487
// Orhun Begen 402520

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

int menu2(int argc, char *argv[])
{   
    int secim= menu(); 
	while( secim != 0)
	{
		switch(secim )
		{
			case 1: CustomerMenu() ;      
			//case 2: urunIslemleri(); break;  
			case 0: break; 
			default: printf("hatali islem ! \n") ; break; 
		}
		secim= menu(); 
	}
    // int a =LoginCustomerReturnID();

    // MakeAOrderByID(a);
     return 0;

}
    

int main(int argc, char *argv[])
{
    int secim;

    baslangic:
    secim  = CustomerMenu();
{   

    if(secim == -1)
    {
        printf("Hatali secim yaptiniz.");
        goto  baslangic;   

    }   
    if(secim == -2)
    {
        printf("hesap olusturuldu\n");
        goto baslangic;
    

    }
    if(secim == 0)
    {
        
        goto baslangic;
    }
    else
    {
        MusteriGirisYaptiMenu(secim);
    }
    return 0;
}
}
