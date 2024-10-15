#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;

};
struct node *head=NULL;
struct node *tail=NULL;


int addNode(int data){ //birden fazla eleman varsa ve sona eklme yapiyorsak
    if (head==NULL){ //LL bos olup olmadigini kontrol ettik
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;

        head=tail=new;
        }
    else{
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;

        tail->next=new;

        tail=new;

    }

}

//LL'in basina eleman ekleme (Add to head)
int addNodeHead(int data){
    if(head==NULL){ //LL bos olup olmadigini kontrol ettik(LL ist empty)
        struct node *new =(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;

        head=tail=new;
    }
    else{
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data=data;
        //new->next=NULL;

        new->next=head; //bu ifade geldigi icin artýk new->next=NULL olmaz.
        head=new;

    }

}

//Delete LL
int Delete(int data){
    //prev index tanimlamalarini yapmam lazim
    struct node *prev =NULL;
    struct node *index =head;

    //LL is empty
    if (head==NULL){
        printf("LL is empty!");
        return 1;
    }

    //head silinecekse
    if(head->data==data){ //head'de isaret edilen data ile siilinecek data ayni ise
        // silme isleminden sonra alani temizlemek icin yeni bir degisken atamak lazım
        struct node *temp = head;
        head = head->next; //head'i bir sonraki veriye guncelledik.
        free(temp);
        return 1;
    }
    //aranan elemani silme
    while(index!=NULL && index->data!=data){
            prev=index; // index 'i prev e atayarak free islemini prev uzerinden gerceklestirecegim.
            index = index->next;// index arık silinen elemandan sonrki elemana ulasacak.

    }
    if(index==NULL){
        printf("Data not found!\n");
        return 1;
    }
    prev->next=index->next;
    //tail silinecekse
    if(tail->data ==data){
            tail=prev;
    }
    free(index);

    //silinecek eleman yoksa


    return 1;
}

int LLprint(){
    printf("*********Link List******\n");
    struct node *index = head;
    while(index!=NULL){
        printf("%d -\n",index->data);
        index=index->next;
    }
    return 1;
}
int main()
{



    addNode(10);
    addNode(14);
    addNode(16);
    addNodeHead(30);
    addNode(19);

    addNode(5);
    addNodeHead(40);


    Delete(40);
    Delete(5);
    Delete(16);

    LLprint();

    Delete(54);



    return 0;
}
