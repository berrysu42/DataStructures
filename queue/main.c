#include <stdio.h>
#include <stdlib.h>

//queue FIFO yani ilk giren ilk cikar mantigina dayanir.
//Dogrusal veri yapisidir.
//hem array hem de link list yapisiyla uygulanabilir.
/*PIPE yapilarinda,disk yonetiminde I/O isteklerini planlamada
switch, router gibi network yapilarindaki veri pakaetlerinde
elektronik devrelerde yazilim ve donanim arasi buffer islemlerinde
kullanilir.*/

/*LL ile Quwuw yapisi gerceklestirilirken kuyrugun basini ve
sonunu gosteren isaretciler kullanilir.Kuyruga ekleme ve kuyruktan
eleman cikarma islemlerinde bu isaretciler guncellenir.*/

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL; //kuyrugun bas gostericisi
struct node *last=NULL; //kuyrugun son gostericisi

//eleman ekleme
int addqueue(int veri){
    //bos olup olmama kontrolu
    if(head==NULL){
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data =veri;
        new->next = NULL;
        head=last=new;
    }
    else{
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data =veri;
        new->next = NULL;

        last->next = new;
        last=new;
    }

}

int removeQueue(){

     if(head==NULL){
        printf("Kuyruk bos!");
        return 1;
    }
    struct node *temp = head;
    head=head->next;
    free(temp);


    if (head == NULL) {
        // Eðer kuyruk tamamen boþaldýysa, last'ý da güncelle
        last = NULL;
    }
}

int yazdir(){
    //travers
    struct node *temp=head;
    if(head==NULL){
        printf("Kuyruk bos!\n");
        return 1;
    }

    printf("QUEUE\n");
    while(temp!=NULL){
        printf("%d =>",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 1;

}

int main()
{
    int secim,sayi;
    while(1==1){
        printf("\n1-Kuyruga eleman ekleme...->");
        printf("\n2-Kuyruktan eleman silme...->");
        printf("\nSeciminizi giriniz...->");
        scanf("%d",&secim);

        switch(secim){
        case 1:
            printf("Eklemek istediginiz degeri giriniz...->");
            scanf("%d",&sayi);
            addqueue(sayi);
            yazdir();
            break;
        case 2:
            removeQueue();
            yazdir();
            break;
        }

    }

    return 0;
}
