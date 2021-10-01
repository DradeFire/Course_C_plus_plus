#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T x);

template <typename Key, typename Value> 
map<Key, Value> operator*(const map<Key, Value>& larg, const map<Key, Value>& rarg);
template <typename Vect> 
vector<Vect> operator*(const vector<Vect>& larg, const vector<Vect>& rarg);
template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& larg, const pair<First, Second>& rarg);

// Объявляем шаблонные функции
template <typename T>
T Sqr(T x) {
    return x * x;
}

template <typename Vect>
vector<Vect> operator*(const vector<Vect>& larg, const vector<Vect>& rarg) {
    vector<Vect> tmp;
    for (size_t i = 0; i < larg.size(); i++)
    {
        tmp.push_back(larg.at(i) * rarg.at(i));
    }
    return tmp;
}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& larg, const pair<First, Second>& rarg) {
    First f = larg.first * rarg.first;
    Second s = larg.second * rarg.second;
    return make_pair(f, s);
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& larg,const map<Key, Value>& rarg) {
    map<Key, Value> tmp;
    for (const auto& item_l : larg) {
        for (const auto& item_r : rarg) {
            if (item_l.first == item_r.first) {
                tmp[item_l.first] = larg.at(item_l.first) * rarg.at(item_r.first);
            }
        }
    }
    
    return tmp;
}

int main() {
    
    // Пример вызова функции
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}