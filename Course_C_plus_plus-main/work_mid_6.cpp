#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
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
			if(name[i] != name[i - 1])
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
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
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
	string GetFullNameWithHistory(int year) {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindHistoryNamesByYears(first_names, year);
		const string last_name = FindHistoryNamesByYears(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
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
};
