#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	//setlocale(LC_ALL, "ru");
	map<string, vector<string>> Buss, Stops;
	int Q, stop_count;
	cin >> Q;
	string s, bus_name, stop_name;

	for (int i = 0; i < Q; i++)
	{
		cin >> s;
		if (s == "NEW_BUS")
		{
			cin >> bus_name >> stop_count;
			for (int i = 0; i < stop_count; i++)
			{
				cin >> stop_name;
				Buss[bus_name].push_back(stop_name);
				Stops[stop_name].push_back(bus_name);
			}

		}
		else if (s == "BUSES_FOR_STOP")
		{
			cin >> stop_name;
			if (Stops.count(stop_name) == 0)
			{
				cout << "No stop" << endl;
			}
			else {
				for (const auto& st : Stops[stop_name])
					cout << st << " ";
				cout << endl;
			}
		}
		else if (s == "STOPS_FOR_BUS")
		{
			cin >> bus_name;
			if (Buss.count(bus_name) != 0)
			{
				int tmp_count = Buss[bus_name].size(), tmp_stop_name;
				for (int j = 0; j < tmp_count; j++)
				{
					cout << "Stop " << Buss[bus_name][j] << ": ";
					tmp_stop_name = Stops[Buss[bus_name][j]].size();
					if (tmp_stop_name < 2)
						cout << "no interchange" << endl;
					else
					{
						for (int g = 0; g < tmp_stop_name; g++)
						{
							if (Stops[Buss[bus_name][j]][g] == bus_name)
								continue;
							cout << Stops[Buss[bus_name][j]][g] << " ";
						}
						cout << endl;
					}

				}
			}
			else
				cout << "No bus" << endl;
			
			
		}
		else if (s == "ALL_BUSES")
		{
			if (Buss.size() > 0)
			{
				for (const auto& bus : Buss)
				{
					cout << "Bus " << bus.first << ": ";
					for (const auto& stops : bus.second)
						cout << stops << " ";
					cout << endl;
				}
			}
			else
			{
				cout << "No buses" << endl;
			}

		}
	}

	return 0;
}
