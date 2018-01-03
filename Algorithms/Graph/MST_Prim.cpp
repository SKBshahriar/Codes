#include<iostream>
#include<queue>
#include<climits>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

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
int minimum(int no_of_vartex)
{
    int index,i;
    int max=INT_MAX;
    for(i=0;i<no_of_vartex;i++)
    {
        if(max>Key[i] && T[i]==0)
        {
            max=Key[i];
            index=i;
        }
    }
    return index;
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
                }
            }
        }
        u=minimum(no_of_vartex);
        T[u]=1;
    }
}
int main()
{
    char vartex[100];
    int no_of_vartex;
    int i,j,k;

    cin>>no_of_vartex;

    for(i=0;i<100;i++)
        vartex[i]=65+i;

    input(no_of_vartex);
    prim(no_of_vartex);
    cout<<endl;
    for(i=0;i<no_of_vartex;i++)
    {
        if(Parent[i]!=-1)
            cout<<vartex[Parent[i]]<<"-"<<vartex[i]<<" "<<Key[i]<<" "<<endl;
        else
            cout<<"N-"<<vartex[i]<<" "<<Key[i]<<endl;
    }
    // cout<<endl;
     //for(i=0;i<no_of_vartex;i++)

  return 0;
}
