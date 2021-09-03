#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n,mid = 0,count = 0;
	cin >> n;

	vector<int> v(n);
	for (int& i : v)
	{
		cin >> i;
		mid += i;
	}
	mid /= n;

	for (int i = 0;i < n;i++)
	{
		if (v[i] > mid)
			count++;
	}
	
	cout << count << endl;
	
	for (int i = 0;i < n;i++)
	{
		if (v[i] > mid)
			cout << i << " ";
	}
	
	return 0;
}
