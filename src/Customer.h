
#ifndef CUSTOMER_H
#define CUSTOMER_H
#define RESTAURANT_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Customer
{
    int id;
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
void deleteCustomer();
void CustomerMenu();
int ScanfOnlyAlphabetic(char *str);
int CheckPhone(char* data);
int CheckMailExistInFile(char* data);
int CheckPhoneExistInFile(char* data);
void ReNumberCustomers();
int CheckEmail(char* data);
int CheckEmail(char* data);





int CheckPhone(char* data) {
    //check if the phone number is 11 digits
    if(strlen(data) != 11) {
        return 0;
    }
    return 1;
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
    while (*str != '\0') {
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

Customer c1,c2;

void addCustomer()
{
    system("cls");
    printf("\n\t MUSTERI EKLEME \n\n");
   
    printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz : ");
    scanf("%s", c1.name);
    //if input is q or Q, exit the function
    if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
        return;
    }
    //until the input is valid, keep asking for the name or give option to quit by pressing q
    while(ScanfOnlyAlphabetic(c1.name) == 0){
        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
        printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf("%s", c1.name);
        if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
            return;
        }
    }
    
    printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz : "); 
    scanf("%s", c1.surname);
    if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
        return;
    }
    while(ScanfOnlyAlphabetic(c1.surname) == 0){
        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
        printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
        scanf("%s", c1.surname);
        if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
            return;
        }
    }
    
    printf("Musteri adresi giriniz ya da q girisi ile isleminizi iptal ediniz : "); 
    scanf("%s", c1.address);
    if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
        return;
    }
    while(strlen(c1.address) < 5){
        printf("Adres en az 5 karakter olmalidir. Lutfen tekrar giriniz: ");
        scanf("%s", c1.address);
        if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
            return;
        }
    }
    
    start:
    printf("Lutfen telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
    scanf("%s", c1.phone);
    if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
        return;
    }
    while(strlen(c1.phone) != 11){
        printf("Telefon numarasi 11 haneli olmalidir. Lutfen tekrar giriniz: ");
        scanf("%s", c1.phone);
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
    scanf("%s",c1.email);
    if(strcmp(c1.email,"q") == 0 || strcmp(c1.email,"Q") == 0){
        return;
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



    printf("\n\nMusteri bilgileri \n");

    printf("Musteri adi : %s \n", c1.name);
    printf("Musteri soyadi : %s \n", c1.surname);
    printf("Musteri adresi : %s \n", c1.address);
    printf("Musteri telefonu : %s \n", c1.phone);
    printf("Musteri email : %s \n", c1.email);
        
    
     // musterilere 000-999 arasinda numara verilir
    int numara = 000;
    FILE *numPtr = fopen("musteriNumarasi.dat", "a+b");
    if (numPtr != NULL) 
    {
        
        fseek(numPtr, 0, SEEK_END);
        
        
        long size = ftell(numPtr);
        
        if (size == 0) 
        {
            fwrite(&numara, sizeof(int), 1, numPtr);
        } 
        else 
        {
            
            fseek(numPtr, -sizeof(int), SEEK_END);
            fread(&numara, sizeof(int), 1, numPtr);
            
           
            if (numara < 999) {
                numara++;
            } else {
                printf("Musteri numarasi siniri asildi!\n");
                fclose(numPtr);
            }
            
           
            fseek(numPtr, 0, SEEK_END);
            fwrite(&numara, sizeof(int), 1, numPtr);
        }

        
        printf("Musteri numarasi: %03d\n", numara);
        fclose(numPtr);
    } 
    else 
    {
        printf("Dosya acilamadi!\n");
    }
    c1.id = numara; 
    FILE *fileWrite = fopen("musteri.dat","a+b");
    fwrite(&c1, sizeof(Customer), 1, fileWrite);
    fclose(fileWrite);
    printf("\n\n%03d numarali musteri eklendi \n", c1.id); 
} 
  
void CustomerList()
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
                    scanf("%s", c1.name);
                    while(ScanfOnlyAlphabetic(c1.name) == 0){
                        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
                        printf("Musteri adi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
                        scanf("%s", c1.name);
                        if(strcmp(c1.name,"q") == 0 || strcmp(c1.name,"Q") == 0){
                            return;
                        }
                    }
                    break;

                case 2:
                    printf("Yeni soyadi giriniz: or q to cancel ");
                    scanf("%s", c1.surname);
                    while(ScanfOnlyAlphabetic(c1.surname) == 0){
                        printf("Gecersiz karakter. Lutfen sadece harf giriniz.\n");
                        printf("Musteri soyadi giriniz ya da q girisi ile isleminizi iptal ediniz: ");
                        scanf("%s", c1.surname);
                        if(strcmp(c1.surname,"q") == 0 || strcmp(c1.surname,"Q") == 0){
                            return;
                        }
                    }
                    break;

                case 3:
                    printf("Yeni adresi giriniz: or q to cancel:");
                    scanf("%s", c1.address);
                    while(strlen(c1.address) < 5){
                        printf("Adres en az 5 karakter olmalidir. Lutfen tekrar giriniz: ");
                        scanf("%s", c1.address);
                        if(strcmp(c1.address,"q") == 0 || strcmp(c1.address,"Q") == 0){
                            return;
                        }
                    }
                    break;

                case 4:
                    printf("Yeni telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
                    scanf("%s", c1.phone);
                    while(strlen(c1.phone) != 11){
                        printf("Telefon numarasi 11 haneli olmalidir. Lutfen tekrar giriniz: ");
                        scanf("%s", c1.phone);
                        if(strcmp(c1.phone,"q") == 0 || strcmp(c1.phone,"Q") == 0){
                            return;
                        }
                    }                   
                    break;

                case 5:
                    UpdateMail:
                    printf("enter a new mail or q to exit");
                    scanf("%s", c1.email);
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
                    scanf("%s", c1.password);
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

void deleteCustomer()
{
    system("cls");
    printf("\n\t MUSTERI LISTESI \n\n");
    int sayac=0,numara,durum=0;
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

        printf("\n\nSilmek istediginiz musteri numarasini giriniz : "); scanf("%d", &numara);

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
           
            printf("%03d %-20s %-20s %-20s %-15d %-20s\n",c1.id ,c1.name,c1.surname , c1.address ,c1.phone ,c1.email );
            char tercih;
            printf("\n\n%d numarali musteri silinsin mi (E/H) : ", numara); scanf(" %c", &tercih);
            if(tercih=='E' || tercih=='e')
            {
                FILE *tempPtr = fopen("temp.dat", "w+b");
                while(fread(&c1, sizeof(Customer), 1, ptr) ==1)
                {
                    if( numara != c1.id )
                    {
                        fwrite(&c1, sizeof(Customer), 1, tempPtr);
                    }
                }
           
            fclose(ptr);
            fclose(tempPtr);

            remove("musteri.dat");
            rename("temp.dat", "musteri.dat");
            system("cls");
            printf("\n\n%d numarali musteri silindi \n", numara);
            }else if (tercih=='H' || tercih=='h'){
            printf("Musteri silme işlemi iptal edildi\n");
        
            }else{
            printf("Hatali secim yaptiniz\n");
            }
        }
        
    }
    fclose(ptr);


}

void CustomerMenu() {
       
        int sec;
        printf("\n\t MUSTERI ISLEMLERI \n\n");
        printf("\t1-MUSTERI EKLE \n");
        printf("\t2-MUSTERI LISTELE \n");
        printf("\t3-MUSTERI GUNCELLE \n");
        printf("\t4-MUSTERI SIL \n");
        printf("\t0-ANA MENU \n");
        printf("\tSECIMINIZ : ");
        scanf("%d", &sec);
        system("cls");
        
        switch (sec)
            {
            case 1:
                addCustomer();
                break;
            case 2:
                ReNumberCustomers();
                CustomerList();
                break;
            case 3:
                updateCustomer();
                break;
            case 4:
                deleteCustomer();
                ReNumberCustomers();
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

    //from the start to the @ sign, check if the email is valid
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '@') {
            if (i == 0) {
                return 0;
            }
            return 1;
        }
    }
    //loop until finding the @ after that if there is a gmail.com or outlook.com or email.com return 1
    char* ptr = data;
    while (*ptr != '\0') {
        if (*ptr == '@') {
            if (strcmp(ptr + 1, "gmail.com") == 0 || strcmp(ptr + 1, "outlook.com") == 0 || strcmp(ptr + 1, "email.com") == 0) {
                return 1;
            }
        }
        ptr++;
    }
    return 0;
}

void ReNumberCustomers() {
    //reassign the customer numbers
    FILE *file = fopen("musteri.dat", "r+b");
    Customer c1;
    int numara = 0;
    while(fread(&c1, sizeof(Customer), 1, file) == 1) {
        c1.id = numara;
        fseek(file, -sizeof(Customer), SEEK_CUR);
        fwrite(&c1, sizeof(Customer), 1, file);
        numara++;
    }
    fclose(file);
    FILE *numPtr = fopen("musteriNumarasi.dat", "w+b");
    fwrite(&numara, sizeof(int), 1, numPtr);
    fclose(numPtr);
}








#endif // CUSTOMER_H
