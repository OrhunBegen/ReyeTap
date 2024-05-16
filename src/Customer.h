#ifndef CUSTOMER_H
#define CUSTOMER_H




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>



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

void addCustomer();
void CustomerList();
void updateCustomer();
//void deleteCustomer();
void CustomerMenu();
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

void addCustomer()
{
    system("cls");
    printf("\n\t MUSTERI EKLEME \n\n");
   
    printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz : ");
    scanf(" %[^\n]", c1.name);
    //if input is q or Q, exit the function
    if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
        return;
    }
    //until the input is valid, keep asking for the name or give option to quit by pressing q
    while(ScanfOnlyAlphabetic(c1.name) == 0){
        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
        printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf(" %[^\n]", c1.name);
        if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
            return;
        }
    }
    
    printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz : "); 
    scanf(" %[^\n]", c1.surname);
    if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
        return;
    }
    while(ScanfOnlyAlphabetic(c1.surname) == 0){
        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
        printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf(" %[^\n]", c1.surname);
        if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
            return;
        }
    }
    
    printf("Musteri adresi giriniz ya da q girisi ile isleminizi iptal ediniz : "); 
    scanf(" %[^\n]", c1.address);
    if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
        return;
    }
    while(strlen(c1.address) < 5){
        printf("Adres en az 5 karakter olmalidir. Lutfen tekrar giriniz: ");
        scanf(" %[^\n]", c1.address);
        if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
            return;
        }
    }
    
    start:
    printf("Lutfen telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
    scanf(" %[^\n]", c1.phone);
    if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
        return;
    }
        while(strlen(c1.phone) != 11 || ScanfOnlyNumeric(c1.phone) == 0){
        printf("Gecersiz telefon numarasi. Lutfen 11 haneli ve sadece rakamlardan olusan bir numara giriniz: ");
        scanf(" %[^\n]", c1.phone);
        if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
             return;
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
        return;
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
        return;
    }

    while(passwordCheck(c1.password) == 0){
        printf("Gecersiz sifre. Sifre en az 6 karakter olmalidir ve bosluk icermemelidir. Lutfen tekrar giriniz: ");
        scanf(" %[^\n]", c1.password);
        if(strcmp(c1.password,"q") == 0 || strcmp(c1.password,"Q") == 0){
            return;
        }
    }


    FILE *ptr= fopen("musteri.dat","a+b");
    fseek(ptr, 0, SEEK_END);
    c1.id = ftell(ptr)/sizeof(Customer) + 1;
    fwrite(&c1, sizeof(Customer), 1, ptr);
    fclose(ptr);
    ReIDCustomers();
    printf("\n\nMusteri eklendi \n");
    return;
    
    
     
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

void CustomerMenu() {
       
        int sec;
        printf("\n\tMUSTERI MENU \n\n");
        printf("\t1-hesap olustur \n");
        printf("\t2-giris yap \n");
        printf("\tseciminiz : ");
        scanf("%d", &sec);
        system("cls");
        
        switch (sec)
            {
            case 1:
                addCustomer();
               
            case 2:
                LogIn();
                
            case 0:
                break;
            default:
                printf("WRONG CHOICE\n");
                break;
                return;
            }
 }

 void RestaurantMenu() {
        int sec;
        printf("\n\t RESTAURANT MENU\n\n");
        printf("\t1- MUSTERI LISTELE \n");
        printf("\t2- MUSTERI SIL \n");
        printf("\t0-  MENU \n");
        printf("\tseciminiz: ");
        scanf("%d", &sec);
        system("cls");
        
        switch (sec)
            {
            case 1:
                CustomerList();
                break;
            case 2:
               // deleteCustomer();
                break;
            case 0:
                break;
            default:
                printf("hatali secim\n");
                break;
                return;
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
    //bring the FoodList.txt
    FILE *ptr = fopen("TextFiles/FoodList.txt", "r");
    if (ptr == NULL)
    {
        printf("Dosya acilamadi");
        return 0;
    }
    //print the food list
    char food[100];
    while (fgets(food, 100, ptr) != NULL)
    {
        printf("%s", food);
    }
    fclose(ptr);
    //take the order 
    //3 -- Chicken Burger -- 18 TL -- 12 -- Available
    //user has to enter 3

    printf("Enter the order: ");

    char order[100];
    scanf(" %[^\n]", order);
    //user only can enter the number
    while(ScanfOnlyNumeric(order) == 0){
        printf("Gecersiz karakter. Lutfen sadece rakam giriniz.\n");
        printf("Siparis numarasi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf(" %[^\n]", order);
        if(strcmp(order,"q") == 0 || strcmp(order,"Q") == 0){
            return 0;
        }
    }

    //open the FoodList.txt again and check if the from the FoodList.txt the order is Available or Not
    ptr = fopen("TextFiles/FoodList.txt", "r");
    if (ptr == NULL)
    {
        printf("Dosya acilamadi");
        return 0;
    }
    int i = 0;
    while (fgets(food, 100, ptr) != NULL)
    {
        i++;
        if (i == atoi(order))
        {
            if (strstr(food, "Available") == NULL)
            {
                printf("This food is not available\n");
                fclose(ptr);
                return 0;
            }
        }
    }
    fclose(ptr);
    //if the order is available, write the order to the Orders.txt
    FILE *orderPtr = fopen("TextFiles/OrderList.txt", "a");
    
    //Date_ID -- FoodsName -- FoodsPrice TL -- CustomerName




    //bu fprintfi duzeltir misiniz ?
    fprintf(orderPtr, "%s %d -- %s", __DATE__, ID, food);
    

        
    fclose(orderPtr);
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

    printf("Password :");
    scanf(" %[^\n]", c1.password);

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
    return 0;

}






#endif //CUSTOMER_H
