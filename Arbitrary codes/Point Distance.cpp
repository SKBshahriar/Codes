#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>
struct dist{
	int x;
	int y;
};
float dis(struct dist p1, struct dist p2){
	float f1 = (p1.x - p2.x)*(p1.x - p2.x);
	float f2 = (p1.y - p2.y)*(p1.y - p2.y);
	float d = sqrt(f1 + f2);
	return d;
}
int main()
{
	struct dist q1, q2;
	float i;
	fflush(stdin);
	scanf("%d%d%d%d", &q1.x, &q1.y, &q2.x, &q2.y);
	i = dis(q1, q2);
	printf("%f", i);
	_getch();
}