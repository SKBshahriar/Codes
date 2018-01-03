#include<bits\stdc++.h>

using namespace std;

struct graph{
	int var1,var2,weight;
};

struct graph edge[100];
int p[100];
vector<int> result;

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

void display()
{
	while(!result.empty()){
		cout<<edge[*result.begin()].var1<<" -> "<<edge[*result.begin()].var2<<endl;
		result.erase(result.begin());
	}
}

int main()
{
	int edg,var;
	cout<<"Edge & Vartices"<<endl;
	cin>>edg>>var;
	for(int i=0;i<var;i++)
		makeSet(i);
	for(int i=0;i<edg;++i){
		int var1,var2,weight;
		cin>>var1>>var2>>weight;
		edge[i].var1=var1;
		edge[i].var2=var2;
		edge[i].weight=weight;
	}
	Kruskal(edg);
	display();
	return 0;
}
