#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string BuildCharCounters(const string& a, const string& b)
{
	map<char, int> count_chars_1;
	map<char, int> count_chars_2;
	for (const auto& chr : a)
		count_chars_1[chr]++;
	for (const auto& chr : b)
		count_chars_2[chr]++;

	if (a.size() == b.size())
	{
		for (const auto& chr : a)
		{
			if (count_chars_1[chr] != count_chars_2[chr])
			{
				return "NO";
			}
		}
		return "YES";
	}
	return "NO";

}

int main()
{
	//setlocale(LC_ALL, "ru");

	int N;
	cin >> N;
	vector<string> str1(N), str2(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> str1[i] >> str2[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << BuildCharCounters(str1[i], str2[i]) << endl;
	}

	return 0;
}
