#include<bits/stdc++.h>
using namespace std;
bool t[100];
int v[1100][1100];
int cut_sticks(int start, int end, int n, int c[])
{
	if (v[start][end] != -1) return v[start][end];
	bool flag=false;
	int min = INT_MAX;
	for (int i = 0;i<n;i++) {
		if (end >= c[i] && start <= c[i] && !t[i]) {
			flag = true;
			t[i] = true;
			int temp = ((end - start) + 1) + cut_sticks(start, c[i], n, c) + cut_sticks(c[i] + 1, end, n, c);
			if (temp<min) min = temp;
			t[i] = false;
		}
	}
	if (flag) return v[start][end]=min;
	else return v[start][end]=0;
}
int main()
{
	int l, n, c[60];
	while (1) {
        scanf("%d", &l);
        if(l==0) break;
		memset(v, -1, sizeof(v));
		scanf("%d", &n);
		for (int i = 0;i<n;i++) {
			scanf("%d", &c[i]);
			t[i] = false;
		}
		cout << "The minimum cutting is " << cut_sticks(1, l, n, c) <<"."<< endl;
	}
	return 0;
}
