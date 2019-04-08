#include<bits\stdc++.h>

using namespace std;

vector<int> edge[100];

char color[100], rgb[3] = {'R','G','B'};
int edg, ver;
bool check(int v, char c){
    for(int i = 0; i < edge[v].size(); i++){
        int u = edge[v].at(i);
        if(color[u] == c) return false;
    }
    return true;
}
bool gcolor(int v)
{
    if(v == ver) return true;
    for(int i = 0; i < 3; i++){
        if(check(v,rgb[i])){
            color[v] = rgb[i];
            if(gcolor(v+1)) return true;
            else color[v] = -1;
        }
    }
    return false;
}

int main()
{
	cout<<"Edge & vertices"<<endl;
	cin>>edg>>ver;
	for(int i = 0; i < edg; i++){
		int x, y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(color,-1,sizeof(color));
	if(!gcolor(0)) cout<<"solution does not exist";
	else for(int i = 0; i < ver; i++) cout<<color[i]<<" ";
	return 0;
}
