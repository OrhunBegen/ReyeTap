#ifndef CUSTOMER_H
#define CUSTOMER_H




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "Kitchen.h"






typedef struct Customer
{
    int  id;
    char name[50];
    char surname[50];
    char address[100];
    char phone[15];
    char email[50];
    char password[50];

} Customer;


void BringTheFoodList();

int addCustomer();
void CustomerList();
void updateCustomer();
//void deleteCustomer();
int CustomerMenu();
int ScanfOnlyAlphabetic(char *str);
int ScanfOnlyNumeric(char *str);
int CheckPhone(char* data);
int CheckMailExistInFile(char* data);
int CheckPhoneExistInFile(char* data);
void ReIDCustomers();
int CheckEmail(char* data);
int CheckEmail(char* data);

int passwordCheck(char* data);
int loginCustomer(char* email, char* password);

void LogIn();
void DeleteCustomerByID(int SpecialID);
void DeleteTheAccountsMailsThatAreNamedOrhun();
void RenameTheMail(int ID);

void ShowMyPastOrders(int ID);

int MakeAOrderByID(int ID);

void AdjustTheSelectedCustomerParamaterByID(int SpecialID);
int LoginCustomerReturnID();

void BringTheAvailableFoods();
int CheckIfFoodIsAvailable(int orderNumber);





int CheckPhone(char* data){
    //check if the phone number is 11 digits
    if(strlen(data) != 11) {
        return 0;
    }else{
        return 1;
    } 
    
}
    
int CheckMailExistInFile(char* data) {
    //check if the email is already in the file
    FILE *file = fopen("musteri.dat", "r+b");
    Customer c1;
    while(fread(&c1, sizeof(Customer), 1, file) == 1) {
        if(strcmp(c1.email, data) == 0) {
            return 1;
        }
    }
    return 0;
}

int CheckPhoneExistInFile(char* data) {
    //check if the phone number is already in the file
    FILE *file = fopen("musteri.dat", "r+b");
    Customer c1;
    while(fread(&c1, sizeof(Customer), 1, file) == 1) {
        if(strcmp(c1.phone, data) == 0) {
            return 1;
        }
    }
    return 0;
}

int ScanfOnlyAlphabetic(char *str) {
       //or space
       // Loop through each character in the string
    while (*str != '\0') 
    {
        // Check if the character is alphabetic or a space
        if (!isalpha(*str) && *str != ' ') {
            // If it's not alphabetic or a space, return 0
            return 0;
        }
        // Move to the next character
        str++;
    }
    // If all characters are alphabetic or spaces, return 1
    return 1;

}

int ScanfOnlyNumeric(char *str) {
    //check if the string is numeric
    //if it is not numeric return 0
    //if it is numeric return 1
    //cant be negative
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    
}

Customer c1,c2;

void LogIn(){
    char email[50], password[50];
    printf("Email: ");
    scanf(" %[^\n]", email);
    printf("Password: ");   
    scanf(" %[^\n]", password);
    while(passwordCheck(password) == 0){
        printf("Gecersiz sifre. Sifre en az 6 karakter olmalidir ve bosluk icermemelidir. Lutfen tekrar giriniz: ");
        scanf(" %[^\n]", password);
        if(strcmp(password,"q") == 0 || strcmp(password,"Q") == 0){
            return;
        }
    }
    if(CheckEmail(email) == 0) {
        printf("Gecersiz email. Lutfen gmail.com, outlook.com veya email.com uzantili bir email giriniz.\n");
        return;
    }
    if(loginCustomer(email, password) == 1) {
        printf("Giris basarili\n");
    } else {
        printf("Giris basarisiz\n");
        return;
    }
}

