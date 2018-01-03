#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
struct student{
	char fullname[20];
	char fname[20];
	char midname[20];
	char lname[20];
	float cgpa;
	int marks[5];
};
int main()
{
	FILE *p1, *p2, *p3,*p4;
	p1 = fopen("a.txt", "w");
	p2 = fopen("b.txt", "w");
	p3 = fopen("c.txt", "w");
	p4 = fopen("d.txt", "w");
	struct student x[3];
	int i = 0, j = 0, k = 0, l=0, c = 0, n, t = 0,count=0;
	for (l = 0; l<3; l++)
	{
		gets(x[l].fullname);
	}
	for (i = 0; i<3; i++)
	{
		for (j = 0; x[i].fullname[j] != ' '; j++)
			x[i].fname[j] = x[i].fullname[j];
		x[i].fname[j] = '\0';
		fprintf(p1, "%s\n", x[i].fname);
		c = 0;
		for (k = j + 1; x[i].fullname[k] != ' '; k++)
		{
			x[i].midname[c] = x[i].fullname[k];
			c++;
		}
		x[i].midname[c] = '\0';
		fprintf(p2, "%s\n", x[i].midname);
		t = 0;
		for (n = k + 1; x[i].fullname[n] != '\0'; n++, t++)
			x[i].lname[t] = x[i].fullname[n];
		x[i].lname[t] = '\0';
		fprintf(p3, "%s\n", x[i].lname);
	}
	for (i = 0; i < 3; i++)
	{
		j = 0; t = 0; c = 0; l = 0;
		for (j = 0; x[i].fullname[j] != '\0'; j++)
		{
			if (x[i].fullname[j] == 'a' || x[i].fullname[j] == 'A')
			{
				count++;
				if (count!= 2)
				{
					if (count < 2)
						c = j;
					else
						c = t;
				}
				if (count > 1)
				{
					t = j;
				}
				l = t - c;
				if (l >= 1)
					fprintf(p4, "%d ", l);
			}
		}
		fprintf(p4, "\n");
	}
	fclose(p1);
	fclose(p2);
	fclose(p3);
	_getch();
}

