#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct library{
	char name[100];
	char srch[100];
	int price;
};
void main(void)
{
    SetConsoleTitle("Book Store");
    system("mode 80,50");
    system("color 0c");
	struct library x[100];
	int i=7,j,k,sum=0,m,h,n,num,z,l;
	char a,b;
	printf("\n                                LIBRARY MANAGEMENT\n                 -----------------------------------------------\n\n");
	printf("\n\t\t1.ADD A BOOK\n\n\t\t2.SHOW BOOK LIST\n\n\t\t3.SHOW QUANTITY OF BOOKS AND TOTAL PRICE\n\n\t\t4.SEARCH A BOOK\n\n\t\t5.EXIT THE PROGRAM\n");
	strcpy(x[0].name,"THE PEOPLE OF THE MIST");
	x[0].price=350;
	strcpy(x[1].name,"THE VINCHI CODE");
	x[1].price=650;
	strcpy(x[2].name,"THE LOST SYMBOL");
	x[2].price=450;
	strcpy(x[3].name,"ALLAN AND THE HOLLY FLOWER");
	x[3].price=350;
	strcpy(x[4].name,"THE IVORY CHILD");
	x[4].price=320;
	strcpy(x[5].name,"RETURN OF SHE");
	x[5].price=360;
	strcpy(x[6].name,"CHILD OF STORM");
	x[6].price=300;
	for(l=0;l<7;l++){
        sum=sum+x[l].price;
	}
	for(z=0;z<100;z++){
	printf("\n\n\t\t\tENTER YOUR CHOICE : ");
	scanf("%d",&num);
	switch(num)
	{
	    case 1:
	for(j=0;j<=100;i++){
    fflush(stdin);
	printf("\n\t\t\tENTER A BOOK : ");
	gets(x[i].name);
	fflush(stdin);
	printf("\n\t\t\tPRICE : ");
	scanf("%d",&x[i].price);
	sum=sum+x[i].price;
	printf("\n\n\t\t\tIF YOU WANT TO EXIT, PRESS n OR PRESS\n\t\t\tANY KEY TO ADD MORE BOOK : ");
	fflush(stdin);
	scanf("%c",&a);
	printf("\n");
	if(a=='n'){
		j=120;
	}
	}
    break;
	case 2:
	printf("\n\n\t\t\tBOOK LIST \n\n");
	printf("-----------------------------------------------\n");
	for(k=0;k<i;k++){
		printf("\t\tNAME : %s\n\n\t\tPRICE : %d\n-----------------------------------------------\n",x[k].name,x[k].price);
	}
	break;
	case 3:
	printf("\n\n\t\t\tTOTAL NO OF BOOKS IS %d\n",i);
	printf("\n\n\t\t\tTOTAL PRICE OF BOOKS IS %d\n",sum);
	break;
	case 4:
    fflush(stdin);
    for(k=0;k<100;k++){
            printf("\n\n\t\t\tSEARCH BOOK : ");
		m=1;
            fflush(stdin);
        gets(x[k].srch);
        for(j=0;j<i;j++){
            if(strcmp(x[k].srch,x[j].name)==0)
                {
                n=j;
                m=0;
                }
        }
        if(m==0){
                printf("\n\t\t\t**********************************");
            printf("\n\n\t\t\tTHE BOOK IS AVAILABLE IN LIBRARY\n");
            for(h=n;h<=n;h++){
                printf("\n\n\t\t\tNAME: %s\n\n\t\t\tPRICE : %d\n\n\t\t\t**********************************",x[h].name,x[h].price);
            }
        }
        else{
                 printf("\n\t\t\t**********************************\n");
            printf("\n\n\t\t\t   THE BOOK IS NOT AVAILABLE \n\n\t\t\t\t   IN LIBRARY\n\n\n\t\t\t**********************************");
        }
    printf("\n\n\t\t\tIF YOU WANT TO EXIT, PRESS n OR PRESS\n\t\t\tANY KEY TO CONTINUE SEARCH: ");
        fflush(stdin);
        scanf("%c",&b);
        if(b=='n'){
            k=120;
        }
    }
    break;
    case 5:
        z=120;
        break;
    default :
        printf("\n\n\t\t\tWRONG INPUT");
        break;
        }

    }
    getch();
}
