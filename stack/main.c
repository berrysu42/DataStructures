#include <stdio.h>
#include <stdlib.h>

//Stack LÝFO(son giren ilk cikar mantigina dayanir.)
// stack icin 3  islem soz konusudur.
//1.Push (ctrl+c gibi dusunebiliriz.)
//2.Pop (Ctrl+z gibi dusunebiliriz.)
//3.Peek (ctrl+v gibi dusunebiliriz)


    //Dizilerde
// Push: En ustte elemen ekler. Top indisi 1 artar.
// Pop: Top indisini 1 azaltmak yeterlidir.
//Peek: Herhangi bir ekleme yapmaz. Top elemanini dondurur.

//Asil stack bizi link Liste'de karsilar. Burda sona degil de basa eleman ekliomus gibi dusunebiliriz.
/* 1.adim 15 ekleme: NULL<- 15
 *2.adim 25 ekeleme: NULL<- 15<- 25
 *3. adim 35 ekleme: NULL<- 15<- 35 gibi*/

  //LL olusturacagimiz icin her dugumu tutan bir struct olusturmliyiz.
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

//top elemanini tutan bir tane dugum olusturulmali
struct node *top = NULL;

//ekleme fonksiyonu
void push(int veri){
    //her ekleme sirasinda yeni bir node olusturmamiz gerekiyor.
    struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
    eklenecek->data = veri;
    eklenecek->next = NULL;

    if(top != NULL)
        eklenecek->next = top;
    top = eklenecek;
}

//silme fonksiyonu. En ustteki degeri silecegi icin parametre atanmaz!
void pop(){
     if(top==NULL){
        printf("Stack bos!");
    }
    else{
        struct node* temp;
        temp = top;
        top= top->next;
        free(temp);
    }
}

//top elemaninin degerini dondurme
int peek(){
    return top->data;

}


//yazdirma islemi
void yazdir(){
    //travers islemi
    struct node* travers;
    travers = top;
    printf("\n");
    printf("NULL<=");
    while(travers!=NULL){
        printf("%d <=",travers->data);
        travers = travers->next;
    }

}
int main()
{
    int secim,sayi;
    while(1==1){
        printf("\n1- Push\n");
        printf("\n2- Pop\n");
        printf("\n3- Peek\n");
        printf("\n1- Yapmak istediginiz islemi secin->\n");
        scanf("%d",&secim);

        switch(secim){
        case 1:
            printf("\nGirmek istediginiz deger?..->");
            scanf("%d",&sayi);
            push(sayi);
            yazdir();
            break;
        case 2:
            pop();
            yazdir();
            break;
        case 3:
            printf("top elemani ->%d", peek());
            break;
        }
   }
    return 0;
}
