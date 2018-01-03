#include<stdio.h>
struct list{
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
    node *start,*temp,*prev;
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
    }while(ch==1);
    display(start);
    printf("\nenter item :");
    scanf("%d",&item);
    temp=start;
    while(temp!=NULL && temp->data!=item)
        temp=temp->next;
    if(temp==NULL)
        printf("\nnot found");
    else
    {
        if(temp!=start)
            temp->back->next=temp->next;
        else
            start=temp->next;
        if(temp->next!=NULL)
            temp->next->back=temp->back;
    }
    printf("\n");
    display(start);
    return 0;
}
