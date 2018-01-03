#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct graph{
	int var1,var2;
	float weight;
};

struct graph edge[130000];
vector<int> result;
int p[510];
int findSet(int x)
{
	if(p[x]==x) return x;
	findSet(p[x]);
}
void unioun(int x,int y)
{
	int fx=findSet(x);
	int fy=findSet(y);
	p[fy]=fx;
}
void makeSet(int x)
{
	p[x]=x;
}
int cmpfunc (const void * a, const void * b)
{
	struct graph* a1 = (struct graph*)a;
    struct graph* b1 = (struct graph*)b;
    return a1->weight - b1->weight;
}
void Kruskal(int edg)
{
	qsort(edge,edg,sizeof(graph),cmpfunc);
	for(int i=0;i<edg;i++){
		if(findSet(edge[i].var1) != findSet(edge[i].var2)){
			result.push_back(i);
			unioun(edge[i].var1,edge[i].var2);
		}
	}
}
int main()
{
    pair<int,int> outpost[510];
    int t,s,p,edg;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>s>>p;
        edg=(p*(p-1))/2;
        for(int i=0;i<p;i++){
            cin>>outpost[i].first>>outpost[i].second;
             makeSet(i);
        }
        int cnt=0;
        for(int j=0;j<p;j++){
            for(int k=j+1;k<p;k++){
                if(j!=k){
                    edge[cnt].var1=j;
                    edge[cnt].var2=k;
                    float f1=(outpost[k].first-outpost[j].first)*(outpost[k].first-outpost[j].first);
                    float f2=(outpost[k].second-outpost[j].second)*(outpost[k].second-outpost[j].second);
                    edge[cnt].weight=sqrt(f1+f2);
                    cnt++;
                }
            }
        }
        Kruskal(edg);
        reverse(result.begin(),result.end());
        printf("%0.2f\n",edge[result.at(s-1)].weight);
    }
    return 0;
}
