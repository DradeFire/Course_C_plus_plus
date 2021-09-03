#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int k = 0;
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == 'f')
			k++;
		if (k == 2)
		{
			cout << i;
			break;
		}

	}
	if (k == 0)
		cout << -2;
	else if (k == 1)
		cout << -1;

	

	return 0;
}
