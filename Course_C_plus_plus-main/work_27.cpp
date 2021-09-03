#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year)  {
	string name;  // изначально имя неизвестно

	// перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
		}
		else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}

	return name;
}
string FindHistoryNamesByYears(const map<int, string>& names, int year) {
	string cr_str;
	vector<string> name;  // изначально имя неизвестно
	// перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		if (item.first <= year) {// ..[cur]..[year]
			name.push_back(item.second);
		}
		else
		{
			break;
		}
	}
	int n_size = name.size();
	if (n_size == 0)
		return "";
	else if (n_size == 1)
		return name[0];
	else
	{
		int cnt = 0, cur_nsize = n_size;
		for (int i = cur_nsize - 1; i > 0; i--)
		{
			if (name[i] == name[i - 1])//..[i-1]..[i]..
			{
				cur_nsize = i;
				cr_str = name[i];
			}
			else
			{
				cur_nsize = i + 1;
				cr_str = name[i] + " (";
				break;
			}
		}

		for (int i = cur_nsize - 2; i >= 0; i--)
		{
			if (i != 0)
			{
				cr_str += name[i] + ", ";
			}
			else
			{
				cr_str += name[i];
			}
		}
		for (int i = n_size - 1; i > 0; i--)
		{
			if (name[i] != name[i - 1])
			{
				cr_str += ")";
				break;
			}
		}
	}

	return cr_str;
}
class Person {
public:
	Person(const string& fname,const string& lname, int ypers)
	{
		kekus = ypers;
		first_names[ypers] = fname;
		last_names[ypers] = lname;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if(year >= kekus)
			first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= kekus)
			last_names[year] = last_name;
	}
	string GetFullName(int year) const {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
			if(year < kekus)
				return "No person";
			return "Incognito";
			// если неизвестно только имя
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// если неизвестна только фамилия
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// если известны и имя, и фамилия
		}
		else {
			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) const {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindHistoryNamesByYears(first_names, year);
		const string last_name = FindHistoryNamesByYears(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
			if (year < kekus)
				return "No person";
			return "Incognito";

			// если неизвестно только имя
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// если неизвестна только фамилия
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// если известны и имя, и фамилия
		}
		else {
			return first_name + " " + last_name;
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
	int kekus;
};
int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
