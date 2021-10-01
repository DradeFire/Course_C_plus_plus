#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> vect(N);
    for (int i = 0; i < N; i++)
    {
        vect.at(i) = N - i;
    }
    do {
        for (auto&& element : vect)
            std::cout << element << " ";
        std::cout << std::endl;
    } while (std::prev_permutation(std::begin(vect), std::end(vect)));
   
    return 0;
}