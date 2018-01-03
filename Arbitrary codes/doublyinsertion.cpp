#include<stdio.h>
struct list
{
    int data;
    struct list *back;
    struct list *next;
};
typedef struct list node;
void display(node *start)
{
    node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    node *start,*temp,*prev,*temp1,*temp2;
    int i,j,ch,item;
    start=NULL;
    do
    {
        printf("Do You Want To Create A Node? ");
        scanf("%d",&ch);
        if(ch==1)
        {
            if(start==NULL)
            {
                start=new node();
                start->next=NULL;
                start->back=NULL;
                printf("Enter Data For Node : ");
                scanf("%d",&start->data);
                prev=start;
            }
            else
            {
                temp=new node();
                printf("Enter Data For Node : ");
                scanf("%d",&temp->data);
                prev->next=temp;
                temp->back=prev;
                prev=temp;
            }
        }
    }
    while(ch==1);
    display(start);
    printf("\nenter item :");
    scanf("%d",&item);
    temp=start;
    while(temp!=NULL && temp->data<=item)
        temp=temp->next;
    temp1=new node();
    temp1->data=item;
    if(temp!=NULL)
    {
        temp1->back=temp->back;
        temp1->next=temp;
        temp->back=temp1;
        if(temp!=start)
            temp->back->next=temp1;
        else
            start=temp1;
    }
    else
    {
        temp2=start;
        while(temp2->next!=NULL)
            temp2=temp2->next;
        temp1->next=NULL;
        temp2->next=temp1;
        temp1->back=temp2;
    }
    display(start);
    return 0;
}

