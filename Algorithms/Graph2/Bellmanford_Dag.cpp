#include<bits/stdc++.h>

using namespace std;

vector<int> edge[100];
vector<int> cost[100];
vector<int> vartex;

int prev[100],key[100];
int d[100],f[100];
char color[100];
bool cycle;


void visit(int var,int u)
{
	color[u]='g';
	for(int v=0;v<edge[u].size();v++){
		if(color[edge[u].at(v)]=='w'){
			visit(var,edge[u].at(v));
		}
	}
	vartex.push_back(u);

	color[u]='B';
}

void dfs(int var)
{
	for(int i=0;i<var;i++){
		d[i]=INT_MAX;
		f[i]=INT_MAX;
	}
	memset(color,'w',sizeof(color));
	for(int u=0;u<var;u++){
		if(color[u]=='w')
			visit(var,u);
	}
}

void bellmanford(int var)
{
    for(int i=0;i<var;i++)
		key[i]=INT_MAX;
	key[0]=0;
	prev[0]=-1;
    for(int i=0; i<var; i++){
        int u=vartex.at(i);
        for(int v=0; v<edge[u].size(); v++){
            if(key[u]+cost[u].at(v)<key[edge[u].at(v)]){
                key[edge[u].at(v)]=key[u]+cost[u].at(v);
                prev[edge[u].at(v)]=u;
            }
        }
    }
	for(int u=0;u<var;u++){
            for(int v=0;v<edge[u].size();v++){
                if(key[u]+cost[u].at(v)<key[edge[u].at(v)])
                    cycle=true;
            }
	}
}

void display(int var)
{
	for(int i=0;i<var;i++)
		cout<<prev[i]<<" ";
	cout<<endl;
    for(int i=0; i<var; i++)
        cout<<key[i]<<" ";
}

int main()
{
	int edg,var;
	cout<<"Edge & Vartices"<<endl;
	cin>>edg>>var;
	for(int i=0;i<edg;i++){
		int x,y,c;
		cin>>x>>y>>c;
		edge[x].push_back(y);
		cost[x].push_back(c);
	}
	dfs(var);
	reverse(vartex.begin(),vartex.end());
	bellmanford(var);
	display(var);
	cout<<endl<<cycle;
	cin>>var;
	return 0;
}

