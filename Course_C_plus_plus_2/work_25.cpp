#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <numeric>
#include <iterator>
#include <functional>
#include <deque>

std::string ArithmFunc(int x, int N) {
    std::deque<std::string> tmp;
    if (N == 0)
        return std::string(std::to_string(x));

    tmp.push_back(std::to_string(x));
    
    std::string retStr, backStr;

    for (int i = 0; i < N; i++) {
        std::string tmpStr;
        int tmpInt;
        std::cin >> tmpStr >> tmpInt;

            if (i == 0) {
                tmp.push_back(" " + tmpStr + " " + std::to_string(tmpInt));
            }
            else if ((tmpStr == "*" || tmpStr == "/") && (backStr.size() > backStr.find("+") || backStr.size() > backStr.find("-"))) {
                tmp.push_front("(");
                tmp.push_back(") " + tmpStr + " " + std::to_string(tmpInt));
            }
            else {
                tmp.push_back(" " + tmpStr + " " + std::to_string(tmpInt));
            }
            backStr = tmpStr;
    }



    for (const auto& item : tmp) {
        retStr += item;
    }

    return retStr;
}

int main() {
    int x, N;
    std::cin >> x >> N;

    std::cout << std::string(ArithmFunc(x, N)) << std::endl;

    return 0;
}