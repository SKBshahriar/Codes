#include<bits\stdc++.h>

using namespace std;

int key[100],parent[100],t[100];

vector<int> edge[100];
vector<int> cost[100];

priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

void prims(int u,int count,int var)
{
	if(count==var) return;
	for(int v=0;v<edge[u].size();v++){
		if(key[edge[u].at(v)]>cost[u].at(v) && t[edge[u].at(v)]==0){
			key[edge[u].at(v)]=cost[u].at(v);
			parent[edge[u].at(v)]=u;
			que.push(pair<int,int> (cost[u].at(v),edge[u].at(v)));
		}
	}
	u=que.top().second;
	while(t[u]!=0){
        que.pop();
        u=que.top().second;
	}
	que.pop();
	t[u]=1;
	prims(u,++count,var);
}


void display(int v)
{
	for(int i=1;i<v;i++){
		cout<<parent[i]<<" -> "<<i<<" "<<key[i]<<endl;
	}
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
		edge[y].push_back(x);
		cost[x].push_back(c);
		cost[y].push_back(c);
	}
	for(int i=0;i<var;i++)
		key[i]=INT_MAX;

	parent[0]=-1;
	t[0]=1;
	prims(0,1,var);
	key[0]=0;
	display(var);

	return 0;

}
