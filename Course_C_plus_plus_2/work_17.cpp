#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
vector<string> SplitIntoWords(const string& s);

vector<string> SplitIntoWords(const string& s) {
    vector<string> tmpstr;
    auto it1 = s.begin(), it = s.begin();
    int i = 0;
    
    if (s.find(' ') < 0) {
        tmpstr.push_back({ it1,s.end() });
        return tmpstr;
    }

    while (1) {
        if (s.find(' ', i) != -1) {
            it += -i + s.find(' ', i);
            tmpstr.push_back({ it1,it });
            i = s.find(' ', i) + 1;
            it1 = ++it;
            
        }
        else {
            tmpstr.push_back({ it,s.end() });
            return tmpstr;
        }
    }
    return tmpstr;
}

int main() {
    string s = "C Cpp Java Python";
    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }

        cout << *it;
    }
    cout << endl;

    return 0;
}
