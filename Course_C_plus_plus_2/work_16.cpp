#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border);

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    set <T> tmpset;
    vector<T> tmpvect;
    auto it = elements.begin();
    while (it != elements.end())
    {
        if (*it > border) {
            tmpset.insert(*it);
        }
        it++;
    }

    for (const auto& item : tmpset) {
        tmpvect.push_back(item);
    }
    return tmpvect;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;
    
    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}