#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	//setlocale(LC_ALL, "ru");

	map<string, string> countries;
	int Q;
	cin >> Q;
	vector<string> s(Q),s_0(Q),s_1(Q);

	for (int i = 0; i < Q; i++)
	{
		cin >> s[i];

		if (s[i] == "CHANGE_CAPITAL")
		{
			cin >> s_0[i] >> s_1[i];
		}
		else if (s[i] == "RENAME")
		{
			cin >> s_0[i] >> s_1[i];
		}
		else if (s[i] == "ABOUT")
		{
			cin >> s_0[i];
		}
	}
	for (int i = 0; i < Q; i++)
	{
		if (s[i] == "CHANGE_CAPITAL")
		{
			int kkk = 0;
			if (countries.count(s_0[i]) == 0)
			{
				countries[s_0[i]] = s_1[i];
				cout << "Introduce new country " + s_0[i] + " with capital " + s_1[i] << endl;
			}
			else
			{
				if (countries[s_0[i]] == s_1[i])
				{
					cout << "Country " + s_0[i] + " hasn't changed its capital" << endl;
				}
				else
				{
					cout << "Country " + s_0[i] + " has changed its capital from " + countries[s_0[i]] + " to " + s_1[i] << endl;
					countries[s_0[i]] = s_1[i];
				}
			}

		}
		else if (s[i] == "RENAME")
		{
			if (s_0[i] == s_1[i] || countries.count(s_0[i]) == 0 || countries.count(s_1[i]) == 1)
				cout << "Incorrect rename, skip" << endl;
			else
			{
				cout << "Country " + s_0[i] + " with capital " + countries[s_0[i]] + " has been renamed to " + s_1[i] << endl;
				countries[s_1[i]] = countries[s_0[i]];
				countries.erase(s_0[i]);
			}
		}
		else if (s[i] == "ABOUT")
		{
			if (countries.count(s_0[i]) == 0)
			{
				cout << "Country " + s_0[i] + " doesn't exist" << endl;
			}
			else
			{
				cout << "Country " + s_0[i] + " has capital " + countries[s_0[i]] << endl;
			}
		}
		else if (s[i] == "DUMP")
		{
			if (countries.size() == 0)
			{
				cout << "There are no countries in the world" << endl;
			}
			else
			{
				for (const auto& item : countries)
				{
					cout << item.first << "/" << item.second << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
