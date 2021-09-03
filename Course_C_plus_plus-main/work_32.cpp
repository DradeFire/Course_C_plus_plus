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

    int line;
    int N, M;
    //cout << setw(10);
    
    input >> N;
    input.ignore(1);
    
    input >> M;
    input.ignore(1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            input >> line;
            input.ignore(1);
            if (j == M - 1)
            {
                cout << setw(10) << line;
            }
            else
            {
                cout << setw(10) << line << ' ';
            }
        }
        if (i != N - 1)
            cout << endl;
    }

    
    return 0;
}