int addCustomer()
{
    system("cls");
    printf("\n\t MUSTERI EKLEME \n\n");
   
    printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz : ");
    scanf(" %[^\n]", c1.name);
    //if input is q or Q, exit the function
    if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
        return -1;
    }
    //until the input is valid, keep asking for the name or give option to quit by pressing q
    while(ScanfOnlyAlphabetic(c1.name) == 0){
        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
        printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf(" %[^\n]", c1.name);
        if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
            return -1;
        }
    }
    
    printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz : "); 
    scanf(" %[^\n]", c1.surname);
    if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
        return -1;
    }
    while(ScanfOnlyAlphabetic(c1.surname) == 0){
        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
        printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf(" %[^\n]", c1.surname);
        if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
            return -1;
        }
    }
    
    printf("Musteri adresi giriniz ya da q girisi ile isleminizi iptal ediniz : "); 
    scanf(" %[^\n]", c1.address);
    if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
        return -1;
    }
    while(strlen(c1.address) < 5){
        printf("Adres en az 5 karakter olmalidir. Lutfen tekrar giriniz: ");
        scanf(" %[^\n]", c1.address);
        if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
            return -1;
        }
    }
    
    start:
    printf("Lutfen telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
    scanf(" %[^\n]", c1.phone);
    if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
        return -1;
    }
        while(strlen(c1.phone) != 11 || ScanfOnlyNumeric(c1.phone) == 0){
        printf("Gecersiz telefon numarasi. Lutfen 11 haneli ve sadece rakamlardan olusan bir numara giriniz: ");
        scanf(" %[^\n]", c1.phone);
        if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
             return -1;
        }
    }
   
    if(CheckPhoneExistInFile(c1.phone) == 1) {
        printf("Bu telefon numarasi zaten kayitli. Lutfen farkli bir telefon numarasi giriniz.\n");
        goto start;
    }
    
    mail:
    printf("Musteri email giriniz q girisi ile isleminizi iptal ediniz : "); 
    scanf(" %[^\n]", c1.email);
    if(strcmp(c1.email,"q") == 0 || strcmp(c1.email,"Q") == 0){
        return -1;
    }
    
    int i = 0;
    while(isalpha(c1.email[i])) { // Harfle başlamalı
        i++;
    }

    while(c1.email[i] != '@') { // @ karakterine kadar olan kısmı kontrol et
        if(!isalnum(c1.email[i])) { // Harf veya sayı olmalı
            printf("Gecersiz karakterler kullanildi. Lutfen gecerli bir mail adresi giriniz.\n");
            goto mail;
        }
        i++;
    }

    if(CheckEmail(c1.email) == 0) {
        printf("Gecersiz email. Lutfen gmail.com, outlook.com veya email.com uzantili bir email giriniz.\n");
        goto mail;
    }

    if(CheckMailExistInFile(c1.email) == 1) {
        printf("Bu email zaten kayitli. Lutfen farkli bir email giriniz.\n");
        goto mail;
    }
    printf("\n\nMusteri password enter or q to exit : ");
    scanf("%s", c1.password);
    if(strcmp(c1.password,"q") == 0 || strcmp(c1.password,"Q") == 0){
        return -1;
    }

    while(passwordCheck(c1.password) == 0){
        printf("Gecersiz sifre. Sifre en az 6 karakter olmalidir ve bosluk icermemelidir. Lutfen tekrar giriniz: ");
        scanf(" %[^\n]", c1.password);
        if(strcmp(c1.password,"q") == 0 || strcmp(c1.password,"Q") == 0){
            return -1;
        }
    }


    FILE *ptr= fopen("musteri.dat","a+b");
    fseek(ptr, 0, SEEK_END);
    c1.id = ftell(ptr)/sizeof(Customer) + 1;
    fwrite(&c1, sizeof(Customer), 1, ptr);
    fclose(ptr);
    ReIDCustomers();
    printf("\n\nMusteri eklendi \n");
    return -2;
    
    
     
} 
  
