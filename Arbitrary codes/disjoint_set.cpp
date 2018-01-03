#include<iostream>
using namespace std;
int  a[10000];
void MakeSet(int x)
{
	a[x] = x;
}
void Union(int x, int y)
{
	int fx=FindSet(x);
	int fy=FindSet(y);
	if(fx!=fy)
        a[fx]=fy;
}
int FindSet(int x)
{
	if(x==a[x])
        return x;
    else
        FindSet(a[x]);
}
int main()
{
	int i, j, ans = 0, l = 0;
	while (l == 0)
	{
		cout << "1.Make Set" << endl << "2.Union" << endl << "3.Find Set" << endl << "4.Check" << endl;
		cout << "Choice : ";
		cin >> ans;
		if (ans == 1)
		{
			cout << "Enter data For Making Set" << " ";
			cin >> j;
			MakeSet(j);
		}
		else if (ans == 2)
		{
			cout << "Enter data For Union " << endl;
			cin >> i >> j;
			Union(i, j);
		}
		else if (ans == 3)
		{
			cout << "Enter data For Finding Set " << endl;
			cin >> i;
			cout << FindSet(i) << endl;
		}
		else if (ans == 4)
		{
			cout << "Enter data For Check " << endl;
			cin >> i >> j;
			if (FindSet(i) == FindSet(j))
				cout << i << " And " << j << "In Same Set" << endl;
			else
				cout << i << " And " << j << "In Different Set" << endl;
		}
		else
			l = 1;
	}
	cin >> j;
	return 0;
}
