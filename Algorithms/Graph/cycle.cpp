#include<iostream>
#include<climits>

using namespace std;

int d[1000];
int f[1000];
char color[1000];
int prev[1000];
int time=0;
int adj_mat[100][100];
int flg=-1,ff=0,fq;
void input(int no_of_vartex)
{
    int i, j;

    for (i = 0; i<no_of_vartex; i++)
    {
        for (j = 0; j<no_of_vartex; j++)
        {
            cin >> adj_mat[i][j];
        }
    }
}

int visit(int no_of_vartex,int u)
{
    color[u]='G';
    time+=1;
    d[u]=time;
    for(int v=0; v<no_of_vartex; v++)
    {
        if(adj_mat[u][v]!=0 && ff==0)
        {
            if(color[v]=='W' && ff==0)
            {
                prev[v]=u;
                visit(no_of_vartex,v);
            }
            else
            {
                prev[v]=u;
                flg=v;
                ff=-1;
                return v;
            }
        }
    }
    if(ff==0)
    {
        color[u]='B';
        time+=1;
        f[u]=time;
    }
    return -1;
}

int DFS(int no_of_vartex)
{
    int i,j,k;
    int u,v;

    for (i = 0; i < no_of_vartex; i++)
    {
        d[i]=INT_MAX;
        f[i]=INT_MAX;
        color[i]='W';
        prev[i]=-1;
    }

    for(u=0; u<no_of_vartex; u++)
    {
        if(color[u]=='W' && ff==0)
        {
            k=visit(no_of_vartex,u);
            if(k!=-1)
                return k;
        }


    }
    return -1;
}
void print_path(int a)
{
    if(prev[a]==flg)
    {
        cout<<prev[a]<<" ";
        return;
    }
    else
    {
        print_path(prev[a]);
        cout<<prev[a]<<" ";
    }
}
int main()
{
    int no_of_vartex;
    int i,j,k;
    char vartex[26];

    cin>>no_of_vartex;
    input(no_of_vartex);

    DFS(no_of_vartex);

    for(i=0; i<no_of_vartex; i++)
        cout<<prev[i]<<" ";

    cout<<endl;
    if(ff==0)
        cout<<"there is no cycle"<<endl;
    else
    {
        cout<<"there is a cycle"<<endl;
        print_path(flg);
    }

    return 0;
}
