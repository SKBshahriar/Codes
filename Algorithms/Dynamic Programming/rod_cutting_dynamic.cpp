#include<iostream>
using namespace std;
int unite_price[100], s[1000];
int rod_cutting(int n)
{
    if(n==0)
        return 0;
    int max=1+rod_cutting(n-1);
    s[n]=1;
    for(int i=1;i<=n;i++)
    {
        if(i<=n)
        {
             int temp=unite_price[i]+rod_cutting(n-i);
             if(temp>max)
             {
                max=temp;
                s[n]=i;
             }
        }
    }
    return max;
}
void display(int n)
{
    int i=n;
    while(i>0)
    {
        cout<<s[i]<<" ";
        i=i-s[i];
    }
}
int main()
{
    int size,i,price;
    /*for(i=1;i<=10;i++)
    {
        cout<<"Enter Price For Length : "<<i<<endl;
        cin>>unite_price[i];
    }*/
    unite_price[1]=1;unite_price[2]=5;unite_price[3]=8;
    unite_price[4]=9;unite_price[5]=13;unite_price[6]=17;
    unite_price[7]=17;unite_price[8]=20;unite_price[9]=24;
    unite_price[10]=30;
    cout<<"Enter The Size Of The Rod : ";
    cin>>size;
    price=rod_cutting(size);
    cout<<price<<endl;
    display(size);
    return 0;
}
