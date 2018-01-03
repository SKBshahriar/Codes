#define size 5
#include<stdio.h>
#include<conio.h>
int q[size + 1], f = 0, r = 0;
void enqueue(int item)
{
	int s;
	s = (r + 1) % (size + 1);
	if (s == f)
		printf("\nQueue Overflow");
	else
	{
		q[s] = item;
		r = s;
	}
}
void dequeue()
{
	if (f == r)
		printf("Queue Underflow\n");
	else
	{
		f = (f + 1) % (size + 1);
		q[f] = 0;
	}
}
void showmenu()
{
	printf("\n1.Enqueue\n2.Dequeue\n");
}
void display()
{
	int i, j;
	i = f;
	j = r;
	while (i != j)
	{
		i = (i + 1) % (size + 1);
		printf("%d ", q[i]);
	}
}
int main()
{
	int ch, item, i = 1;
	do
	{
		showmenu();
		printf("Enter Choice : ");
		scanf("%d", &ch);
		if (ch == 1)
		{
			printf("Enter Item : ");
			scanf("%d", &item);
			enqueue(item);
		}
		else if (ch == 2)
		{
			dequeue();
			printf("\ndequeue done\n");
		}
		else
			i = 0;
	} while (i == 1);
	display();
	return 0;
}
