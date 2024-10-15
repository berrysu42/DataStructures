#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kitap{
    char kitapAd[30];
    float fiyat;
    int sSayisi;
};
int main()

{   /*
    //Dogrudan struct kullanimi
    struct kitap kitap1;
    strcpy(kitap1.kitapAd,"Turk Tarihi");
    kitap1.fiyat=225.50;
    kitap1.sSayisi=650;
    //kontrol
    printf("Kitap1 Bilgileri: %s %.2f %d ",kitap1.kitapAd,kitap1.fiyat,kitap1.sSayisi);
    */


    //pointer yardýmýyla struct kullanimi
    struct kitap *kitap2 = (struct kitap *)malloc(sizeof(struct kitap));
    strcpy(kitap2->kitapAd,"Fabrika Ayarlari");
    kitap2->fiyat=110.50;
    kitap2->sSayisi=200;
    //kontrol
    printf("Kitap 2 Bilgileri: %s %f %d",kitap2->kitapAd,kitap2->fiyat,kitap2->sSayisi);



    return 0;
}
