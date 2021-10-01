#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};
/*
bool IsPalindrom(const string& str) {

}
*/
void Test1() {
    Assert(IsPalindrom({}), "test#1");
}

void Test2() {
    Assert(IsPalindrom("1 ,2<3 3<2, 1"), "test#2");
}

void Test3() {
    Assert(IsPalindrom(",./*Gf!@#$%^&?(){}-_`'<>10 : : 01><'`_-}{)(?&^%$#@!fG*/.,"), "test#3");
}

void Test4() {
    Assert(!IsPalindrom("Amama"), "test#4");
}

void Test5() {
    Assert(!IsPalindrom("fgddg4"), "test#5");
}

void Test6() {
    Assert(IsPalindrom("Adinida deified deified adinidA"), "test#6");
}

void Test7() {
    Assert(IsPalindrom("G"), "test#7");
}

void Test8() {
    Assert(!IsPalindrom("WASITACARoracatisaw"), "test#8");
}

void Test9() {
    Assert(IsPalindrom("                                                                           "), "test#9");
}

void Test10() {
    Assert(!IsPalindrom("                                  gf                                   "), "test#10");
}

void Test11() {
    Assert(!IsPalindrom("adinida dei fied dei fied adi ni da"), "test#11");
}

void Test12() {
    Assert(IsPalindrom("ff"), "test#12");
}

void Test13() {
    Assert(!IsPalindrom("fF"), "test#13");
}

void Test14() {
    Assert(!IsPalindrom("Adinida deified deified  adinidA"), "test#14");
}

void TestAll() {
    TestRunner r;
    r.RunTest(Test1, "Test1");
    r.RunTest(Test2, "Test2");
    r.RunTest(Test3, "Test3");
    r.RunTest(Test4, "Test4");
    r.RunTest(Test5, "Test5");
    r.RunTest(Test6, "Test6");
    r.RunTest(Test7, "Test7");
    r.RunTest(Test8, "Test8");
    r.RunTest(Test9, "Test9");
    r.RunTest(Test10, "Test10");
	r.RunTest(Test11, "Test11");
	r.RunTest(Test12, "Test12");
	r.RunTest(Test13, "Test13");
}

int main() {
    TestAll();
    return 0;
}