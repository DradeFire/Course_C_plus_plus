#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	string s;
	int Q,tmp,count_worry = 0;
	vector<bool> P;

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> s;
		if (s != "WORRY_COUNT")
			cin >> tmp;
		else
		{
			for (auto p : P)
			{
				if (p == true)
					count_worry++;
			}
			cout << count_worry << endl;
			count_worry ^= count_worry;
			continue;
		}

		if (s == "WORRY")
		{
			P[tmp] = true;
			continue;
		}

		if (s == "QUIET")
		{
			P[tmp] = false;
			continue;
		}

		if (s == "COME")
		{
			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					P.push_back(false);
				}
			}
			else
			{
				P.resize(P.size() + tmp);
			}
		}
 
	}

	
	return 0;
}
