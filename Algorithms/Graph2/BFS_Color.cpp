#include<bits\stdc++.h>

using namespace std;

vector<int> edge[100];

int prev[100],dist[100];
char color[100];
bool cycle;

void bfs()
{
	queue<int> que;
	memset(color,'w',sizeof(color));
	que.push(0);
	color[0]='g';
	dist[0]=0;
	prev[0]=-1;
	while(!que.empty()){
		int u=que.front();
		color[u]='B';
		que.pop();
		for(int v=0;v<edge[u].size();v++){
			if(color[edge[u].at(v)]=='w'){
				que.push(edge[u].at(v));
				dist[edge[u].at(v)]=dist[u]+1;
				color[edge[u].at(v)]='g';
				prev[edge[u].at(v)]=u;
			}
			else
				cycle=true;
		}
	}
}

void display(int var)
{
	for(int i=0;i<var;i++)
		cout<<i<<" - Distance from source: "<<dist[i]<<" Prev: "<<prev[i]<<endl;
	if(cycle)
		cout<<endl<<"Cycle exist";
	else
		cout<<endl<<"Cycle does not exist";
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
		edge[y].push_back(x);
	}
	bfs();
	display(var);
	return 0;
}
