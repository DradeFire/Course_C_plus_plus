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
class Rational {
public:
    Rational();
    Rational(int numerator, int denominator) {
    }

    int Numerator() const {
    }

    int Denominator() const {
    }
};
*/
void Test1() { //Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
    Rational rat;
    Assert(rat.Numerator() == 0 && rat.Denominator() == 1, "Test#1");
}

//При конструировании объекта класса Rational с параметрами 
//p и q должно выполняться сокращение дроби p/q. 
void Test2() {   
    Rational rat(50, 175);
    Assert(rat.Numerator() == 2 && rat.Denominator() == 7, "Test#2");
}

//Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель 
//и положительный знаменатель.
void Test3() { 
    Rational rat(5, -7);
    Assert(rat.Numerator() == -5 && rat.Denominator() == 7, "Test#3");
}

//Если дробь p / q положительная, то объект Rational(p, q) должен иметь положительные числитель 
//и знаменатель(обратите внимание на случай Rational(-2, -3)).
void Test4() {
    Rational rat(-5, -7);
    Assert(rat.Numerator() == 5 && rat.Denominator() == 7, "Test#4");
}

//Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
void Test5() {
    Rational rat(0, -7);
    Assert(rat.Numerator() == 0 && rat.Denominator() == 1, "Test#5");
}

void TestAll() {
    TestRunner r;
    r.RunTest(Test1, "Test1"); 
    r.RunTest(Test2, "Test2"); 
    r.RunTest(Test3, "Test3");
    r.RunTest(Test4, "Test4");
    r.RunTest(Test5, "Test5");
}

int main() {
    TestAll();
    return 0;
}