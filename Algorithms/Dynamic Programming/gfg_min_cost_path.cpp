#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>
using namespace std;
int cost[100][100];
int mcp(int m,int n)
{

    if(m<0 || n<0)
    {
        return 10000;
    }
    else if(m==0 && n==0)
        return cost[m][n];
    else
    {
        int min=mcp(m-1,n-1)+cost[m][n];
        int temp=mcp(m,n-1)+cost[m][n];
        if(temp<min)
            min=temp;
        int temp2=mcp(m-1,n)+cost[m][n];
        if(temp2<min)
            min=temp2;
        return min;
    }
}
int main()
{
    int row,col;
    cin>>row>>col;
    srand(time(NULL));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cost[i][j]=rand()%50+1;
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<mcp(row-1,col-1);
    return 0;
}
