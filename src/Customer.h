#ifndef CUSTOMER_H
#define CUSTOMER_H



typedef struct Customer
{
    int id;
    char name[50];
    char surname[50];
    char address[100];
    char phone[15];
    char email[50];
} Customer;
#include <stdlib.h>
#include <stdio.h>

void addCustomer();
void CustomerList();
void updateCustomer();
void deleteCustomer();
void CustomerMenu();
void MenuForCustomer();




Customer c1,c2;


void addCustomer()
{
    system("cls");
    printf("\n\t MUSTERI EKLEME \n\n");

    int numara=0;
    FILE *numPtr = fopen("musteriNumarasi.dat","a+b");
    while( fread(&numara, sizeof(int), 1, numPtr) == 1)
    {
        
    }
    numara++;
    fwrite(&numara, sizeof(int), 1, numPtr);
    fclose(numPtr);

    c1.id = numara;

    printf("Musteri adi giriniz : "); scanf("%[^\n]s", c1.name);
    printf("Musteri soyadi giriniz : "); scanf("%[^\n]s", c1.surname);
    printf("Musteri adresi giriniz : "); scanf("%[^\n]s", c1.address);
    printf("Musteri telefonu giriniz : "); scanf("%[^\n]s", c1.phone);
    printf("Musteri email giriniz : "); scanf("%[^\n]s", c1.email);
    printf("Musteri adi : %s \n", c1.name);
    printf("Musteri soyadi : %s \n", c1.surname);
    printf("Musteri adresi : %s \n", c1.address);
    printf("Musteri telefonu : %s \n", c1.phone);
    printf("Musteri email : %s \n", c1.email);
    FILE *file = fopen("musteri.dat","a+b");
    fwrite(&c1, sizeof(Customer), 1, file);
    fclose(file);
    printf("\n\n%d numarali musteri eklendi \n", numara);

}
void CustomerList()
{
    Customer c1;
    system("cls");
    printf("\n\t MUSTERI LISTELE \n\n");

    int sayac=0;
    printf("%-10d %-20s %-20s %-20s %-15d %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");
    FILE *ptr= fopen("musteri.dat","r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        printf("%-10d %-20s %-20s %-20s %-15d %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
        sayac++;
    }
    fclose(ptr);

    if(sayac == 0)
    {
        printf("Listelenecek musteri bulunamadi \n");
    }
    else
    {
        printf("\n\nToplam %d musteri bulunmaktadir \n", sayac);
    }
}
void updateCustomer()
{
    system("cls");
    printf("\n\t MUSTERI LISTESI \n\n");
    int sayac=0,numara,durum=0;
    printf("%-10d %-20s %-20s %-20s %-15d %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");
    
    FILE *ptr= fopen("musteri.dat","r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) ==1)
    {
        printf("%-10d %-20s %-20s %-20s %-15d %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
        sayac++;
    }
    if(sayac==0)
    {
        system("cls");
        printf("\n Listelenecek musteri bulunamadi \n");
    }
    else
    {
        sayac=0;
        rewind(ptr);

        printf("\n\nGuncellenecek musteri numarasini giriniz : "); scanf("%d", &numara);

        while(fread(&c1, sizeof(Customer), 1, ptr) ==1)
        {
            if( numara == c1.id )
            {
                durum=1;
                break;
            }
            sayac++;     
        }
        if(durum==0)
        printf("%d numarali musteri bulunamadi \n", numara);
        else
        {
            system("cls");
            printf("güncellemek istediginiz musteri bilgileri \n");
            printf("AD : "); scanf("%[^\n]s", c1.name);
            printf("SOYAD : "); scanf("%[^\n]s", c1.surname);
            printf("ADRES: "  ); scanf("%[^\n]s", c1.address);
            printf("TELEFON : "); scanf("%[^\n]s", c1.phone);
            printf("MAİL : "); scanf("%[^\n]s", c1.email);
            
            fwrite(&c1, sizeof(Customer), 1, ptr);
            printf("\n\n%d numarali musteri guncellendi \n", numara);
        }
    }
    fclose(ptr);
}
void deleteCustomer()
{

}

    

#endif // CUSTOMER_H