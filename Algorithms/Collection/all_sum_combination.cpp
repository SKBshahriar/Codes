#include<bits/stdc++.h>
using namespace std;
vector<int> A;
void printCombo(int n,int k)
{
	if(n<0)
		return;
	if(n==0)
	{
		for(int i=0;i<A.size();i++)
			cout<<A.at(i)<<" ";
		cout<<endl;
	}
	//int i=1;
	for(int i=k;i<=n;i++)
	{
		A.push_back(i);
		printCombo(n-i,i);
		A.pop_back();		//i++;

	}

}
int main()
{
	int n;
	cin>>n;
	printCombo(n,1);
}
