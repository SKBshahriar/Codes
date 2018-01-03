#include<bits/stdc++.h>
using namespace std;
long a[1000];
int r=0;
void ShiftUp(int x)
{
    if(x==1) return;
    int  par,large;
    par=x/2;
    large=par;
    if (a[x] > a[large]) large = x;
    if (large == par) return;
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
    if (left <= r && a[left] > a[large]) large = left;
    if (right <= r && a[right] > a[large]) large = right;
    if (large == index) return;
    else{
        swap(a[large], a[index]);
        ShiftDown(large);
    }
}
void insert(int x)
{
    if(r+1<SIZE){
        r++;
        a[r]=x;
        ShiftUp(r);
    }
    else printf("Queue Overflow\n");
}
void update(int value,int pos)
{
    if(a[pos]>=value){
        a[pos]=value;
        ShiftUp(pos);
    }
    else{
        a[pos]=value;
        ShiftDown(pos);
    }
}
int delete_top()
{
    if(r>0){
        int x=a[1];
        a[1]=a[r];
        r--;
        ShiftDown(1);
        return x;
    }
    else printf("Queue Underflow\n");
}
int main()
{
    int a,b,i;
    while(1){
        printf("1.Insert\n2.Delete\n3.Update\n4.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d",&a);
        if(a==1){
            printf("Enter Data : ");
            scanf("%d",&b);
            insert(b);
        }
        else if(a==2) delete_top();
        else if(a==3){
             printf("\nEnter Value and Position\n");
             int value,pos;
             scanf("%d%d",&value,&pos);
             update(value,pos);
        }
        else break;
    }
    while(r>=1) printf("%d ",delete_top());
}
