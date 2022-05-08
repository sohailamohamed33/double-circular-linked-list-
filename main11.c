#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data;
    struct node*next;
    struct node*prev;
}node;
typedef struct
{
    node*head;
    node*tail;
}linkedlist;
node *newnode(int x)
{
    node*n=malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    n->prev=NULL;
    return n;
}
linkedlist *initialize ()
{
    linkedlist *l=malloc(sizeof(linkedlist));
    l->head=NULL;
    l->tail=NULL;
    return l;
}
int isempty (linkedlist *l)
{
    if(l->head==NULL)
        return 1;
    else
        return 0;
}
void insertstart (linkedlist *l,int x)
{
    node *n=newnode(x);
    if (l->head==NULL)
    {
        n->next=n;
        n->prev=n;
        l->head=n;
        l->tail=n;
    }
    else
    {
        l->tail->next=n;
        n->prev=l->tail;
        n->next=l->head;
        l->head=n;
    }
}
void insertend(linkedlist *l,int x)
{
    node*n=newnode(x);
    if (l->head==NULL)
    {
        n->next=n;
        n->prev=n;
        l->head=n;
        l->tail=n;
    }
    else
    {
        l->tail->next=n;
        n->prev=l->tail;
        n->next=l->head;
        l->head->prev=n;
        l->tail=n;
    }

}
void deletestart (linkedlist *l)
{
    if (l->head==NULL)
        return ;
    else if (l->head->next==l->head)
    {
        free(l->head);
        l->head=NULL;
        l->tail=NULL;
    }
    else
    {
        node*temp=l->head;
        l->head=l->head->next;
        free(temp);
        l->tail->next=l->head;
        l->head->prev=l->tail;
    }
}
//void deleteend (linkedlist *l)
//{
    //if (l->head==NULL)
        //return ;
    //else if (l->head->next=l->head)
    //{
        //free(l->head);
       // l->head=NULL;
       // l->tail=NULL;
   // }
   // else
    //{
       // node *temp=l->tail;
       // node*prev=NULL;
        //while (temp->next!=NULL)
        //{
           // prev=temp;
            //temp=temp->next;
        //}

    //}
//}
void display (linkedlist*l)
{
    if(l->head==NULL)
        return ;
    node *temp=l->head;
    while(temp->next !=l->head)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
int main()
{
    linkedlist *l=initialize();
    insertstart(l,8);
    insertstart(l,7);
    insertstart(l,3);
    insertend(l,0);
    insertend(l,1);
    display(l);
    deletestart(l);
    printf("\n");
    display(l);
    return 0;
}
