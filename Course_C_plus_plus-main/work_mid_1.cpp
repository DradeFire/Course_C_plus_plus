#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//setlocale(LC_ALL, "ru");

	vector<vector<string>> a(12);
	a[0].assign(31,"");
	a[1].assign(28, "");
	a[2].assign(31, "");
	a[3].assign(30, "");
	a[4].assign(31, "");
	a[5].assign(30, "");
	a[6].assign(31, "");
	a[7].assign(31, "");
	a[8].assign(30, "");
	a[9].assign(31, "");
	a[10].assign(30, "");
	a[11].assign(31, "");

	int q;
	cin >> q;
	
	for(int i = 0,k = 0;k < q;)
	{
		string s;
		cin >> s;

		if (s == "ADD")
		{
			int tmp1;
			string tmp2;
			cin >> tmp1 >> tmp2;
			tmp1--;
			a[i][tmp1] += tmp2 + " ";
		}
		else if (s == "DUMP")
		{
			int tmp,count_0 = 0,g = 0;
			cin >> tmp;
			tmp--;
			while (a[i][tmp][g] != '\0')
			{
				if (a[i][tmp][g] == ' ')
					count_0++;
				g++;
			}
			cout << count_0 << " " << a[i][tmp] << endl;
		}
		else if (s == "NEXT")
		{
			int tmpi1 = a[i].size();
			if (i != 11)
			{
				int tmpi2 = a[i + 1].size();
				if (tmpi2 < tmpi1)
				{
					for (int j = 0; j < tmpi2; j++)
					{
						a[i + 1][j] = a[i][j];
					}
					for (int j = tmpi2; j < tmpi1; j++)
					{
						a[i + 1][tmpi2 - 1] += a[i][j];
					}
				}
				else
				{
					for (int j = 0; j < tmpi1; j++)
					{
						a[i + 1][j] = a[i][j];
					}
				}

			}
			else
			{ 
				for (int j = 0; j < 31; j++)
				{
					a[0][j] = a[11][j];
				}
			}
			a[i].assign(tmpi1, "");
			i++;
		}
		k++;
		if (i == 12)
			i = 0;
	}
	
	return 0;
}
