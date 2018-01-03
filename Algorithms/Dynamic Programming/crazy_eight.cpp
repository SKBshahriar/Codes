#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define N 100000
int cards[N];
int suits[N];
int v[N];
int y[N];
int x, count;
int match(int n, int i)
{
	if (cards[n] == cards[i] || suits[n] == suits[i] || cards[n] == 8 || cards[i] == 8)
		return 1;
	else
		return 0;
}
void generateCards(int n)
{
	while (n)
	{
		suits[n - 1] = rand() % 4;
		cards[n - 1] = (rand() % 13) + 1;
		n--;
	}
}
void print_card(int i)
{
	if (cards[i] != 10)
		printf("%c%c ", cards[i] == 1 ? 'A' : cards[i] == 11 ? 'J' : cards[i] == 12 ? 'Q' : cards[i] == 13 ? 'K' : '0' + cards[i], suits[i] + 3);
	else
		printf("10%c ", suits[i] + 3);
}
void printAll(int n)
{
	for (int i = 0; i<n; i++)
	{
		print_card(i);
	}
	printf("\n");
}
int c8(int n)
{
	int i, max, temp, j;
	if (v[n] != -1)
    return v[n];
    max = 1;
    for (i = n - 1; i >= 0; i--)
    {
        if (match(n, i) == 1)
        {
            temp = 1 + c8(i);
            if (max < temp)
            {
                max = temp;
                y[n] = i;
            }
        }
    }

    v[n] = max;
	return max;
}
void print_sequence(int j)
{
    int i;
	int k = count;
	for (k = 0; k < count; k++)
	{
		if (y[j] != -1)
		{
			int c = y[j];
			print_card(c);
			j = y[j];
		}
	}

}
int main()
{
	int j, i,temp,max=0;
	srand(time(NULL));
	int numberOfCards = 10;
	for (i = 0; i<200; i++)
		v[i] = -1;
	for (i = 0; i<200; i++)
		y[i] = -1;
	v[0] = 1;
	generateCards(numberOfCards);
	printAll(numberOfCards);
	for(i=1;i<numberOfCards;i++)
    {
        temp=c8(i);
        if(temp>max){
            max=temp;
            y[numberOfCards]=i;
        }
    }
	printf("\n%d\n", max);
	count = max;
	print_sequence(numberOfCards);
	return 0;
}


