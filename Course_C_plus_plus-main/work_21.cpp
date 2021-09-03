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
	int Q;
	cin >> Q; 
	
	string tmp_str;
	map<string, set<string>> sinonims;

	for (int i = 0; i < Q; i++)
	{
		cin >> tmp_str;
		if (tmp_str == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			sinonims[word1].insert(word2);
			sinonims[word2].insert(word1);

		}
		else if (tmp_str == "COUNT")
		{
			string word;
			cin >> word;
			cout << sinonims[word].size() << endl;
		}
		else if (tmp_str == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;
			if(sinonims[word1].count(word2) == 0)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}

	return 0;
}
