#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Function {
public:
    void AddPart(char op, double val)
    {
        parts.push_back({ op, val });
    }
    double Apply(double s_val) const
    {
        for (const FunPart& item : parts)
        {
            s_val = item.Apply(s_val);
        }
        return s_val;
    }
    void Invert()
    {
        for (FunPart& item : parts)
            item.Invert();
        reverse(begin(parts), end(parts));
    }
private:
    struct FunPart{
        FunPart(char new_op, double new_val) {
            op = new_op;
            val = new_val;
        }
        double Apply(double s_val) const {
            if (op == '+')
                return s_val + val;
            else
                return s_val - val;
        }
        void Invert()
        {
            if (op == '+')
                op = '-';
            else
                op = '+';
        }

        char op;
        double val;
    };
    vector<FunPart> parts;
};
