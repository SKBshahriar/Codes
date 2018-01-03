#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	int eleven = 11;

	while (1)
	{
		int flg = 0;
		cin >> str;
		if (str[0] == '0' && str.length()==1)
			break;
		int lenght = str.length();
		if (str.length()<2 || (str[0] == '1' && str[1] == '0' && lenght == 2))
			cout << str << " is not a multiple of 11.\n";
		else
		{

			vector<int> arr;
			for (int i = 0; i<str.length(); i++)
				arr.push_back(str[i] - 48);

			int index = 1;
			int temp = (arr.at(0) * 10) + arr.at(1);

			while (index<lenght)
			{


				if (temp%eleven == 0)
				{
					if (index == (lenght - 1))
					{

						cout << str << " is a multiple of 11.\n";
						flg = 1;
						break;
					}

					if ((lenght - index)>2)
					{

						index++;
						temp = (arr.at(index) * 10) + arr.at(index + 1);
						index++;

					}
					else if(lenght-index==2 && arr.at(index+1)==0)
					{
						cout << str << " is a multiple of 11.\n";
						break;
					}
					else
					{
						cout << str << " is not a multiple of 11.\n";
						break;
					}

				}

				else
				{

					int dv = temp%eleven;
					if (lenght - index>1)
						temp = (dv * 10) + arr.at(++index);
					else
					{
						cout << str << " is not a multiple of 11.\n";
						break;
					}
				}
			}

		}
	}
	return 0;
}
