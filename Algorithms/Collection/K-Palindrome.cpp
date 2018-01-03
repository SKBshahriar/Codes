#include<bits/stdc++.h>
using namespace std;
int isKPal(string str1,string str2,int length1,int length2)
{
	if(length1==0)
		return length2;
	if(length2==0)
		return length1;

	if(str1[length1]==str2[length2])
		return isKPal(str1,str2,length1-1,length2-1);

	return 1+ min(isKPal(str1,str2,length1-1,length2),isKPal(str1,str2,length1,length2-1));
}
int main()
{
	string str;
	int k;
	cin>>str>>k;
	string str2=str;
	reverse(str2.begin(),str2.end());
	if(isKPal(str,str2,str.length(),str.length())<=k*2)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
