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
	
	vector<string> mas_str;
	int N;
	string tmp_str;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> tmp_str;
			mas_str.push_back(tmp_str);
		}

		sort(begin(mas_str), end(mas_str), [](string x, string y) {for (char& xx : x) { xx = tolower(xx); }; for (char& yy : y) { yy = tolower(yy); }; return x < y; });

		for (const auto& item : mas_str)
		{
			cout << item << " ";
		}


	return 0;
}
