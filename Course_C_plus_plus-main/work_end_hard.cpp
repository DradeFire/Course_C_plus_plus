#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Date
{
public:
	Date(int new_year, int new_month, int new_day)
	{
		year = new_year;
		month = new_month;
		day = new_day;
	}
	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}

private:
	int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear())
	{
		return true;
	}
	else if (lhs.GetYear() > rhs.GetYear())
	{
		return false;
	}
	else
	{
		if (lhs.GetMonth() < rhs.GetMonth())
		{
			return true;
		}
		else if (lhs.GetYear() > rhs.GetYear())
		{
			return false;
		}
		else
		{
			if (lhs.GetDay() < rhs.GetDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

ostream& operator<<(ostream& stream, const Date& date)
{
	int year = date.GetYear(), month = date.GetMonth(), day = date.GetDay();
	string syear, smonth, sday;
	if (year >= 0 && year < 10)
	{
		syear = "000" + to_string(year);
	}
	else if (year >= 10 && year < 100)
	{
		syear = "00" + to_string(year);
	}
	else if (year >= 100 && year < 1000)
	{
		syear = "0" + to_string(year);
	}
	else if (year >= 1000)
	{
		syear = to_string(year);
	}

	if (month < 10)
		smonth = "0" + to_string(month);
	else
		smonth = to_string(month);

	if (day < 10)
		sday = "0" + to_string(day);
	else
		sday = to_string(day);

	stream << syear << '-' << smonth << '-' << sday;
	return stream;
}

class Database
{
public:
	void AddEvent(const Date& date, const string& event)
	{
		db[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event_str)
	{
		if (db.count(date) > 0)
		{
			for (const string& strs : db[date])
			{
				if (event_str == strs)
				{
					db[date].erase(event_str);
					return true;
				}
			}
		}

		return false;
	}
	int DeleteDate(const Date& date)
	{
		int del_count = 0;
		if (db.count(date) > 0)
		{
			del_count = db[date].size();
			db[date].clear();
		}
		return del_count;
	}
	void Find(const Date& date) const
	{
		if (db.count(date) > 0)
		{
			for (const auto& strs : db.at(date))
			{
				cout << strs << endl;
			}
		}
	}
	void Print() const
	{
		for (const auto& items : db)
		{
			for (const auto& strs : items.second)
			{
				cout << items.first << ' ' << strs << endl;
			}
		}
	}
	//готово

private:
	map <Date, set<string>> db;
};

void CheckIsDigit(const string& s, string& sndate, const int& ndate, const int& iNEW)
{
	for (int i = iNEW; i < ndate; i++)
	{
		if (i == iNEW && s.at(i) == '+')
			continue;
		sndate += s.at(i);
	}
	for (int i = 0; i < sndate.size(); i++)
	{
		if (i == 0 && (isdigit(sndate[0]) != 0 || sndate[0] == '-'))
		{
			continue;
		}
		else if (i > 0 && (isdigit(sndate[0]) != 0 || sndate[0] == '-' || sndate[0] == '+'))
		{
			if (isdigit(sndate[i]))
			{
				continue;
			}
			else
			{
				throw "Wrong date format: " + s;
			}
		}
		else
		{
			throw "Wrong date format: " + s;
		}
	}
}

void CheckFormatDateAndChangeValues(const string& s, int& nyear, int& nmonth, int& nday)
{
	string snyear, snmonth, snday;
	nyear = s.find('-', 1);
	nmonth = s.find('-', nyear + 1);
	if (nmonth == nyear + 1)
		nmonth = s.find('-', nyear + 2);
	nday = s.size();

	try {
		if (nmonth < 1 || nyear < 1 || nday < 1)
		{
			throw "Wrong date format: " + s;
		}

		CheckIsDigit(s, snyear, nyear, 0);
		CheckIsDigit(s, snmonth, nmonth, nyear + 1);
		CheckIsDigit(s, snday, nday, nmonth + 1);
		if(snyear == "" || snmonth == "" || snday == "")
		{
			throw "Wrong date format: " + s;
		}

		nyear = stoi(snyear);
		nmonth = stoi(snmonth);
		nday = stoi(snday);

		if (nmonth > 12 || nmonth < 1)
			throw 1;
		if (nday > 31 || nday < 1)
			throw 2;
	}
	catch (int i) {
		if (i == 1)
		{
			throw "Month value is invalid: " + snmonth;
		}
		else if (i == 2)
		{
			throw "Day value is invalid: " + snday;

		}
	}
	catch (...)
	{
		throw;
	}
}

int main()
{
	Database db;

	string command;

	while (getline(cin, command))
	{

		if (command.find("Add ") == 0)
		{
			int a = command.find(' ', 4), nyear, nmonth, nday;
			string s, event;

			for (int i = a + 1; i < command.size(); i++) //event
			{
				event += command[i];
			}

			for (int i = 4; i < a; i++) //date
			{
				s += command.at(i);
			}
			try {
				CheckFormatDateAndChangeValues(s, nyear, nmonth, nday);
				db.AddEvent({ nyear, nmonth, nday }, event);
			}
			catch (string ex)
			{
				cout << ex << endl;
				return 0;
			}
			catch (...)
			{
			}
		}
		else if (command.find("Del ") == 0)
		{
			int a = command.find(' ', 4), nyear, nmonth, nday;
			string s, event = "";
			if (a > 0)
			{
				for (int i = a + 1; i < command.size(); i++)
				{
					event += command[i]; //event to del
				}
			}
			else
			{
				a = command.size();
			}

			for (int i = 4; i < a; i++) //format date
			{
				s += command.at(i);
			}
			try {
				CheckFormatDateAndChangeValues(s, nyear, nmonth, nday);
				if (event != "")
				{
					if (db.DeleteEvent({ nyear, nmonth, nday }, event))
					{
						cout << "Deleted successfully" << endl;
					}
					else
					{
						cout << "Event not found" << endl;
					}

				}
				else
				{
					cout << "Deleted " + to_string(db.DeleteDate({ nyear,nmonth,nday })) + " events" << endl;
				}
			}
			catch (string ex)
			{
				cout << ex << endl;
				return 0;
			}
			catch (...)
			{
			}
		}
		else if (command.find("Find ") == 0)
		{
			int a = command.size(), nyear, nmonth, nday;
			string s;
			for (int i = 5; i < a; i++)
			{
				s += command.at(i);
			}
			try {
				CheckFormatDateAndChangeValues(s, nyear, nmonth, nday);
				db.Find({ nyear, nmonth, nday });
			}
			catch (string ex)
			{
				cout << ex << endl;
				return 0;
			}
			catch (...)
			{
			}
		}
		else if (command.find("Print") == 0 && command.size() == 5)
		{
			db.Print();
		}
		else if (command == "")
		{
			continue;
		}
		else
		{
			string err;
			for (const auto& chars : command)
			{
				if (chars != ' ')
					err += chars;
				else
					break;
			}
			cout << "Unknown command: " << err << endl;
			return 0;
		}

	}



	return 0;
}
