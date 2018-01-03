#include<bits/stdc++.h>

using namespace std;

vector<int> edge[100];
vector<int> cost[100];

int prev[100],key[100];
bool cycle;

void bellmanford(int var)
{
    for(int i=0;i<var;i++)
		key[i]=INT_MAX;
	key[0]=0;
	prev[0]=-1;
	for(int i=0;i<var-1;i++){
        for(int u=0;u<var;u++){
            for(int v=0;v<edge[u].size();v++){
                if(key[u]+cost[u].at(v)<key[edge[u].at(v)]){
                    key[edge[u].at(v)]=key[u]+cost[u].at(v);
                    prev[edge[u].at(v)]=u;
                }
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
	bellmanford(var);
	display(var);
	cout<<endl<<cycle;
	cin>>var;
	return 0;
}
