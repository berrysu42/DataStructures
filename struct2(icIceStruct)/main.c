#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char takimAdi[30];
    int kYili;
}takim;

typedef struct{
    char adSoyad[30];
    int yas;
    takim Takim;
}futbolcu;

int main()
{
    futbolcu ftb;
    strcpy(ftb.adSoyad,"Arda Guler");
    ftb.yas=21;
    strcpy(ftb.Takim.takimAdi,"Real Madrid");
    ftb.Takim.kYili=1961;

    //kontrol
    printf("\t Bilgiler\n Futbolcu AdSoyad->%s \n Futbolcunun Yasi->%d \n Takiminin Adi->%s \n Takimimini Kurulus Yili->%d"
           ,ftb.adSoyad,ftb.yas,ftb.Takim.takimAdi,ftb.Takim.kYili);

    printf("\n******************************************\n");
    printf("\tFutbolcu Bilgiler\n Futbolcu Adi Soyadi->%s\n Yasi->%d\n",ftb.adSoyad,ftb.yas);

    //Boyle uzun uzun yazmak yerine takim strucindan bir veri olusturup da cekebiliriz.
    takim tkm;
    strcpy(tkm.takimAdi,"Besiktas");
    tkm.kYili=1964;

    //kontrol
    printf("\tTakim Bilgileri\n Takim Adi->%s\n Takim Kurulus Yili->%d",tkm.takimAdi,tkm.kYili);

    return 0;
}
