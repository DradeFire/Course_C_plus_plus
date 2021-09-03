#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		str.push_back(s);
		// добавить строку s в набор
	}
	vector<string> GetSortedStrings() {
		sort(begin(str),end(str));
		return str;
		// получить набор из всех добавленных строк в отсортированном порядке
	}
private:
	vector<string> str;
};

void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	//setlocale(LC_ALL, "ru");
	
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}
