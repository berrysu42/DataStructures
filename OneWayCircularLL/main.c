#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
struct node *prev=NULL;
struct node *tail;



void basaEkle(int sayi){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=sayi;
    if(head==NULL){
        head=new;
        head->next=head;

    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new;
        new->next=head;
        head=new;
    }
}


void sonaEkle(int sayi){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=sayi;
    if(head==NULL){
        head=new;
        new->next=head;



    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new;
        new->next=head;
    }
}
void arayaEkle(int sayi){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = sayi;

    // Eðer liste boþsa ya da yeni eleman baþa eklenmeli ise
    if (head == NULL || head->data >= sayi) {
        if (head == NULL) {
            new->next = new;
            head = new;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new;
            new->next = head;
            head = new;
        }
    }
    else {
        // Araya ekleme durumu
        temp = head;
        while (temp->next != head && temp->next->data < sayi) {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void bastanSilme(int sayi){
	struct node *index = (struct node*)malloc(sizeof(struct node));
	temp=head;
	tail = head;
	//new->data=sayi;
    	if(head==NULL){
        	printf("Link list is empty!");
		return 1;
    	}
	while(tail->next!= head){
		tail = tail->next;
	}
	if(head->next==head){

		free(head);
		head=NULL;
	}
	else{
		head=head->next;
		tail->next =head;
		free(temp);
	}



}

void sondanSilme(int sayi){
	struct node *index = (struct node*)malloc(sizeof(struct node));
	temp=head;
	prev = NULL;
	if(head==NULL){
		printf("LL is empty!");
		return;

	}
	if(head->next==head){

		free(head);
		head=NULL;
	}
	else{
		while(temp->next !=head){
			prev=temp;
			temp = temp->next;
		}
		prev->next =head;
		free(temp);
	}


}
void aradanSilme(int sayi){
	prev=head;
	temp = head->next;
	if(head==NULL){
		printf("LL is empty!");
		return ;

	}
	while(temp !=head){
		if(temp->data ==sayi){
			prev->next = temp->next;
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;

	}
	printf("Eleman bulunamadi!");

}
void listele(){
    if(head==NULL){
        printf("Link list is empty!\n");
    }
    else{
        temp=head;
        while(temp->next!=head){
            printf("%d - >",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }

}
int main()
{
    while(1){
    int secim,sayi;
    printf("\n1--> basa eleman ekle \n");
    printf("\n2--> sona eleman ekle \n");
    printf("\n3--> araya eleman ekle \n");
    printf("\n4--> bastan eleman silme \n");
    printf("\n5--> sondan eleman silme \n");
    printf("\n6--> aradan eleman silme \n");
    printf("\n7--> listele\n");
    printf("secim yapiniz: ");
    scanf("%d",&secim);
    switch(secim)
    {

        case 1: printf("basa eklenecek sayi: ");
        scanf("%d",&sayi);
        basaEkle(sayi);
        break;

        case 2: printf("sona eklenecek sayi: ");
        scanf("%d",&sayi);
        sonaEkle(sayi);
        break;

        case 3:
        printf("araya eklenecek sayi: ");
        scanf("%d",&sayi);
        arayaEkle(sayi);
        break;

        case 4:
        bastanSilme(sayi);
        break;

        case 5:
        sondanSilme(sayi);
        break;

        case 6:
        printf("araydan silinece sayi: ");
        scanf("%d",&sayi);
        aradanSilme(sayi);
        break;

        case 7: listele();
        break;
    }
}
return 0;

}
