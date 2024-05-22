#ifndef KITCHEN_H
#define KITCHEN_H

//this is a c library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>


/*#define MAX_YEMEK 100
#define MAX_SIPARIS 100
#define MAX_ASCILAR 3*/

/*typedef struct {
    char yemekAdi[50];
    int yemekFiyati;
    int hazirlanmaSuresi;
    int mevcut;
} Yemek;

typedef struct {
    int siparisID;
    char yemekAdi[50];
    int siparisZamani;
    int hazirlanmaZamani;
} Siparis;

typedef struct {
    int bitisZamani;
} Asci;


// Aşçı kuyruk yönetimi
void siparisleriYonet(Yemek yemekListesi[], int yemekSayisi, Siparis siparisListesi[], int siparisSayisi) {
    Asci ascilar[MAX_ASCILAR] = {{0}, {0}, {0}};

    for (int i = 0; i < siparisSayisi; i++) {
        int minBitisZamani = ascilar[0].bitisZamani;
        int secilenAsci = 0;

        for (int j = 1; j < MAX_ASCILAR; j++) {
            if (ascilar[j].bitisZamani < minBitisZamani) {
                minBitisZamani = ascilar[j].bitisZamani;
                secilenAsci = j;
            }
        }

        for (int k = 0; k < yemekSayisi; k++) {
            if (strcmp(yemekListesi[k].yemekAdi, siparisListesi[i].yemekAdi) == 0 && yemekListesi[k].mevcut) {
                int baslamaZamani = (minBitisZamani > siparisListesi[i].siparisZamani) ? minBitisZamani : siparisListesi[i].siparisZamani;
                siparisListesi[i].hazirlanmaZamani = baslamaZamani + yemekListesi[k].hazirlanmaSuresi;
                ascilar[secilenAsci].bitisZamani = siparisListesi[i].hazirlanmaZamani;
                printf("Sipariş ID: %d, Yemek: %s, Başlama Zamani: %d, Bitiş Zamani: %d\n", siparisListesi[i].siparisID,
                       siparisListesi[i].yemekAdi, baslamaZamani, siparisListesi[i].hazirlanmaZamani);
                break;
            }
        }
    }
}
*/
#define ASCI_SAYISI 5 



void asciZamanAyarla(Asci* asci,Asci*zaman);
void asciZamanYazdir(Asci* asci,Asci*zaman);
int AsciTanimlama();
//void asciSil(Asci ascilar[], int asciSayisi);


// Aşçı veri yapısı
typedef struct Asci  {
    char ID[10]; 
    struct tm zaman; 
} Asci;

// Aşçıların zamanını ayarlama fonksiyonu
void asciZamanAyarla(Asci* zaman, Asci* asci) {
    // Aşçı zamanını 12 Mayıs 1970 12:00 olarak ayarlama
    memset(&asci->zaman, 0, sizeof(struct tm));
    asci->zaman.tm_mday = 12;
    asci->zaman.tm_mon = 5 - 1;
    asci->zaman.tm_year = 1970 - 1900;
    asci->zaman.tm_hour = 12;
    asci->zaman.tm_min = 0;
    asci->zaman.tm_sec = 0;
}

// Aşçı zamanını formatlı olarak yazdırma fonksiyonu
void asciZamanYazdir(Asci* zaman, Asci* asci) {
    printf("%s zamani: %02d %02d %04d %02d:%02d:%02d\n", asci->ID, asci->zaman.tm_mday, asci->zaman.tm_mon + 1,
           asci->zaman.tm_year + 1900, asci->zaman.tm_hour, asci->zaman.tm_min, asci->zaman.tm_sec);
}

int AsciTanimlama(Asci *asci) {
    // Aşçıları tanımlama
    Asci asciListesi[ASCI_SAYISI];
    char asciID[3]; 
    for (int i = 0; i < ASCI_SAYISI; ++i) {
        sprintf(asciID, "A%d", i); 
        strcpy(asciListesi[i].ID, asciID);
        asciZamanAyarla(&asciListesi[i]); 
    }

    // Aşçıların zamanlarını yazdırma
    for (int i = 0; i < ASCI_SAYISI; ++i) {
        asciZamanYazdir(&asciListesi[i]);
    }

    return 0;
}









#endif // KITCHEN_H