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
    while( fread(&numara, sizeof(int), 1, numPtr) != NULL )
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
    fwrite(&c1, sizeof(Customer), 1, ptr);
    fclose(ptr);
    printf("\n\n%d numarali musteri eklendi \n", c1.id);

}
void CustomerList()
{

}
void updateCustomer()
{

}
void deleteCustomer()
{

}
void MenuForCustomer()
    void CustomerMenu() {
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
            secim = CustomerMenu();
        }
    }

    int main() {
        CustomerMenu();
        return 0;
    }

#endif // CUSTOMER_H