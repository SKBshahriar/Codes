#include<bits/stdc++.h>
#define inf 9999

using namespace std;

int adj_mat[100][100];
int d[100][100];
int p[100][100];

void input(int no_of_vertex)
{
	int i, j;
	for (i = 0; i<no_of_vertex; i++){
		for (j = 0; j<no_of_vertex; j++){
			cin >> adj_mat[i][j];
		}
	}
}
void Warshall(int no_of_vertex)
{
    int i,j,k;
    for(i=0; i<no_of_vertex; i++){
        for(j=0; j<no_of_vertex; j++){
            if(adj_mat[i][j]==0 && i!=j) d[i][j]=inf;
            else d[i][j]=adj_mat[i][j];
        }
    }
    for(i=0; i<no_of_vertex; i++){
        for(j=0; j<no_of_vertex; j++){
            if(i==j) p[i][j]=-1;
            else if(d[i][j]==inf)  p[i][j]=-1;
            else p[i][j]=j;
        }
    }
    for(k=0;k<no_of_vertex;k++){
        for(j=0;j<no_of_vertex;j++){
            for(i=0;i<no_of_vertex;i++){
                if(d[i][j]>(d[i][k]+d[k][j])){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[i][k];
                }
            }
        }
    }
}
void print_path(int u,int v)
{
    if(p[u][v]==-1){
        cout<<" No Path";
        return;
    }
    if(p[u][v]==v){
        cout<<v<<" ";
        return;
    }
    else{
         print_path(u,p[u][v]);
         print_path((p[u][v]),v);
    }
}
int main()
{
    int no_of_vertex;
    int u,v;

	cout << "Number of vartex : ";
	cin >> no_of_vertex;
	cout << "Enter The Graph"<<endl;
	input(no_of_vertex);
	Warshall(no_of_vertex);

	for(int i=0;i<no_of_vertex;i++){
        for(int j=0;j<no_of_vertex;j++){
            if(d[i][j]>=inf) cout<<"N\t";
            else cout<<d[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    cout<<endl<<"Enter path"<<endl;
    cin>>u>>v;
    cout<<u<<" ";
    print_path(u,v);
    return 0;
}
