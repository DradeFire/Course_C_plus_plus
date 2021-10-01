#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

template <typename RandomIt>
void MergeSort1(RandomIt range_begin, RandomIt range_end);
template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end);

template <typename RandomIt>
void MergeSort1(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2)
        return;

    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    
    MergeSort1(elements.begin(), elements.begin() + (elements.end() - elements.begin()) / 2);
    MergeSort1(elements.begin() + (elements.end() - elements.begin()) / 2, elements.end());

    merge(elements.begin(), elements.begin() + (elements.end() - elements.begin()) / 2, elements.begin() + (elements.end() - elements.begin()) / 2, elements.end(), range_begin);
}


template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2)
        return;

    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    MergeSort2(elements.begin(), elements.begin() + (elements.end() - elements.begin()) / 3);
    MergeSort2(elements.begin() + (elements.end() - elements.begin()) / 3, elements.begin() + 2 * (elements.end() - elements.begin()) / 3);
    MergeSort2(elements.begin() + 2 * (elements.end() - elements.begin()) / 3, elements.end());


    vector<typename RandomIt::value_type> tmpvect;

    merge(elements.begin(), elements.begin() + (elements.end() - elements.begin()) / 3, elements.begin() + (elements.end() - elements.begin()) / 3, elements.begin() + 2 * (elements.end() - elements.begin()) / 3, back_inserter(tmpvect));

    merge(tmpvect.begin(), tmpvect.end(), elements.begin() + 2 * (elements.end() - elements.begin()) / 3, elements.end(), range_begin);

}

int main() {
    vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
    vector<int> v2 = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
    MergeSort1(begin(v1), end(v1));
	MergeSort2(begin(v2), end(v2));
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;
	for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}