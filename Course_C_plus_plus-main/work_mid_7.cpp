#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;

struct Person {
    string firstname,lastname;
    int day, month, year;
};

class DB_Persons {
public:
    DB_Persons()
    {
        if(CreatePersons())
            ShowInfoPersons();
    }
    bool CreatePersons()
    {
        int N;
        vector<Person> tmp_persons;
        cin >> N;
        if (CheckNM(N))
        {
            cout << "bad request" << endl;
            return false;
        }
        for (int i = 0; i < N; i++)
        {
            
            string fname, lname; 
            int new_day, new_month, new_year;
            cin >> fname >> lname >> new_day >> new_month >> new_year;
            if (CheckName(fname, lname) || CheckDate(new_day, new_month, new_year))
            {
                cout << "bad request" << endl;
                return false;
            }

            tmp_persons.push_back({fname,lname,new_day,new_month,new_year});
        }
        for (const auto& pers : tmp_persons)
        {
            persons.push_back(pers);
        }
        return true;
    }
    void ShowInfoPersons()
    {
        int M;
        cin >> M;
        string cinstr;
        if (CheckNM(M))
        {
            cout << "bad request" << endl;
            return;
        }
        for (size_t i = 0; i < M; i++)
        {
            cin >> cinstr;

            int K;
            cin >> K;
            if (K < 1 || K > persons.size())
            {
                cout << "bad request" << endl;
                continue;
            }
            if (cinstr == "name")
            {
                cout << persons[K - 1].firstname << " " << persons[K - 1].lastname << endl;
            }
            else if (cinstr == "date")
            {
                cout << persons[K - 1].day << '.' << persons[K - 1].month << '.' << persons[K - 1].year << endl;
            }
            else
            {
                cout << "bad request" << endl;
            }
        }
    }
private:
    bool CheckNM(int NM)
    {
        if (NM > 10000 || NM < 0)
            return true;
        else
            return false;
    }
    bool CheckName(string fname, string lname)
    {
        if (fname.size() > 15 || fname.size() < 1 || lname.size() > 15 || lname.size() < 1)
            return true;
        else
            return false;
    }
    bool CheckDate(int day, int month, int year)
    {
        if (day > 1000000000 || day < 0 || month > 1000000000 || month < 0 || year > 1000000000 || year < 0)
            return true;
        else
            return false;
    }
    vector<Person> persons;
};

int main() {

    DB_Persons pers;

    return 0;
}
