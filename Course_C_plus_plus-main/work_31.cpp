#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    double tmp_d;
    cout << fixed << setprecision(3);
    while (input >> tmp_d)
    {
        cout << tmp_d << endl;
    }

    return 0;
}
