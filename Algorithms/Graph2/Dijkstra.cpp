#include<bits\stdc++.h>

using namespace std;

int prev[100],key[100];

vector<int> edge[100];
vector<int> cost[100];

priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

void dijkstra(int var)
{
	for(int i=0;i<var;i++)
		key[i]=INT_MAX;
	key[0]=0;
	prev[0]=-1;
	que.push(pair<int, int>(0,key[0]));
	while(!que.empty()){
		int u=que.top().second;
		que.pop();
		for(int v=0;v<edge[u].size();v++){
			if(key[u]+cost[u].at(v)<key[edge[u].at(v)]){
				key[edge[u].at(v)]=key[u]+cost[u].at(v);
				prev[edge[u].at(v)]=u;
				que.push(pair<int,int>(key[edge[u].at(v)],edge[u].at(v)));              //
			}
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
	dijkstra(var);
	display(var);
	return 0;
}

