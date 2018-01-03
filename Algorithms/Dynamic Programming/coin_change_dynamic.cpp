#include<iostream>
using namespace std;
int v[2000],s[2000];
/*int cc(int n)
{
    int min;
    if(n==0)
        return 0;
    else
    {
        min=1+cc(n-1);
        if(n>=10)
        {
            int temp=1+cc(n-10);
            if(temp<min)
            {
                min=temp;
                s[n]=min;
            }
        }
        if(n>=25)
        {
            int temp=1+cc(n-25);
            if(temp<min)
            {
                min=temp;
                s[n]=min;
            }
        }
        if(n>=50)
        {
            int temp=1+cc(n-50);
            if(temp<min)
            {
                min=temp;
                s[n]=min;
            }
        }
        return min;
    }
}*/
int mcc(int n)
{
    int min;
    if(v[n]!=-1)
        return v[n];
    else
    {
        min=1+mcc(n-1);
        s[n] = 1;
        if(n>=10)
        {
            int temp=1+mcc(n-10);
            if(temp<min)
            {
                min=temp;
                s[n]=10;
            }
        }
        if(n>=25)
        {
            int temp=1+mcc(n-25);
             if(temp<min)
            {
                min=temp;
                s[n]=25;
            }
        }
        if(n>=50)
        {
            int temp=1+mcc(n-50);
            if(temp<min)
            {
                min=temp;
                s[n]=50;
            }
        }
        v[n]= min;
        return v[n];
    }
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
    int amount,i;
    cin>>amount;
    for(i=0; i<2000; i++)
        v[i]=-1;
    for(i=0; i<1000; i++)
        s[i]=-1;
    v[0]=0;
    cout<<mcc(amount)<<endl;
    display(amount);
    return 0;
}
