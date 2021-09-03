#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	//setlocale(LC_ALL, "ru");
	
	int Q, N, tmp_int,count_bus = 0;
	cin >> Q;
	string tmp_str;
	map<int, vector<string>> BUS;

	for (int i = 0,k = 0; i < Q; i++, k++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> tmp_str;
			BUS[k].push_back(tmp_str);
		}
		tmp_int = BUS.size();
		for (int j = 0; j < tmp_int; j++)
		{
			if (BUS[k] == BUS[j] && k != j)
			{
				cout << "Already exists for " << j + 1 << endl;
				BUS.erase(k);
				k--;
				break;
			}
			if(j == tmp_int - 1)
			{
				count_bus++;
				cout << "New bus " << count_bus << endl;
				break;
			}
			
		}

	}

	return 0;
}
