#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *left,*right;
};

//yeni node oluşturma
struct node *newNode(int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data =data;
    new->left=NULL;
    new->right=NULL;
    return new;
};
int main()
{
    //root oluşturma
    struct node *root = newNode(10);
    root->left =newNode(20);
    root->right =newNode(30);
    root->left->left = newNode(40);
    root->left->right=newNode(50);
    root->right->left=newNode(60);
    root->right->right=newNode(70);

    printf("Root %d \n",root->data);
    printf("root->left (Left child) %d\n",root->left->data);
    printf("root->right(Right child) %d\n",root->right->data);
    printf("root->left->left %d\n",root->left->left->data);
    printf("root->left->right %d\n",root->left->right->data);
    printf("root->right->left %d\n",root->right->left->data);
    printf("root->right->right %d\n",root->right->right->data);


    return 0;
}
