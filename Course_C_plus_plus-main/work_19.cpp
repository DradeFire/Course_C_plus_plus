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
	
	int N;
	cin >> N;
	string tmp_str;
	set<string> un_strs;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp_str;
		un_strs.insert(tmp_str);
	}
	cout << un_strs.size();

	return 0;
}
