#include<stdio.h>
#define size 5
int stack[size],top=-1;
void push (int item)
{
    if(top+1==size)
    {
        printf("\nStack Overflow\n\n");
        return ;
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow\n\n");
        return;
    }
    else
    {
        stack[top]=0;
        top--;
        printf("\npop done\n\n");
    }
}
void showmenu()
{
    printf("1.push\n2.pop\n");
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
}
int main()
{
    int ch,item,i=1;
    do
    {
        showmenu();
        printf("Enter Choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter Item : ");
            scanf("%d",&item);
            push(item);
        }
        else if(ch==2)
        {
            pop();
        }
        else
            i=0;
    }while(i==1);
    display();
    return 0;
}

