#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"hellow world\n";
    vector<int> myvector;
    myvector.push_back(3);
    myvector.push_back(5);
    myvector.push_back(7);
    myvector.push_back(9);
    myvector.push_back(11);
    for(unsigned int i=0;i<myvector.size();i++)
        cout<<myvector.at(i)<<" ";
    cout<<endl;
    myvector.insert(myvector.begin()+2,6);
    for(unsigned int i=0;i<myvector.size();i++)
        cout<<myvector.at(i)<<" ";
    myvector.erase(myvector.begin()+3);
    cout<<endl;
    for(unsigned int i=0;i<myvector.size();i++)
        cout<<myvector.at(i)<<" ";
    if(myvector.empty())
        cout<<endl<<"Empty!!";
    else
         cout<<endl<<"Not Empty";
    myvector.clear();
     if(myvector.empty())
        cout<<endl<<"Empty!!";
    else
         cout<<endl<<"Not Empty";
}
