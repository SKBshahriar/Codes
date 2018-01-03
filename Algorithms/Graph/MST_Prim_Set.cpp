#include<iostream>
#include<queue>
#include<climits>
#include<set>

using namespace std;

set< pair<int,int> > myPQ;

int T[1000];
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
void prim(int no_of_vartex)
{
    int i,j,k,v;

    for(i=0;i<no_of_vartex;i++)
    {
        T[i]=0;
        Key[i]=INT_MAX;
    }

    T[0]=1;
    Key[0]=0;
    Parent[0]=-1;
    int u=0;

    for(j=0; j<no_of_vartex-1; j++)
    {
        for(i=0; i<no_of_vartex; i++)
        {
            if(adj_mat[u][i]!=0 && T[i]==0)
            {
                if(adj_mat[u][i]<Key[i])
                {
                    Parent[i]=u;
                    Key[i]=adj_mat[u][i];
                    myPQ.insert(pair<int,int> (adj_mat[u][i],i));
                }
            }
        }

        u=(*myPQ.begin()).second;
        while(T[u]!=0)
        {
            if(T[u]!=0)
                myPQ.erase(myPQ.begin());
            u=(*myPQ.begin()).second;
        }

        T[u]=1;
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
    prim(no_of_vartex);

     for(i=0;i<no_of_vartex;i++)
        count+=Key[i];
    cout<<endl;

    for(i=0;i<no_of_vartex;i++)
    {
        if(Parent[i]!=-1)
            cout<<vartex[Parent[i]]<<"-"<<vartex[i]<<" "<<Key[i]<<" "<<endl;
        else
            cout<<"N-"<<vartex[i]<<" "<<Key[i]<<endl;
    }
      cout<<"MST : "<<count;

  return 0;
}
