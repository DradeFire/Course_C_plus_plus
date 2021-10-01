#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <numeric>
#include <iterator>
#include <functional>
#include <deque>
#include <sstream>
#include <memory>
#include <math.h>

using namespace std;

const double PI = 3.14;

class Figure {
public:
    Figure(const string& name_) 
        : name(name_) { 

    }

    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

protected:
    const string name;
};

class Triangle : public Figure {
public:
    Triangle(const string& name_, const int& a_, const int& b_, const int& c_) 
        : Figure(name_), a(a_), b(b_), c(c_) {

    }

    string Name() const override {
        return name;
    }
    double Perimeter() const override {
        return a + b + c;
    }
    double Area() const override {
        double p = (a + b + c) / 2.0;
        double k = sqrt(p * (p - a) * (p - b) * (p - c));
        return k;
    }

private:
    const int a, b, c;
};

class Rect : public Figure {
public:
    Rect(const string& name_, const double& width_, const double& height_) 
        : Figure(name_), width(width_), height(height_) {

    }

    string Name() const override {
        return name;
    }
    double Perimeter() const override {
        return 2 * width + 2 * height;
    }
    double Area() const override {
        return width * height;
    }

private:
    const double width, height;
};

class Circle : public Figure {
public:
    Circle(const string& name_, const int& rad_) : Figure(name_), r(rad_) {

    }

    string Name() const override {
        return name;
    }
    double Perimeter()  const override {
        return 2 * PI * r;
    }
    double Area() const override {
        return PI * r * r;
    }

private:
    const int r;
};

shared_ptr<Figure> CreateFigure(istringstream& stream) {
    string fig;
    stream >> fig;
    if (fig == "RECT") {
        double width, height;
        stream >> width >> height;
        return make_shared<Rect>(fig, width, height);
    }
    else if (fig == "TRIANGLE") {
        int a, b, c;
        stream >> a >> b >> c;
        return make_shared<Triangle>(fig, a, b, c);
    }
    else { //CIRCLE
        int r;
        stream >> r;
        return make_shared<Circle>(fig, r);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}