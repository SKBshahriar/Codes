#include<stdio.h>
struct list
{
    int data;
    struct list *next;
    struct list *back;
};
typedef struct list node;
void showmenu()
{
    printf("\n1.Insertion\n2.Deletion\n3.Exit\n");
}
node *insertion(node *start,int item)
{
    node *temp,*temp1;
    if(start==NULL)
    {
        start=new node();
        start->data=item;
        start->next=NULL;
        start->back=NULL;
    }
    else if(item<start->data)
    {'+
        temp =new node();
        temp->next=start;
        start->back=temp;
        temp->data=item;
        start=temp;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL && item>=temp->next->data)
            temp=temp->next;
        temp1=new node();
        temp1->data=item;
        temp1->next=temp->next;
        temp1->back=temp;
        if(temp->next!=NULL)
            temp->next->back=temp1;
        temp->next=temp1;
    }
    return start;
}
node *deletion(node *start,int item)
{
    node *temp,*temp1;
    if(start!=NULL)
    {
        if(start->data==item)
        {
            temp=start;
            start=start->next;
            if(start!=NULL)
                start->back=NULL;
            delete temp;
        }
        else
        {
            temp=start;
            while(temp->next!=NULL && temp->next->data!=item)
                temp=temp->next;
            if(temp->next==NULL)
                printf("Nothing To Delete\n");
            else
            {
                temp1=temp->next;
                temp->next=temp1->next;
                if(temp1->next!=NULL)
                    temp1->next->back=temp;
                delete temp1;
            }
        }
    }
    return start;
}
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
void displayrev(node *start)
{
    node *temp;
    temp=start;
    if(temp!=NULL)
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->back;
        }
    }
}
void dis(node *start)
{
    if(start==NULL)
        return;
    dis(start->next);
    printf("%d ",start->data);
}
int main()
{
    node *start,*temp;
    int choice,i=0,item;
    start=NULL;
    do
    {
        showmenu();
        printf("Enter Choice : ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter Item To Insert: ");
            scanf("%d",&item);
            start=insertion(start,item);
            display(start);
            printf("\n");
            temp=start;
            dis(temp);
            //printf("\n");
            //displayrev(start);
        }
        else if(choice==2)
        {
            printf("Enter Item To Delete : ");
            scanf("%d",&item);
            start=deletion(start,item);
            display(start);
        }
        else
            i=1;
    }while(i==0);
    return 0;
}
