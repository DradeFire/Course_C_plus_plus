#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& maps)
{
	set<string> tmp_set;
	for (const auto& item : maps)
		tmp_set.insert(item.second);
	return tmp_set;
}
