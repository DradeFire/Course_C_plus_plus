#include <iostream>
#include <string>
#include <vector>
#include <memory>
//#include <iomanip>
//#include <set>
//#include <algorithm>
//#include <map>
//#include <numeric>
//#include <iterator>
//#include <functional>
//#include <deque>
//#include <sstream>
//#include <math.h>

class People {
public:
    People(const std::string& name, const std::string& prof) : Name(name) , Prof(prof) {

    }

    virtual void Walk(const std::string& destination) const {
        std::cout << Prof << ": " << Name << " walks to: " << destination << std::endl;
    }

    virtual void Check(const People& p) const {
        std::cout << "It's not Policeman!" << std::endl;
    }

    const std::string Name;
    const std::string Prof;
};


class Student : public People {
public:

    Student(std::string name, std::string favouriteSong) : People(name, "Student"), FavouriteSong(favouriteSong) {
    }

    void Learn() const {
        std::cout << "Student: " << Name << " learns" << std::endl;
    }

    void Walk(const std::string& destination) const override {
        std::cout << "Student: " << Name << " walks to: " << destination << std::endl;
        std::cout << "Student: " << Name << " sings a song: " << FavouriteSong << std::endl;
    }

    void SingSong() const {
        std::cout << "Student: " << Name << " sings a song: " << FavouriteSong << std::endl;
    }

    const std::string FavouriteSong;
};


class Teacher : public People {
public:

    Teacher(const std::string name, const std::string subject) : People(name, "Teacher"), Subject(subject) {
        
    }

    void Teach() const {
        std::cout << "Teacher: " << Name << " teaches: " << Subject << std::endl;
    }

    const std::string Subject;
};


class Policeman : public People {
public:
    Policeman(const std::string& name) : People(name, "Policeman") {
    }

    void Check(const People& p) const override {
        std::cout << "Policeman: " << Name << " checks " << Prof << ". " << Prof << "'s name is : " << Name << std::endl;
    }
};


void VisitPlaces(const People& peop, std::vector<std::string> places) {
    for (auto p : places) {
        peop.Walk(p);
    }
}

int main() {
    std::vector<std::shared_ptr<People>> peop{
        std::make_shared<Teacher>("Jim", "Math"),
        std::make_shared<Student>("Ann", "We will rock you"),
        std::make_shared<Policeman>("Bob")
    };

    VisitPlaces(*(peop.at(0)), { "Moscow", "London" });
    peop.at(2)->Check(*(peop.at(1)));
    VisitPlaces(*(peop.at(1)), { "Moscow", "London" });
    return 0;
}