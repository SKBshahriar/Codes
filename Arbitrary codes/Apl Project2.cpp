#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	printf("\n");
	char p[10], q[10];
	printf(".......................Welcome to Tic Tac Toe game:.....................\n\n");
	printf("Player 1 enter your name : ");
	scanf("%s", p);
	printf("Player 2 enter your name : ");
	scanf("%s", q);
	printf("\n");
	int a[3][3] = { 0, };
	int i, j, x, y;
	int count = 0;
	for (i = 1; i <= 9; i++)
	{

		if (count % 2 == 0)
		{
			printf("It's your turn %s : ", p);
			scanf("%d%d", &x, &y);
			a[x][y] = 'X';
			count++;
		}
		else
		{
			printf("It's your turn %s : ", q);
			scanf("%d%d", &x, &y);
			a[x][y] = 'O';
			count++;

		}
		printf("\n");
		for (i = 0; i<3; i++)
		{
			for (j = 0; j<3; j++)
			{
				if (a[i][j]=='\0')
					printf("\t_\t");
				else
					printf("\t%c\t", a[i][j]);
			}

			printf("\n\n");
		}

		if (a[0][0] == 'X'&&a[0][1] == 'X'&&a[0][2] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[1][0] == 'X'&&a[1][1] == 'X'&&a[1][2] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[2][0] == 'X'&&a[2][1] == 'X'&&a[2][2] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[0][0] == 'X'&&a[1][0] == 'X'&&a[2][0] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[0][1] == 'X'&&a[1][1] == 'X'&&a[2][1] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[0][2] == 'X'&&a[1][2] == 'X'&&a[2][2] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[0][0] == 'X'&&a[1][1] == 'X'&&a[2][2] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}
		if (a[0][2] == 'X'&&a[1][1] == 'X'&&a[2][0] == 'X')
		{
			printf("%s wins\n", p);
			break;
		}


		if (a[0][0] == 'O'&&a[0][1] == 'O'&&a[0][2] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[1][0] == 'O'&&a[1][1] == 'O'&&a[1][2] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[2][0] == 'O'&&a[2][1] == 'O'&&a[2][2] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[0][0] == 'O'&&a[1][0] == 'O'&&a[2][0] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[0][1] == 'O'&&a[1][1] == 'O'&&a[2][1] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[0][2] == 'O'&&a[1][2] == 'O'&&a[2][2] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[0][0] == 'O'&&a[1][1] == 'O'&&a[2][2] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (a[0][2] == 'O'&&a[1][1] == 'O'&&a[2][0] == 'O')
		{
			printf("%s wins\n", q);
			break;
		}
		if (count == 9)
		{
			printf("This is a tie");
			break;
		}
	}
	_getch();
}


