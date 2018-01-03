#include<iostream>
using namespace std;
int p[100000];
struct graph{
    int vartex1;
    int vartex2;
    int weight;
};
int find_set(int x)
{
    if(x==p[x])
        return x;
    else
        find_set(p[x]);
}
void Unioun(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    if(fx!=fy)
        p[fy]=fx;
}
void makeset(int x)
{
    p[x]=x;
}
int main()
{
    int var,no_of_edge, set[1000],i,j,sum=0;
    struct graph grp[1000],temp;
    cout<<"Number of vartex : ";
    cin>>var;
    cout<<"Number of edge : ";
    cin>>no_of_edge;
    for(i=0;i<no_of_edge;i++)
    {
        cin>>grp[i].vartex1>>grp[i].vartex2>>grp[i].weight;
    }
    for(i=0; i<var; i++)
    {
        makeset(i);
    }
    for(i=1;i<no_of_edge;i++)
    {
        for(j=0;j<no_of_edge-i;j++)
        {
            if(grp[j].weight>grp[j+1].weight)
            {
                temp=grp[j];
                grp[j]=grp[j+1];
                grp[j+1]=temp;
            }
        }
    }
    j=0;
    /*Unioun(0,2);
    for(i=0;i<no_of_edge;i++)
    {
        if(grp[i].vartex1==0 && grp[i].vartex2==2)
        {
            sum+=grp[i].weight;
            set[j]=i;
            j++;
        }
    }
    Unioun(7,8);
    for(i=0; i<no_of_edge; i++)
    {
        if(grp[i].vartex1==7 && grp[i].vartex2==8)
        {
            sum+=grp[i].weight;
            set[j]=i;
            j++;
        }
    }*/
    for(i=0;i<no_of_edge;i++)
    {
        if((find_set(grp[i].vartex1))!=(find_set(grp[i].vartex2)))
        {
            Unioun(grp[i].vartex1,grp[i].vartex2);
            sum+=grp[i].weight;
            set[j]=i;
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        int c=set[i];
         cout << grp[c].vartex1 << "->" << grp[c].vartex2<<" "<<grp[c].weight<<endl;
    }
    cout<<sum;
}
