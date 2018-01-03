#include<iostream>
#include<queue>
#include<climits>
#include<set>

using namespace std;

set< pair<int,int> > myPQ;

int Key[1000];
int Parent[1000];
int adj_mat[100][100];

void input(int no_of_vartex)
{
    int i,j;

    for(i=0;i<no_of_vartex;i++)
    {
        for(j=0;j<no_of_vartex;j++)
        {
            cin>>adj_mat[i][j];
        }
    }
}
void DJK(int no_of_vartex)
{
    int i,j,k,v;

    for(i=0;i<no_of_vartex;i++)
    {
        Key[i]=INT_MAX;
    }

    Key[0]=0;
    Parent[0]=-1;
    int u=0;
    myPQ.insert(pair<int,int>(0,0));
    while(!myPQ.empty())
    {
        for(i=0; i<no_of_vartex; i++)
        {
            if(adj_mat[u][i]!=0)
            {
                if(adj_mat[u][i]+Key[u]<Key[i])
                {
                    Parent[i]=u;
                    Key[i]=adj_mat[u][i]+Key[u];
                    myPQ.insert(pair<int,int> (adj_mat[u][i],i));
                }
            }
        }

        u=(*myPQ.begin()).second;
        myPQ.erase(myPQ.begin());
    }
}
int main()
{
    char vartex[100];
    int no_of_vartex;
    int i,j,k,count=0;

    cout<<"Number of vertices : ";
    cin>>no_of_vartex;

    for(i=0;i<100;i++)
        vartex[i]=65+i;

    cout<<"Enter The Graph"<<endl;

    input(no_of_vartex);

    DJK(no_of_vartex);

    for(i=0;i<no_of_vartex;i++)
    {
        if(Parent[i]!=-1)
            cout<<Parent[i]<<" ";
        else
            cout<<"N ";
    }
     cout<<endl;
    for(i=0; i<no_of_vartex; i++)
        cout<<Key[i]<<" ";

  return 0;
}
