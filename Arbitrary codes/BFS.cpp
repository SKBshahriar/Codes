#include<stdio.h>
#define size 100
int vs=-1,r=0,f=0,n,graph[size][size];
char visited_list[size],q[size+1],vartex[26];
void visit(char ch)
{
    vs++;
    visited_list[vs]=ch;
}
int check(char ch)
{
    int i;
    for(i=0;i<=vs;i++)
    {
        if(visited_list[i]==ch)
            return 0;
    }
    return 1;
}
void enqueue(char ch)
{
    int s;
    s=(r+1)%(size+1);
    if(s==f)
        return;
    else
    {
        q[s]=ch;
        r=s;
    }
}
char dequeue()
{
    char ch;
    if(f==r)
        return '\0';
    else
    {
        f=(f+1)%(size+1);
        ch=q[f];
        q[f]='\0';
    }
    return ch;
}
void find_adjacent(char ch)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(vartex[i]==ch)
        {
            for(j=0; j<n; j++)
            {
                if(graph[i][j]==1)
                {
                    if(check(vartex[j])==1)
                        enqueue(vartex[j]);
                }
            }
        }
    }
}
void graph_input()
{
    int i,j;
    for(i=0;i<26;i++)
    {
        vartex[i]=65+i;
    }
    printf("How Many Vartices :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            graph[i][j]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            printf("%c-%c Exist? ",vartex[i],vartex[j]);
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==1)
                graph[j][i]=1;
        }
    }
}
void bfs()
{
    char ch;
    enqueue(vartex[0]);
    while(f!=r)
    {
        ch=dequeue();
        if(check(ch)==1)
        {
            visit(ch);
            find_adjacent(ch);
        }
    }
}
void display()
{
    int i;
    for(i=0;i<=vs;i++)
        printf("%c ",visited_list[i]);
}
int main()
{
    graph_input();
    bfs();
    display();
    return 0;
}
