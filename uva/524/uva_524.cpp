#include<bits/stdc++.h>
using namespace std;
vector<int> circle,existance;
bool isPrime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
bool exist(int n)
{
	if(existance.empty())
		return true;
	for(int i=0;i<existance.size();i++)
	{
		if(existance.at(i)==n)
			return false;
	}
	return true;
}

void primeCircle(int n,int lim)
{
    if(n==lim && isPrime(circle.at(circle.size()-1)+circle.at(0)))
    {
        for(int i=0; i<circle.size(); i++)
            cout<<circle.at(i)<<" ";
		cout<<endl;
        return;
    }
    else if(n==lim && !isPrime(circle.at(circle.size()-1)+circle.at(0)))
		return;
	for(int i=2;i<=lim;i++)
	{
        if(exist(i))
        {
            if(isPrime(circle.at(circle.size()-1)+i))
            {
                circle.push_back(i);
                existance.push_back(i);
                primeCircle(n+1,lim);
                circle.pop_back();
                existance.pop_back();
            }
        }
	}
	return;
}
int main()
{
	int n,t=0;
	while (scanf("%d", &n) != EOF)
	{
		if(t>0)
			cout<<endl;
	 	circle.push_back(1);
	 	cout<<"Case "<<t+1<<":"<<endl;
	 	primeCircle(1,n);
	 	circle.clear();
	 	existance.clear();
	 	//cout<<endl;
	 	t++;
	}
	return 0;
}
