#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pointer yardimiyla ic›ce struct yapisi. Bu onemli cunku vy kisminda bu yapi modelini kullanacagiz.

typedef struct{
    char takimAdi[30];
    int kYili;
}takim;

typedef struct{
    char adSoyad[30];
    int yas;
    takim *takim;
}futbolcu;


int main()
{

    return 0;
}
