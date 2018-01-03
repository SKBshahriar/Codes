#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    int i,j;
    for(i=1; i<=a || i<=b; ++i)
    {
        if(a%i==0 && b%i==0)
            j=i;
    }
    return (a*b)/j;
}
int main()
{
    int j;
    float fraction,i=2,x,y,a,b,c;
    cin>>x>>y;
    c=x/y;
    while(c>0)
    {
        j=gcd(y,i);
        a=(j/y)*x;
        b=(j/i)*1;
        if(a>=b)
        {
            x=a-b;
            y=j;
            cout<<1<<"/"<<i<<"  ";
            i++;
            c=x/y;
        }
        else
            i++;
    }
}
