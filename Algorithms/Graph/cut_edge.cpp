#include<iostream>

using namespace std;

char color[1000];
int prev[1000];
int adj_mat[100][100];
int r[1000];
int ad[1000];
int fq=0;

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

void visit(int no_of_vartex,int u)
{
    color[u]='G';
    for(int v=0;v<no_of_vartex;v++)
    {
        if(adj_mat[u][v]!=0)
        {
            if(color[v]=='W')
            {
                prev[v]=u;
                visit(no_of_vartex,v);
            }
        }
    }

    color[u]='B';
}

void DFS(int no_of_vartex)
{
    int i,j,k;
    int u,v;

    for (i = 0; i < no_of_vartex; i++)
	{
	    color[i]='W';
	    prev[i]=-1;
	}
	u=0;
    visit(no_of_vartex,u);
}

int check(int no_of_vartex)
{
    for(int i=1;i<no_of_vartex;i++)
    {
        if(prev[i]==-1)
            return 1;
    }
    return 0;
}

int main()
{
    int no_of_vartex;
    int i,j,k;
    char vartex[26];

    cin>>no_of_vartex;
    input(no_of_vartex);

    DFS(no_of_vartex);

    for(i=0;i<no_of_vartex;i++)
    {
        for(j=0;j<no_of_vartex;j++)
        {
            if(adj_mat[i][j]!=0)
            {
                k=adj_mat[i][j];
                adj_mat[i][j]=0;
                DFS(no_of_vartex);

                if(check(no_of_vartex)==1)
                {
                    r[fq]=i;
                    ad[fq]=j;
                    fq++;
                }

                adj_mat[i][j]=k;
            }
        }
    }

   if(fq==0)
        cout<<"There is no cut edge";
   else
        for(i=0;i<fq;i++)
            cout<<r[i]<<"-"<<ad[i]<<endl;
    return 0;
}

