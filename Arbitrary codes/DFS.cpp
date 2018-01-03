#include<stdio.h>
#define size 100
int vs=-1,top=-1,n,graph[size][size];
char visited_list[size],stack[size],vartex[26];
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
void push(char ch)
{
    if((top+1)==size)
        return;
    else
    {
        top++;
        stack[top]=ch;
    }
}
char pop()
{
    char ch;
    if(top==-1)
        return '\0';
    else
    {
        ch=stack[top];
        stack[top]='\0';
        top--;
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
                        push(vartex[j]);
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
void dfs()
{
    char ch;
    push(vartex[0]);
    while(top!=-1)
    {
        ch=pop();
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
    dfs();
    display();
    return 0;
}
