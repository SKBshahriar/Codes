#include<bits\stdc++.h>

using namespace std;

vector<int> edge[100];

int prev[100],d[100],f[100],t=0;
char color[100];

void visit(int var,int u)
{
	color[u]='g';
	t++;
	d[u]=t;
	for(int v=0;v<edge[u].size();v++){
		if(color[edge[u].at(v)]=='w'){
			prev[edge[u].at(v)]=u;
			visit(var,edge[u].at(v));
		}
	}
	color[u]='B';
    t++;
    f[u]=t;
}

void dfs(int var)
{
	for(int i=0;i<var;i++){
		d[i]=INT_MAX;
		f[i]=INT_MAX;
	}
	memset(prev,-1,sizeof(prev));
	memset(color,'w',sizeof(color));
	for(int u=0;u<var;u++){
		if(color[u]=='w')
			visit(var,u);
	}
}

void display(int var)
{
	cout<<"Nodes:   ";
	for(int i=0;i<var;i++)
		cout<<i<<"  ";
	cout<<endl<<"Prev:   ";
	for(int i=0;i<var;i++)
		cout<<prev[i]<<"  ";
	cout<<endl<<"Start:   ";
	for(int i=0;i<var;i++)
		cout<<d[i]<<"  ";
	cout<<endl<<"Finish: ";
	for(int i=0;i<var;i++)
		cout<<f[i]<<"  ";
}

int main()
{
	int edg,var;
	cout<<"Edge & Vartices"<<endl;
	cin>>edg>>var;
	for(int i=0;i<edg;i++){
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
	}
	dfs(var);
	display(var);
	return 0;
}
