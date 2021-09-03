#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;



int main()
{
	//setlocale(LC_ALL, "ru");
	
	vector<int> mas_int;
	int N, tmp_int;
	//do
	//{
		cin >> N;
	//} while (N > 1000 || N < 0);

		for (int i = 0; i < N; i++)
		{
			cin >> tmp_int;
			mas_int.push_back(tmp_int);
		}

		sort(begin(mas_int), end(mas_int), [](int x, int y) {return abs(x) < abs(y); });

		for (const auto& item : mas_int)
		{
			cout << item << " ";
		}


	return 0;
}
