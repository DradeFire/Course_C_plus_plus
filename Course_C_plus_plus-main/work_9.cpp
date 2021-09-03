#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int k,tmp;
	vector<int> a;
	cin >> k;
	
	while (k > 0)
	{
		tmp = k % 2;
		a.push_back(tmp);
		k /= 2;

	}
	for(int i = a.size() - 1;i >= 0;i--)
		cout << a[i];

	return 0;
}
