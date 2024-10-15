#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef kullanarak struct yapisi olusturma

typedef struct{
    char adSoyad[50];
    int yas;
}yazar;
int main()
{
    /*
    // doðrudan kullaným
    yazar yazar1;
    strcpy(yazar1.adSoyad,"Ilber Oratyli");
    yazar1.yas=74;

    //kontrol
    printf("Yazar1 Bilgileri: %s %d",yazar1.adSoyad,yazar1.yas);
    */

    //pointer yardimiyla typedef struct kullanimi
    //struct kitap *kitap1 =(struct kitap *)malloc(sizeof(struct kitap)) farkini gormek icin tekrar yazdim.
    yazar * yazar2 = (yazar *)malloc(sizeof(yazar));
    strcpy(yazar2->adSoyad,"Hayati Inanc");
    yazar2->yas=60;

    //kontrol
    printf("Yazar2 Bilgileri\n AD-Soyad-> %s \n Yas-> %d",yazar2->adSoyad,yazar2->yas);
    return 0;
}
