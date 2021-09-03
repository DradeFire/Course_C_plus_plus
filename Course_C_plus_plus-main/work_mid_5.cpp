#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		lists[year][0] = first_name;
		for (auto& item : years)
		{
			if (year == item)
			{
				break;
			}
		}
		years.push_back(year);
		sort(begin(years), end(years));
	}
	void ChangeLastName(int year, const string& last_name) {
		lists[year][1] = last_name;
		for (auto& item : years)
		{
			if (year == item)
			{
				break;
			}
		}
		years.push_back(year);
		sort(begin(years), end(years));
	}
	string GetFullName(int year) {
		sort(begin(years),end(years));

		int count_y = 0,y_size = years.size();
		
		for (int i = 0;i < y_size; i++)
		{
			vector<string> tmp_str(2);
			if (year < years[i] && i == 0)
			{
				return "Incognito";
			}
			else if(year < years[i])
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (lists[years[j]][0] != "")
					{
						tmp_str[0] = lists[years[j]][0];
						break;
					}
				}
				for (int j = i - 1; j >= 0; j--)
				{
					if (lists[years[j]][1] != "")
					{
						tmp_str[1] = lists[years[j]][1];
						break;
					}
				}
				if(tmp_str[0] == "")
				{
					return tmp_str[1] + " with unknown first name";
				}
				else if(tmp_str[1] == "")
				{
					return tmp_str[0] + " with unknown last name";
				}
				else
				{
					return tmp_str[0] + " " + tmp_str[1];
				}
			}
			else if(i == y_size - 1 && year >= years[i])
			{

				for (int j = i; j >= 0; j--)
				{
					if (lists[years[j]][0] != "")
					{
						tmp_str[0] = lists[years[j]][0];
						break;
					}
				}
				for (int j = i; j >= 0; j--)
				{
					if (lists[years[j]][1] != "")
					{
						tmp_str[1] = lists[years[j]][1];
						break;
					}
				}
				if (tmp_str[0] == "")
				{
					return tmp_str[1] + " with unknown first name";
				}
				else if (tmp_str[1] == "")
				{
					return tmp_str[0] + " with unknown last name";
				}
				else
				{
					return tmp_str[0] + " " + tmp_str[1];
				}
			}
		}
	
	}
private:
	vector<int> years;
	map<int, string[2]> lists;//0 - first_name, 1 - last_name
};

int main()
{
	//setlocale(LC_ALL, "ru");
	
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}


	return 0;
}
