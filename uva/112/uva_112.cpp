#include<stdio.h>
int main()
{
    int i,j,k,bin[3][3],move[6],a[6],min1,min,t,count;
    while(1)
    {
        t=0;
        count=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(scanf("%d",&bin[i][j]) == EOF) return 0;
            }
        }
        move[0]=bin[1][0]+bin[2][0]+bin[0][2]+bin[2][2]+bin[0][1]+bin[1][1];
        move[1]=bin[1][0]+bin[2][0]+bin[0][1]+bin[2][1]+bin[0][2]+bin[1][2];
        move[2]=bin[1][2]+bin[2][2]+bin[0][0]+bin[2][0]+bin[0][1]+bin[1][1];
        move[3]=bin[1][2]+bin[2][2]+bin[0][1]+bin[2][1]+bin[0][0]+bin[1][0];
        move[4]=bin[1][1]+bin[2][1]+bin[0][0]+bin[2][0]+bin[0][2]+bin[1][2];
        move[5]=bin[1][1]+bin[2][1]+bin[0][2]+bin[2][2]+bin[0][0]+bin[1][0];
        min=move[0];
        j=0;
        for(i=0; i<6; i++)
        {
            if(min>move[i])
            {
                min=move[i];
                j=i;
            }
        }
        for(i=0; i<6; i++)
        {
            if(move[i]==min)
            {
                 count++;
                 a[t]=i;
                 t++;
            }
        }
        if(count==1)
        {
            if(j==0)
                printf("BCG %d",move[j]);
            else if(j==1)
                printf("BGC %d",move[j]);
            else if(j==2)
                printf("CBG %d",move[j]);
            else if(j==3)
                printf("CGB %d",move[j]);
            else if(j==4)
                printf("GBC %d",move[j]);
            else if(j==5)
                printf("GCB %d",move[j]);
        }
        else
        {
            min1=a[0];
            k=0;
            for(i=0;i<count;i++)
            {
                if(min1>a[i])
                {
                    min1=a[i];
                    k=i;
                }
            }
            k=min1;
            if(k==0)
                printf("BCG %d",move[min1]);
            else if(k==1)
                printf("BGC %d",move[min1]);
            else if(k==2)
                printf("CBG %d",move[min1]);
            else if(k==3)
                printf("CGB %d",move[min1]);
            else if(k==4)
                printf("GBC %d",move[min1]);
            else if(k==5)
                printf("GCB %d",move[min1]);
        }
        printf("\n");
    }
    return 0;
}
