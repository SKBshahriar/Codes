#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct emp{
	char firstname[100];
	char lastname[100];
	int age;
	float salary;
};
int main()
{
	struct emp x[5];
	int i, j, k, n, m, l = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		printf("Enter First Name And Last Name\n");
		fflush(stdin);
		gets(x[i].firstname);
		fflush(stdin);
		gets(x[i].lastname);
		printf("Enter Age : ");
		scanf("%d", &x[i].age);
		printf("Enter Salary : ");
		scanf("%f", &x[i].salary);
	}
	for (j = 0; j<n; j++)
	{
		if (x[j].salary<10000)
		{
			x[j].salary = x[j].salary - ((x[j].salary / 100) * 2);
		}
		else if (x[j].salary>10000)
		{
			x[j].salary = x[j].salary - ((x[j].salary / 100) * 5);
		}
	}
	for (j = 0; j<n; j++)
	{
		for (i = 0, l = 0; x[j].firstname[i] != '\0'; i++)
		{
			if (x[j].firstname[i] == 'a' || x[j].firstname[i] == 'A')
				l++;
		}
		for (i = 0; x[j].lastname[i] != '\0'; i++)
		{
			if (x[j].lastname[i] == 'a' || x[j].lastname[i] == 'A')
				l++;
		}
		printf("\nFull Name: %s %s\nAge: %d\nSalaey: %f", x[j].firstname, x[j].lastname, x[j].age, x[j].salary);
		fflush(stdout);
		printf("\nTotal no of a : %d", l);
	}

	_getch();
}