#ifndef KITCHEN_H
#define KITCHEN_H

//this is a c library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>



#define MAX_YEMEK 100
#define MAX_SIPARIS 100
#define MAX_ASCILAR 3

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

// aşcı sayısını belirle 

typedef struct {
    int asciID;

} Asci;

int asciSayisiBelirle()
{
    int asciSayisi;
    printf("Asci sayisini giriniz: ");
    scanf("%d", &asciSayisi);
    return asciSayisi;
}

// girilen aşçı sayısı kadar aşçı oluştur
void asciOlustur(Asci ascilar[], int asciSayisi)
{
    for (int i = 0; i < asciSayisi; i++)
    {
        ascilar[i].asciID = i;
    }
}


#endif // KITCHEN_H