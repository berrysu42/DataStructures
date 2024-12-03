#include <stdio.h>
#include <stdlib.h>

struct node* head = NULL;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* nodeOlusturma(int veri){
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->prev = NULL;
    yeniDugum->next = NULL;

    return yeniDugum;
};

//sona yeni node ekleme
void sonaEkle(int veri){
    struct node* sonaEklenecekNode = nodeOlusturma(veri);
    if(head == NULL)
        head = sonaEklenecekNode;
    else{
        //travers (dolasma)
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        sonaEklenecekNode -> prev = temp;
        temp->next =sonaEklenecekNode;

    }
}

//basa node ekleme
void basaEkle(int veri){
    struct node* basaEklenecekNode = nodeOlusturma(veri);
    if(head == NULL){
        head = basaEklenecekNode;
        return ;
    }
    head->prev =basaEklenecekNode;
    basaEklenecekNode->next=head;
    head=basaEklenecekNode;
}

//araya eleman ekleme
void arayaEkle(int kiminOnu,int veri){ //veri=eklenecek deger
    struct node* temp = head;
    struct node* arayaEklenecekNode = nodeOlusturma(veri);
    struct node* onceki = NULL;

    if(head==NULL)
        head = arayaEklenecekNode;
    else if(head->data == kiminOnu)
            basaEkle(veri);
    else{
         //travers
        while(temp->next!=NULL){
            if(temp->data == kiminOnu){ //araya girecek olan elemandan bir onceki nodeu tuttuk
                    //a->b->c->d b ve c arasýna e gelsin burasi b yi tutma islemi yapr.
                    onceki = temp->prev;
                    break;
            }
            temp = temp->next;
        }
        temp->prev = arayaEklenecekNode;
        arayaEklenecekNode->next = temp;
        arayaEklenecekNode ->prev = onceki;
        onceki->next = arayaEklenecekNode;
        }

}

//bastan eleman silme
void bastanSil(){

    if(head==NULL){
        printf("Liste zaten bos!");

    }

    if (head->next == NULL){
        free(head);
        head = NULL;
        printf("Eleman kalmadi!");
        return;
    }
    struct node* ikinci = head->next;
    free(head);
    ikinci->prev= NULL;
    head = ikinci;
}

//sondan eleman silme
void sondanSil(){
     if(head==NULL){
        printf("Liste zaten bos!");
    }

    if (head->next == NULL){
        bastanSil();
        /*
        free(head);
        head = NULL;
        printf("Eleman kalmadi!");*/
        return;
    }
    //travers
    struct node* temp = head;
    while(temp->next != NULL){
            temp = temp->next;
    }
    struct node* onceki = temp ->prev;
    free(temp);
    onceki ->next = NULL;

}

//aradan eleman silme
void aradanSil(int veri){ //veri = silinecek deger
    struct node* temp = head;
    if(head==NULL){
        printf("Liste zaten bos!");
    }

    if (head->next == NULL){
        bastanSil();
        /*
        free(head);
        head = NULL;
        printf("Eleman kalmadi!");*/
        return;
    }

    while(temp->next!=NULL){
        if(temp->data == veri){
            break;
        }
        temp = temp->next;
    }
    struct node* sonraki = temp->next;
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next =sonraki;
    sonraki->prev = onceki;
}

// yazdirma fonksiyonu
void yazdir(){
    struct node* temp = head;
        while(temp != NULL){
            printf(" %d",temp->data);
            temp= temp->next;
        }

}
int main()
{
    int i, secim, sayi, sayi1;
    while(1) {

            printf("\n1-sona eleman ekleme\n");
            printf("\n2-basa eleman ekleme\n");
            printf("\n3-araya eleman ekleme\n");
            printf("\n4-bastaki elemani sil\n");
            printf("\n5-sondaki elemani sil\n");
            printf("\n6-aradaki elemani sil\n");
            printf("\n0-CIKIS\n");
            printf("\nSeciminizi giriniz: \n");
            scanf("%d",&secim);

            switch (secim){
            case 1:
                printf("\n Sona eklenecek elemani giriniz...->\n");
                scanf("%d",&sayi);
                sonaEkle(sayi);
                yazdir();
                break;

            case 2:
                printf("\n Basa eklenecek elemani giriniz...->");
                scanf("%d",&sayi);
                basaEkle(sayi);
                yazdir();
                break;

            case 3:
                printf("\n Araya eklenecek elemani giriniz...->");
                scanf("%d",&sayi);
                printf("\n Hangi elemanin onune eklemek istersiniz?...->");
                scanf("%d",&sayi1);
                arayaEkle(sayi1,sayi);
                yazdir();
                break;

            case 4:
                bastanSil();
                yazdir();
                break;
            case 5:
                sondanSil();
                yazdir();
                break;
            case 6:
                printf("\n Silinmesini istediginiz elemani giriniz...->");
                scanf("%d",&sayi);
                aradanSil(sayi);
                yazdir();
                break;

            case 0:
                printf("\n Cikmak icin 0'a basin...->");
                exit(0);


            }
    }
    return 0;
}
