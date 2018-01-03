#include<stdio.h>>
#include<stdlib.h>
#include<time.h>
struct list
{
	int data;
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
	node *start, *head, *prev, *temp, *temp2, *temp3, *temp1, *temp4;
	int nop, i, a, f;
	start = NULL;
	head = NULL;
	prev = start;
	scanf("%d", &nop);
	for (i = 0; i<nop; i++)
	{
		if (start == NULL)
		{
			start = new node();
			start->data = i + 1;
			prev = start;
			prev->next = NULL;
		}
		else
		{
			temp = new node();
			prev->next = temp;
			temp->data = i + 1;
			temp->next = NULL;
			prev = temp;
		}
	}
	temp = new node();
	temp->next = start;
	temp4 = temp;
	srand(time(NULL));
	while (1)
	{
		if (temp->next == start && start->next == NULL)
		{
			printf("\nThe Winner Is No : %d", start->data);
			break;
		}
		f = 1;
		a = rand() % nop + 1;
		temp = temp4;
		if (head != NULL)
		{
			temp3 = head;
			while (temp3 != NULL)
			{
				if (temp3->data == a)
					f = 0;
				temp3 = temp3->next;
			}
		}
		if (f == 1)
		{
			while (temp->next != NULL && temp->next->data != a)
			temp = temp->next;
			if (head == NULL)
			{
				head = new node();
				head->data = a;
				head->next = NULL;
				prev = head;
			}
			else
			{
				temp1 = new node();
				temp1->data = a;
				prev->next = temp1;
				temp1->next = NULL;
				prev = temp1;
			}
			temp2 = temp->next;
			temp->next = temp2->next;
			if (temp2 == start)
				start = start->next;
			delete temp2;
			printf("%d ", a);
		}
	}
	return 0;
}
