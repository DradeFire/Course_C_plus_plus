#include <iostream>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int NOD(int numerator, int denominator)
    {
        if (numerator == 0 || denominator == 0)
            return numerator + denominator;
        if (numerator > denominator)
            return NOD(numerator - denominator, denominator);
        else
            return NOD(numerator, denominator - numerator);
    }

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
           
        if (denominator == 0)
            throw invalid_argument("");
        if (numerator == 0)
                        {
                            num = 0;
                            den = 1;
                            return;
                        }
                        if (numerator * denominator < 0)
                        {
                            numerator = -abs(numerator);
                            denominator = abs(denominator);
                        }
                        else
                        {
                            numerator = abs(numerator);
                            denominator = abs(denominator);
                        }
                        int divv = NOD(abs(numerator), abs(denominator));

                        num = numerator / divv;
                        den = denominator / divv;
    }


    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num, den;
};

bool operator==(const Rational& larg, const Rational& rarg)
{
    if (larg.Numerator() == rarg.Numerator() && larg.Denominator() == rarg.Denominator())
        return true;
    else
        return false;
}

Rational operator+(const Rational& larg, const Rational& rarg)
{
    if (larg.Denominator() == rarg.Denominator())
        return Rational(larg.Numerator() + rarg.Numerator(), larg.Denominator());
    else
    {
        int tmp_mul = larg.Denominator() * rarg.Denominator();
        return Rational(larg.Numerator() * rarg.Denominator() + rarg.Numerator() * larg.Denominator(), tmp_mul);
    }
}

Rational operator-(const Rational& larg, const Rational& rarg)
{
    if (larg.Denominator() == rarg.Denominator())
        return Rational(larg.Numerator() - rarg.Numerator(), larg.Denominator());
    else
    {
        int tmp_mul = larg.Denominator() * rarg.Denominator();
        return Rational(larg.Numerator() * rarg.Denominator() - rarg.Numerator() * larg.Denominator(), tmp_mul);
    }
}

Rational operator*(const Rational& larg, const Rational& rarg)
{
    int lnum = larg.Numerator(),
        rnum = rarg.Numerator(),
        lden = larg.Denominator(),
        rden = rarg.Denominator();
    int nod1 = NOD(abs(lnum), rden);
    int nod2 = NOD(abs(rnum), lden);
    return Rational((lnum/nod1) * (rnum/nod2), (lden/nod2) * (rden/nod1));
}

Rational operator/(const Rational& larg, const Rational& rarg)
{
    try {
        int lnum = larg.Numerator(),
            rnum = rarg.Numerator(),
            lden = larg.Denominator(),
            rden = rarg.Denominator();
        if (rnum == 0)
            throw exception();
        int nod1 = NOD(abs(lnum), abs(rnum));
        int nod2 = NOD(lden, rden);
        return Rational((lnum / nod1) * (rden / nod2), (lden / nod2) * (rnum / nod1));
    }
    catch (exception&)
    {
        throw domain_error("");
    }
}

bool operator<(const Rational& larg, const Rational& rarg)
{
    int lnum = larg.Numerator(),
        rnum = rarg.Numerator(),
        lden = larg.Denominator(),
        rden = rarg.Denominator();
    if (lnum * rden < rnum * lden)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& stream, const Rational& rat)
{
    try {
        stream << rat.Numerator() << '/' << rat.Denominator();
    }
    catch (domain_error&)
    {
        throw domain_error("");
    }
    return stream;
}

istream& operator>>(istream& stream, Rational& rat)
{
    int num, den;
    char check;

    if ((stream >> num) && (stream >> check) && (stream >> den))
    {
        if (check == '/')
        {
            try {
                Rational r(num, den);
                rat = r;
            }
            catch (invalid_argument&) {
                throw invalid_argument("");
            }

        }
    }
    return stream;
}

Rational Calc(const Rational& larg, const Rational& rarg, const char& oper)
{
    if (oper == '+')
    {
            return larg + rarg;
    }
    else if (oper == '-')
    {
        return larg - rarg;
    }
    else if (oper == '*')
    {
        return larg * rarg;
    }
    else if (oper == '/')
    {
        try {
            return larg / rarg;
        }
        catch (domain_error&) {
            throw domain_error("");
        }
    }
}

int main() {
    Rational a, b;
    char oper;
    try {
        cin >> a >> oper >> b;
    }
    catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
        return 0;
    }

    try {
        cout << Calc(a, b, oper) << endl;
    }
    catch (domain_error&)
    {
        cout << "Division by zero" << endl;
        return 0;
    }


    return 0;
}