/*void CustomerList()
{
    Customer c1;
    system("cls");
    printf("\n\t MUSTERI LISTELE \n\n");

    int sayac=0;
    printf("%-10s %-20s %-20s %-20s %-15s %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");
    
    FILE *ptr= fopen("musteri.dat","r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        printf("%03d %-20s %-20s %-20s %-15s %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
        sayac++;
        
    }
    fclose(ptr);

    if(sayac==0)
    {
        system("cls");
        printf("\n Listelenecek musteri bulunamadi \n");
    }else{
        printf("\n\nToplam %d musteri bulunmaktadir \n", sayac);
    }
    

}*/
void CustomerList() {
    Customer c1;
    system("cls");
    printf("\n\t MUSTERI LISTELE \n\n");

    int sayac = 0;
    printf("%-10s %-20s %-20s %-30s %-15s %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");
    
    FILE *ptr = fopen("musteri.dat","r+b");
    if (ptr == NULL) {
        printf("Dosya acilamadi.");
        return;
    }

    while (fread(&c1, sizeof(Customer), 1, ptr) == 1) {
        // Adresi belirli bir karakter sınırında yazdırma
        char truncatedAddress[21];
        if (strlen(c1.address) > 20) {
            strncpy(truncatedAddress, c1.address, 17);
            strcat(truncatedAddress, "...");
        } else {
            strcpy(truncatedAddress, c1.address);
        }
        printf("%03d %-20s %-20s %-30s %-15s %-20s\n",c1.id ,c1.name,c1.surname , truncatedAddress ,c1.phone ,c1.email );
        sayac++;
    }
    fclose(ptr);

    if (sayac == 0) {
        system("cls");
        printf("\n Listelenecek musteri bulunamadi \n");
    } else {
        printf("\n\nToplam %d musteri bulunmaktadir \n", sayac);
    }
}

void updateCustomer()
{  
    system("cls");
    printf("\n\t MUSTERI LISTESI \n\n");
    int sayac=0,numara=0,durum=0,secim=0;
    printf("%-10s %-20s %-20s %-20s %-15s %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");
    
    FILE *ptr= fopen("musteri.dat","r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) ==1)
    {
        printf("%03d %-20s %-20s %-20s %-15s %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
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
            printf("%03d numarali musteri bulunamadi \n", numara);
        else
        {system("cls");
            printf("Guncellemek istediginiz bilgiyi seciniz:\n");
            printf("1. AD\n");
            printf("2. SOYAD\n");
            printf("3. ADRES\n");
            printf("4. TELEFON\n");
            printf("5. MAIL\n");
            printf("6. PASSWORD\n");
            printf("Secim: ");
            scanf("%d", &secim);

            switch (secim)
            {
                case 1:
                    printf("Yeni adi giriniz: or q to cancel:");
                    scanf(" %[^\n]", c1.name);
                    while(ScanfOnlyAlphabetic(c1.name) == 0){
                        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
                        printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
                        scanf(" %[^\n]", c1.name);
                        if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
                            return;
                        }
                    }
                    break;

                case 2:
                    printf("Yeni soyadi giriniz: or q to cancel ");
                    scanf(" %[^\n]", c1.surname);
                    while(ScanfOnlyAlphabetic(c1.surname) == 0){
                        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
                        printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
                        scanf(" %[^\n]", c1.surname);
                        if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
                            return;
                        }
                    }
                    break;

                case 3:
                    printf("Yeni adresi giriniz: or q to cancel:");
                    scanf(" %[^\n]", c1.address);
                    while(strlen(c1.address) < 5){
                        printf("Adres en az 5 karakter olmalidir. Lutfen tekrar giriniz: ");
                        scanf(" %[^\n]", c1.address);
                        if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
                            return;
                        }
                    }
                    break;

                case 4:
                    printf("Yeni telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
                    scanf(" %[^\n]", c1.phone);
                    while(strlen(c1.phone) != 11){
                        printf("Telefon numarasi 11 haneli olmalidir. Lutfen tekrar giriniz: ");
                        scanf(" %[^\n]", c1.phone);
                        if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
                            return;
                        }
                    }                   
                    break;

                case 5:
                    UpdateMail:
                    printf("enter a new mail or q to exit");
                    scanf(" %[^\n]", c1.email);
                    if(strcmp(c1.email,"q") == 0 || strcmp(c1.email,"Q") == 0){
                        return;
                    }
                    if(CheckEmail(c1.email) == 0) {
                        printf("Gecersiz email. Lutfen gmail.com, outlook.com veya email.com uzantili bir email giriniz.\n");
                        goto UpdateMail;
                    }
                    break;
                
                case 6:
                    printf("Yeni password enter or q to exit : ");
                    scanf(" %[^\n]", c1.password);
                    if(strcmp(c1.password,"q") == 0 || strcmp(c1.password,"Q") == 0){
                        return;
                    }
                    break;

                default:
                    printf("Gecerli bir secim yapmadiniz.");
                    break;
            }        
            fseek(ptr, sayac*sizeof(Customer), SEEK_SET);
            fwrite(&c1, sizeof(Customer), 1, ptr);
            printf("\n\n%03d numarali musteri guncellendi \n", numara);
        }
    }
    fclose(ptr);
 
}

