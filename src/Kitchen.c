#include "Kitchen.h"
#include "Restaurant.h"
#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    Yemek yemekListesi[MAX_YEMEK];
    Siparis siparisListesi[MAX_SIPARIS];

    int yemekSayisi = yemekleriOku(yemekListesi, "FoodList.txt");
    int siparisSayisi = siparisleriOku(siparisListesi, "OrderList.txt");

    siparisleriYonet(yemekListesi, yemekSayisi, siparisListesi, siparisSayisi);

    return 0;
}
