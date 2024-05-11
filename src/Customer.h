
#ifndef CUSTOMER_H
#define CUSTOMER_H
#define RESTAURANT_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Customer
{
    int id;
    char name[50];
    char surname[50];
    char address[100];
    char phone[15];
    char email[50];
} Customer;



void addCustomer();
void CustomerList();
void updateCustomer();
void deleteCustomer();
void CustomerMenu();




Customer c1,c2;



void addCustomer()
{
    system("cls");
    printf("\n\t MUSTERI EKLEME \n\n");
   
    int basamaksayisi=0;
    int validPart = 0;
    printf("Musteri adi giriniz : "); 
    scanf("%s", c1.name);
    printf("Musteri soyadi giriniz : "); 
    scanf("%s", c1.surname);
    printf("Musteri adresi giriniz : "); 
    scanf("%s", c1.address);
    printf("Musteri telefonu giriniz : "); 
    scanf("%s",c1.phone);

    while (!validPart) {
        printf("Lutfen telefon numarasini giriniz (11 haneli) veya 'q' girerek islemi iptal ediniz:");
        scanf("%s", c1.phone);

        // Girişin iptal edilip edilmediğini kontrol et
        if (strcmp(c1.phone, "q") == 0) {
            return; // İşlemi iptal et
        } else {
            // Telefon numarasının tüm karakterlerinin rakam olup olmadığını kontrol et
            validPart = 1; // Varsayılan olarak, girişin doğru olduğunu varsayalım.
            for (int i = 0; c1.phone[i] != '\0'; ++i) {
                if (!isdigit(c1.phone[i])) {
                    validPart = 0; // Bir karakter rakam değilse, geçersiz bir parça olarak işaretle
                    printf("Gecersiz karakter. Lutfen sadece rakam giriniz.\n");
                    break; // Daha fazla kontrol etmeye gerek yok, hata zaten var
                }
            }    
        }    
     }
    printf("Musteri email giriniz : "); 
    scanf("%s",c1.email);
   /* while (c1.phone!= 0) {
        c1.phone /= 10;
        basamaksayisi++;
    }
    if (basamaksayisi != 11) {
        printf("Telefon numarasi 11 haneli olmalidir!\n");
        //Programı kapatmayı yaz
        return;
    }else{
        printf("Musteri email giriniz : "); 
        scanf("%s",c1.email);
    }*/

   
    
    printf("Musteri adi : %s \n", c1.name);
    printf("Musteri soyadi : %s \n", c1.surname);
    printf("Musteri adresi : %s \n", c1.address);
    printf("Musteri telefonu : %s \n", c1.phone);
    printf("Musteri email : %s \n", c1.email);
        
    FILE *file = fopen("musteri.dat", "rb");
    if (file != NULL)
    {
        Customer temp;
        int found = 0;
        while (fread(&temp, sizeof(Customer), 1, file) == 1)
        {
            if (strcmp(temp.phone, c1.phone) == 0)
            {
                printf("Bu telefon numarasi zaten kayitli. Lutfen farkli bir numara giriniz.\n");
                found = 1;
                break;
            }
        }
        fclose(file);
        if (found)
        {
            return; // Tekrar müşteri eklemeyi iptal et
        }
    }
    else
    {
        printf("Dosya acilamadi!\n");
        return;
    }

     // musterilere 000-999 arasinda numara verilir
    int numara = 000;
    FILE *numPtr = fopen("musteriNumarasi.dat", "a+b");
    if (numPtr != NULL) {
        
        fseek(numPtr, 0, SEEK_END);
        
        
        long size = ftell(numPtr);
        
        if (size == 0) {
            fwrite(&numara, sizeof(int), 1, numPtr);
        } else {
            
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
    } else {
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
            printf("Secim: ");
            scanf("%d", &secim);

            switch (secim)
            {
                case 1:
                    printf("AD : ");
                    scanf("%s", &c1.name);
                    break;
                case 2:
                    printf("SOYAD : ");
                    scanf("%s", &c1.surname);
                    break;
                case 3:
                    printf("ADRES: ");
                    scanf("%s", &c1.address);
                    break;
                case 4:
                    printf("TELEFON : ");
                    scanf("%s", &c1.phone);
                    break;
                case 5:
                    printf("MAIL : ");
                    scanf("%s", &c1.email);
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
                printf("hatali secim\n");
                break;
            }
        
        
 }

    

#endif // CUSTOMER_H