/*void deleteCustomer()
{
 system("cls");
    
    // Müşteri listesini yazdır
    printf("\n\t MUSTERI LISTESI \n\n");
    int sayac = 0, numara = 0, durum = 0;
    printf("%-10s %-20s %-20s %-20s %-15s %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");

    FILE *ptr = fopen("musteri.dat", "r+b");
    if(ptr == NULL) {
        printf("Dosya acilamadi.");
        return;
    }

    while (fread(&c1, sizeof(Customer), 1, ptr) == 1) {
        printf("%03d %-20s %-20s %-20s %-15s %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
        sayac++;
    }

    if(sayac == 0) {
        system("cls");
        printf("\n Listelenecek musteri bulunamadi \n");
    } else {
        rewind(ptr);
        printf("\n\nSilinecek musteri numarasini giriniz : "); 
        scanf("%d", &numara);

        while(fread(&c1, sizeof(Customer), 1, ptr) == 1) {
            if(numara == c1.id) {
                durum = 1;
                break;
            }
            sayac++;     
        }

        if(durum == 0)
            printf("%03d numarali musteri bulunamadi \n", numara);
        else {
            FILE *tempPtr = fopen("temp.dat", "wb");
            rewind(ptr);
            while(fread(&c1, sizeof(Customer), 1, ptr) == 1) {
                if(c1.id != numara) {
                    fwrite(&c1, sizeof(Customer), 1, tempPtr);
                }
            }
            fclose(ptr);
            fclose(tempPtr);
            remove("musteri.dat");
            rename("temp.dat", "musteri.dat");
            printf("\n\n%03d numarali musteri silindi \n", numara);
        }
    }

}*/

/*
void deleteCustomer() {
    system("cls");
    
    // Müşteri listesini yazdır
    printf("\n\t MUSTERI LISTESI \n\n");
    int sayac = 0, numara = 0, durum = 0;
    printf("%-10s %-20s %-20s %-20s %-15s %-20s\n","ID","ADI","SOYADI","ADRESI","TELEFONU","EMAIL");

    FILE *ptr = fopen("musteri.dat", "r+b");
    if(ptr == NULL) {
        printf("Dosya acilamadi.");
        return;
    }

    while (fread(&c1, sizeof(Customer), 1, ptr) == 1) {
        printf("%03d %-20s %-20s %-20s %-15s %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
        sayac++;
    }

    if(sayac == 0) {
        system("cls");
        printf("\n Listelenecek musteri bulunamadi \n");
    } else {
        rewind(ptr);
        printf("\n\nSilinecek musteri numarasini giriniz : "); 
        scanf("%d", &numara);

        while(fread(&c1, sizeof(Customer), 1, ptr) == 1) {
            if(numara == c1.id) {
                durum = 1;
                break;
            }
        }

        if(durum == 0) {
            printf("%03d numarali musteri bulunamadi \n", numara);
        } else {
            FILE *tempPtr = fopen("temp.dat", "wb");
            rewind(ptr);
            while(fread(&c1, sizeof(Customer), 1, ptr) == 1) {
                if(c1.id != numara) {
                    fwrite(&c1, sizeof(Customer), 1, tempPtr);
                }
            }
            fclose(ptr);
            fclose(tempPtr);
            remove("musteri.dat");
            rename("temp.dat", "musteri.dat");
            printf("\n\n%03d numarali musteri silindi \n", numara);
        }
    }
}
*/

int CustomerMenu() {
        
        int x;
        int y;

        StartP:
        printf("\n\tMUSTERI MENU \n\n");
        printf("\t1-hesap olustur \n");
        printf("\t2-giris yap \n");
        printf("\tseciminiz : ");
        scanf("%d", &x);
        system("cls");
        
      
        if (x == 1)
        {
            addCustomer();
        }
        else if (x == 2)
        {
            
            LoginCustomerReturnID();
            
        }
        
        else
        {
            printf("WRONG CHOICE\n");
            goto StartP;
        }
 }

 

