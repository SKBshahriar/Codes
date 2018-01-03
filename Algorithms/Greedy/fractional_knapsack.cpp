#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int price[100],weight[100],unite_price[100];
    int W=25,i,j,profit=0,k;

    weight[0]=1;weight[1]=2;weight[2]=5;weight[3]=7;weight[4]=8;weight[5]=10;
    price[0]=15;price[1]=32;price[2]=100;price[3]=133;price[4]=144;price[5]=170;

    for(i=0;i<6;i++){
        unite_price[i]=price[i]/weight[i];
    }

    for(i=1;i<6;i++){
        for(j=0;j<6-i;j++){
            if(unite_price[j]<unite_price[j+1]){
                swap(unite_price[j],unite_price[j+1]);
                swap(price[j],price[j+1]);
                swap(weight[j],weight[j+1]);
            }
        }
    }

    i=0;

    while(i<6 && W>0)
    {
        if(weight[i]<=W)
        {
            W=W-weight[i];
            profit=profit+price[i];
        }
        else
        {
            profit=profit+(unite_price[i]*W);
            W=0;
        }
        i++;
    }

    cout<<profit<<endl<<endl;

    return 0;
}
