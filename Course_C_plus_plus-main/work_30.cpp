#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    
    ifstream input("input.txt");

    const string path = "output.txt";
    ofstream output(path);

    string line;
    while (getline(input, line))
    {

        output << line << endl;

    }

    return 0;
}