int CheckEmail(char* data) {
    //if mail starts with @ return 0
    if(data[0] == '@') {
        return 0;
    }


    //loop until finding the @ after that if there is a gmail.com or outlook.com or email.com return 1

    int i = 0;
    while(data[i] != '@') {
        i++;
    }
    if(strcmp(data + i + 1, "gmail.com") == 0 || strcmp(data + i + 1, "outlook.com") == 0 || strcmp(data + i + 1, "email.com") == 0) {
        return 1;
    }
    return 0;

}

void ReIDCustomers()
 {  
    //count the number of customers by the surname of the customers
    int count = 0;
    FILE *file = fopen("musteri.dat", "r+b");
    while(fread(&c1, sizeof(Customer), 1, file) == 1) {
        count++;
    }
    fclose(file);
    //if there are no customers, return
    if(count == 0) {
        return;
    }
    //if there are customers, assign new ids to them
    Customer *customers = (Customer*)malloc(count * sizeof(Customer));
    file = fopen("musteri.dat", "r+b");
    for(int i = 0; i < count; i++) {
        fread(&customers[i], sizeof(Customer), 1, file);
    }
    fclose(file);
    file = fopen("musteri.dat", "w+b");
    for(int i = 0; i < count; i++) {
        customers[i].id = i + 1;
        fwrite(&customers[i], sizeof(Customer), 1, file);
    }
    fclose(file);
    free(customers);
}

int passwordCheck(char* data) {
    //password cant contain space
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == ' ') {
            return 0;
        }
    }
    //password must be at least 6 characters
    if (strlen(data) < 6) {
        return 0;
    }
    return 1;

}

