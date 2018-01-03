#include<iostream>
#include<climits>

using namespace std;

int Key[1000];
int Parent[1000];
int adj_mat[100][100];
bool cycle=false;

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

void BLMF(int no_of_vartex)
{
    int i,j,k;
    int u,v;
    for(i=0;i<no_of_vartex;i++)
    {
        Key[i]=INT_MAX;
    }

    Key[0]=0;
    Parent[0]=-1;
    for(i=0;i<no_of_vartex-1;i++)
    {
        for(u=0; u<no_of_vartex; u++)
        {
            for(v=0; v<no_of_vartex; v++)
            {
                if(adj_mat[u][v]!=0)
                {
                    if(adj_mat[u][v]+Key[u]<Key[v])
                    {
                        Parent[v]=u;
                        Key[v]=adj_mat[u][v]+Key[u];
                    }
                }
            }
        }
    }
    for(u=0; u<no_of_vartex; u++)
    {
        for(v=0; v<no_of_vartex; v++)
        {
            if(adj_mat[u][v]!=0)
            {
                if(adj_mat[u][v]+Key[u]<Key[v])
                cycle=true;
            }
        }
    }
}

int main()
{
    char vartex[100];
    int no_of_vartex;
    int i,j,k,count=0;

    cout<<"Number of vertices : ";
    cin>>no_of_vartex;
    cout<<"Enter The Graph"<<endl;
    input(no_of_vartex);

    BLMF(no_of_vartex);

    for(i=0; i<no_of_vartex; i++)
    {
        if(Parent[i]!=-1)
            cout<<Parent[i]<<" ";
        else
            cout<<"N ";
    }
    cout<<endl;
    for(i=0; i<no_of_vartex; i++)
        cout<<Key[i]<<" ";
    if(cycle==true)
        cout<<endl<<"There is negative cycle in the graph";
    else
        cout<<endl<<"There is no negative cycle in the graph";
    return 0;
}

