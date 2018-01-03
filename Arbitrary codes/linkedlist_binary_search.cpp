#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
struct list{
	int data;
	struct list *back;
	struct list *next;
};
typedef struct list node;
void display(node *start)
{
	node *temp;
	temp = start;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main()

{
	node *start, *temp, *prev, *midindex, *temp1;
	int i, j, ch, item, count = 0, low = 1, high, mid;
	start = NULL;
	prev = start;
	do
	{
		printf("Do You Want To Create A Node? ");
		scanf("%d", &ch);
		if (ch == 1)
		{
			if (start == NULL)
			{
				start = new node();
				start->next = NULL;
				start->back = NULL;
				printf("Enter Data For Node : ");
				scanf("%d", &start->data);
				prev = start;
				count++;
			}
			else
			{
				temp = new node();
				printf("Enter Data For Node : ");
				scanf("%d", &temp->data);
				prev->next = temp;
				temp->back = prev;
				prev = temp;
				count++;
			}
		}
	} while (ch == 1);
	printf("\nEnter Item : ");
	scanf("%d", &item);
	high = count;
	temp = start;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (low == mid)
		{
			temp = start;
			for (i = 1; i < mid; i++)
				temp = temp->next;
		}
		else
		{
			for (i = low; i < mid; i++)
			{
				temp = temp->next;
			}
		}
		if (temp->data == item)
		{
			printf("\nFound!");
			break;
		}
		else if (temp->data > item)
		{
			high = mid - 1;
		}
		else if (temp->data < item)
		{
			low = mid + 1;
			temp = temp->next;
		}
	}
	if (low > high)
		printf("\nNot Found");
	_getch();
}