int loginCustomer(char* email, char* password) {
    FILE *file = fopen("musteri.dat", "r+b");
    while(fread(&c1, sizeof(Customer), 1, file) == 1) {
        if(strcmp(c1.email, email) == 0 && strcmp(c1.password, password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}










// BUNLARA BAKIN
int MakeAOrderByID(int ID)
{    
    BringTheAvailableFoods();

    //get the order number from the customer
    
    int orderNumber;

    printf("hangi yemeği sipariş etmek istersiniz? : ");

    scanf("%d", &orderNumber);

    //check if the order is available

    CheckIfFoodIsAvailable(orderNumber);


    FILE *file = fopen("TextFiles/FoodList.txt", "r");
    
    //print out the orderNumber's line from the TextFiles/FoodList.txt

    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        i++;
        //order number + 1 because there is a title
        if (i == orderNumber+1) {
            printf("%s", line);
        }
    }

    fclose(file);

    int Line = orderNumber+1;
    char OrderName[50];
    char OrderPrice[50];
    char OrderPrepTime[50];
    char OrderState[50];

    FILE *file2 = fopen("TextFiles/FoodList.txt", "r");
    //1 -- Hamburger -- 15 TL -- 10 -- Available

    //now save this line inside these 
    //Line, OrderName, OrderPrice, OrderPrepTime, OrderState
    
    
    i = 0;
    while (fgets(line, sizeof(line), file2)) {
        i++;
        if (i == Line) {
            sscanf(line, "%d -- %[^--] -- %[^TL] TL -- %[^--] -- %[^\n]", &Line, OrderName, OrderPrice, OrderPrepTime, OrderState);
        }
    }
    fclose(file2);

    // printf("Line: %d\n", Line);
    // printf("OrderName: %s\n", OrderName);
    // printf("OrderPrice: %s\n", OrderPrice);
    // printf("OrderPrepTime: %s\n", OrderPrepTime);
    // printf("OrderState: %s\n", OrderState);

    //get the current date from the system year month day by windows.h


    int year, month, day;
    SYSTEMTIME t;
    GetLocalTime(&t);
    year = t.wYear;
    month = t.wMonth;
    day = t.wDay;

    //Date_UserID -- FoodName -- Price TL --  UserName


    //for the OrderList.txt enter the order as

    //Date_UserID -- FoodName -- Price TL -- PrepTime -- UserName

    FILE *file3 = fopen("TextFiles/OrderList.txt", "a");

    fprintf(file3, "%d-%d-%d_%d -- %s -- %s TL -- %s -- %s\n", year, month, day, ID, OrderName, OrderPrice, OrderPrepTime, c1.name);

    fclose(file3);
    
    printf("order");

    return 1;
    

   








    

    





} 

void DeleteCustomerByID(int SpecialID)
{
    FILE *ptr = fopen("musteri.dat", "r+b");
    FILE *tempPtr = fopen("temp.dat", "wb");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        if (c1.id != SpecialID)
        {
            fwrite(&c1, sizeof(Customer), 1, tempPtr);
        }
    }
    fclose(ptr);
    fclose(tempPtr);
    remove("musteri.dat");
    rename("temp.dat", "musteri.dat");
    printf("\n\n%03d numarali musteri silindi \n", SpecialID);
    return;
}

void AdjustTheSelectedCustomerParamaterByID(int SpecialID){

    printf("hangi parametreyi degistirmek istiyorsunuz ? \n");
    printf("1-Ad\n");
    printf("2-Soyad\n");
    printf("3-Adres\n");
    printf("4-Telefon\n");
    printf("5-Email\n");
    printf("6-Password\n");
    printf("Secim : ");
    int secim;
    scanf("%d", &secim);
    switch (secim)
    {
    case 1:
        printf("Yeni adi giriniz : ");
        scanf(" %[^\n]", c1.name); 
        while(ScanfOnlyAlphabetic(c1.name) == 0){
            printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
            printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
            scanf(" %[^\n]", c1.name);
            if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
                return;
            }
        }
        break;
    case 2:
        printf("Yeni soyadi giriniz : ");
        scanf(" %[^\n]", c1.surname);
        while(ScanfOnlyAlphabetic(c1.surname) == 0){
            printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
            printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
            scanf(" %[^\n]", c1.surname);
            if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
                return;
            }
        }
        break;
    case 3:
        printf("Yeni adresi giriniz : ");
        scanf(" %[^\n]", c1.address);
        while(strlen(c1.address) < 5){
            printf("Adres en az 5 karakter olmalidir. Lutfen tekrar giriniz: ");
            scanf(" %[^\n]", c1.address);
            if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
                return;
            }
        }
        break;
    case 4:
        printf("Yeni telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
        scanf(" %[^\n]", c1.phone);
        while(strlen(c1.phone) != 11){
            printf("Telefon numarasi 11 haneli olmalidir. Lutfen tekrar giriniz: ");
            scanf(" %[^\n]", c1.phone);
            if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
                return;
            }
        }                   
        break;
    case 5:
        UpdateMail:
        printf("enter a new mail or q to exit");
        scanf(" %[^\n]", c1.email);
        if(strcmp(c1.email,"q") == 0 || strcmp(c1.email,"Q") == 0){
            return;
        }
        if(CheckEmail(c1.email) == 0) {
            printf("Gecersiz email. Lutfen gmail.com, outlook.com veya email.com uzantili bir email giriniz.\n");
            goto UpdateMail;
        }
        break;
    case 6:
        printf("Yeni password enter or q to exit : ");
        scanf(" %[^\n]", c1.password);
        if(strcmp(c1.password,"q") == 0 || strcmp(c1.password,"Q") == 0){
            return;
        }
        break;
    default:
        printf("Gecerli bir secim yapmadiniz.");
        break;
    }
    FILE *ptr = fopen("musteri.dat", "r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        if (c1.id == SpecialID)
        {
            fseek(ptr, -sizeof(Customer), SEEK_CUR);
            fwrite(&c1, sizeof(Customer), 1, ptr);
            break;
        }
    }
    fclose(ptr);
    printf("\n\n%03d numarali musteri guncellendi \n", SpecialID);
    return;

}

