#include<iostream>
#include<queue>
using namespace std;

char Color[1000];
int Partent[1000];
int Distance[1000];
int adj_mat[100][100];

queue<int> q;
bool cycle;

void input(int no_of_vartex)
{
	int i, j;

	for (i = 0; i<no_of_vartex; i++)
	{
		for (j = 0; j<no_of_vartex; j++)
		{
			cin >> adj_mat[i][j];
		}
	}
}

void BFS(int no_of_vartex)
{
	int i, j, k;
	int u, v;

	for (i = 0; i < no_of_vartex; i++)
	{
		Color[i] = 'W';
		Partent[i] = -1;
		Distance[i] = -1;
	}

	q.push(1);
	Color[1] = 'G';
	Distance[1] = 0;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		Color[u] = 'B';

		for (v = 0; v < no_of_vartex; v++)
		{
			if (adj_mat[u][v] != 0 && Color[v] == 'W')
			{
				q.push(v);
				Distance[v] = Distance[u] + 1;
				Color[v] = 'G';
				Partent[v] = u;
			}
			else if (adj_mat[u][v] != 0 && Color[v] == 'G')
				cycle = true;
		}
	}
}
int main()
{
	int no_of_vartex;
	char vartex[26];

	cout << "Number of vartex : ";
	cin >> no_of_vartex;
	cout << "Enter The Graph"<<endl;
	input(no_of_vartex);

	BFS(no_of_vartex);

	for (int i = 0; i < no_of_vartex; i++)
	{
		vartex[i] = 82 + i;
	}

	cout << endl;

	for (int i = 0; i < no_of_vartex; i++)
		cout << Distance[i] << " ";

	cout << endl;

	for (int i = 0; i < no_of_vartex; i++)
		cout << vartex[Partent[i]]<<" ";

	if (cycle == true)
		cout << endl <<endl<< "There is a cycle";
	else
		cout << endl <<endl << "There is no cycle";

	cin >> no_of_vartex;
	return 0;
}
