#include<stdio.h>
#include<algorithm>
#define SIZE 10
using namespace std;
long a[1000];
int r=0;
void ShiftUp(int x)
{
    if(x==1)
        return;
    int  par,large;
    par=x/2;
    large=par;
    if (a[x] > a[large])
        large = x;
    if (large == par)
        return;
    else
    {
        swap(a[large], a[par]);
        ShiftUp(par);
    }
}
void ShiftDown(int index)
{
    int left, right, large;
    left = index * 2;
    right = (index * 2) + 1;
    large = index;
    if (left <= r && a[left] > a[large])
        large = left;
    if (right <= r && a[right] > a[large])
        large = right;
    if (large == index)
        return;
    else
    {
        swap(a[large], a[index]);
        ShiftDown(large);
    }
}
void enque(int x)
{
    if(r+1<SIZE)
    {
        r++;
        a[r]=x;
        ShiftUp(r);
    }
    else
        printf("Queue Overflow\n");
}
int dequeue()
{
    if(r>0)
    {
        int x=a[1];
        a[1]=a[r];
        r--;
        ShiftDown(1);
        return x;
    }
    else
        printf("Queue Underflow\n");
}
int main()
{
    int a,b,i;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&a);
        if(a==1)
        {
            printf("Enter Data : ");
            scanf("%d",&b);
            enque(b);
        }
        else if(a==2)
            dequeue();
        /*else if(a==3)
        {
            display(1);
            printf("\n");
        }*/
        else
            break;
    }
    while(r>=1)
    {
        printf("%d ",dequeue());
    }
}
