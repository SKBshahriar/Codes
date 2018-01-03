#include<stdio.h>
#include<conio.h>
struct student{
    int id;
    float marks[3];
    float avg;
};
int main()
{
    struct student x[5];
    int i,j,n,k,m;
	float hst,hst1,hst2,hst3;
    for(i=0;i<5;i++){
        printf("Enter The Id : ");
        scanf("%d",&x[i].id);
        printf("Enter The Marks Of 3 Subjects\n");
        for(j=0;j<3;j++){
                fflush(stdin);
            scanf("%f",&x[i].marks[j]);
        }
        x[i].avg=(x[i].marks[0]+x[i].marks[1]+x[i].marks[2])/3.0;
    }
    hst=x[0].avg;
    for(k=0,n=0;k<5;k++){
            if(hst<x[k].avg){
                hst=x[k].avg;
                n=k;
            }
    }
    printf("Highest Average Obtained :\n");
    fflush(stdin);
    printf("ID : %d\nMark In 1st Sub : %f\nMark In 2nd Sub : %f",x[n].id,x[n].marks[0],x[n].marks[1]);
    fflush(stdin);
    printf("\nMark In 3rd Sub : %f\nAverage : %f",x[n].marks[2],x[n].avg);
    hst1=x[0].marks[0];
    hst2=x[0].marks[1];
    hst3=x[0].marks[2];
    for(m=0;m<5;m++){
            if(hst1<x[m].marks[0])
                hst1=x[m].marks[0];
             if(hst2<x[m].marks[1])
                hst2=x[m].marks[1];
                 if(hst3<x[m].marks[2])
                hst3=x[m].marks[2];
        }
        printf("\n\n1st Subject Highest mark : %f\n2nd Subject Highest mark : %f\n3rd Subject Highest mark : %f",hst1,hst2,hst3);
    getch();
}
