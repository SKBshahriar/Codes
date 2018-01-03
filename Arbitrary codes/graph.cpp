#include<stdio.h>
int main()
{
    char vartex[26],v;
    int i,var,graph[20][20],j;
    for(i=0;i<26;i++)
    {
        vartex[i]=65+i;
    }
    scanf("%d",&var);
    for(i=0; i<var; i++)
    {
        for(j=0; j<var; j++)
        {
            graph[i][j]=0;
        }
    }
    for(i=0; i<var; i++)
    {
        for(j=i+1; j<var; j++)
        {
            printf("%c-%c exist? ",vartex[i],vartex[j]);
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==1)
                graph[j][i]=1;
        }
    }
    for(i=0;i<var;i++)
    {
      printf("%c-> ",vartex[i]);
        for(j=0; j<var; j++)
        {
            if(graph[i][j]==1)
                printf("%c ",vartex[j]);
        }
      printf("\n");
    }
    fflush(stdin);
    scanf("%c",&v);
    for(i=0; i<var; i++)
    {
        if(vartex[i]==v)
        {
            printf("%c-> ",vartex[i]);
            for(j=0; j<var; j++)
            {
                if(graph[i][j]==1)
                    printf("%c ",vartex[j]);
            }
        }
    }
}
