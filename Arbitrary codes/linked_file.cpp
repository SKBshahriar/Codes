#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct list{
	int data;
	char name[50];
	struct list *next;
};
typedef struct list node;
int main()
{
	node *start, *temp, *temp1, *head, *start2;
	start = new node();
	scanf("%d", &start->data);
	fflush(stdin);
	gets(start->name);
	start2 = start;
	head = start;
	head = new node();
	head->data = 30;
	strcpy(head->name, start ->name);
	temp = new node();
	temp1 = new node();
	temp->data = 35;
	strcpy(temp->name, "sasa");
	temp1->data = 38;
	strcpy(temp1->name, "banglA");
	start->next = temp;
	temp->next = temp1;
	temp1->next = head;
	while (start2 != NULL)
	{
		printf("Data = %d\tName =%s", start2->data,start2->name);
		start2 = start2->next;
		printf("\n");
	}
	head->next = start;
	printf("%d", start->next->next->next->next->data);
	_getch();

}