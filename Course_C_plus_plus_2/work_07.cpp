#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

template <class Key, class Value, class T>
Value& GetRefStrict(map<Key, Value>& arg, T k) {
    if (arg.count(k) == 0) {
        throw runtime_error("");
    }
    return arg.at(k);
}