//bu siliyo ama kullanmayacagiz 
void DeleteTheAccountsMailsThatAreNamedOrhun()
{
//if the mails named as Orhun delete them

    FILE *ptr = fopen("musteri.dat", "r+b");
    FILE *tempPtr = fopen("temp.dat", "wb");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        if (strcmp(c1.email, "Orhun") == 0)
        {
            fwrite(&c1, sizeof(Customer), 1, tempPtr);
        }
    }
    fclose(ptr);
    fclose(tempPtr);
    remove("musteri.dat");
    rename("temp.dat", "musteri.dat");
    printf("\n\nOrhun isimli musteriler silindi \n");
    return;
} 

//delete calismiyor son musteri account silince karisiyor bunu cagiracagiz ki sorun olmasin  ID'leri karismasin diye zaten giris yapamayacaklar
//siparis vermelerde vs ID inserting ile yapacagiz ona gore hazirlayin altta ornegi var int ID gibi

void RenameTheMailasOrhun(int ID)
{
    //rename the customer EMAIL to "Orhun"

    FILE *ptr = fopen("musteri.dat", "r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        if (c1.id == ID)
        {
            strcpy(c1.email, "Orhun");
            fseek(ptr, -sizeof(Customer), SEEK_CUR);
            fwrite(&c1, sizeof(Customer), 1, ptr);
            break;
        }
    }
    fclose(ptr);
    printf("\n\n%03d numarali musteri maili Orhun olarak degistirildi \n", ID);
    return;

}

int LoginCustomerReturnID()
{
   printf("Email :");
   scanf(" %[^\n]", c1.email);

    //mail has to obey the rules have been created for customer creation or press q to exit
    while (CheckEmail(c1.email) == 0)
    {
        printf("Gecersiz email. Lutfen gmail.com, outlook.com veya email.com uzantili bir email giriniz.\n");
        printf("Email :");
        scanf(" %[^\n]", c1.email);
        if(strcmp(c1.email,"q") == 0 || strcmp(c1.email,"Q") == 0){
            return 0;
        }
    }


    printf("Password :");
    scanf(" %[^\n]", c1.password);

    //password has to obey the rules have been created for customer creation or press q to exit

    while (passwordCheck(c1.password) == 0)
    {
        printf("Gecersiz sifre. Sifre en az 6 karakter olmalidir ve bosluk icermemelidir. Lutfen tekrar giriniz: ");
        scanf(" %[^\n]", c1.password);
        if(strcmp(c1.password,"q") == 0 || strcmp(c1.password,"Q") == 0){
            return 0;
        }
    }

    FILE *ptr = fopen("musteri.dat", "r+b");
    while (fread(&c1, sizeof(Customer), 1, ptr) == 1)
    {
        if (strcmp(c1.email, c1.email) == 0 && strcmp(c1.password, c1.password) == 0)
        {
            fclose(ptr);
            return c1.id;
        }
    }
    fclose(ptr);
    return -3;

}


void MusteriGirisYaptiMenu(int ID)
{
    int sec;
    
    Rms:

    printf("\n\t MUSTERI MENU\n\n");
    printf("\t1- Siparis Ver \n");
    printf("\t2- Gecmis Siparislerimi Goster \n");
    printf("\t3- Aktif siparislerimi Goster \n");
    printf("\t4- Hesabimi Sil \n");
    printf("\t0-  CIKIS \n");
    printf("\tseciminiz: ");
    scanf("%d", &sec);
    system("cls");

    if(sec == 1)
    {
        MakeAOrderByID(ID);
    }
    if(sec == 2)
    {
        //show the previous orders
    }
    if(sec == 3)
    {
        //show the active orders
    }
    if(sec == 4)
    {
        DeleteCustomerByID(ID);
    }
   
    else 
    {
        goto Rms;
    }
    
    
   
}    

void BringTheFoodList() {
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void BringTheAvailableFoods()
{
    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if(strstr(line, "Available") != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);





}

int CheckIfFoodIsAvailable(int OrderNumber){

    FILE *file;
    file = fopen("TextFiles/FoodList.txt", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
    }
   
    char line[100];
    int count = 1;
    while (fgets(line, sizeof(line), file)) {
        if(strstr(line, "Available") != NULL) {
            count++;
            if(count == OrderNumber -1 ) {
                printf("The order is available\n");
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    printf("The order is not available\n");
    return 0;
    

}



#endif //CUSTOMER_H
