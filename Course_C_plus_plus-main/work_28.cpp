#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

struct Specialization {
	string spec;
	explicit Specialization(string s)
	{
		spec = s;
	}
};
struct Course {
	string cour;
	explicit Course(string c)
	{
		cour = c;
	}
};
struct Week {
	string week;
	explicit Week(string w)
	{
		week = w;
	}
};

struct LectureTitle {
	
	LectureTitle(Specialization spec, Course cour, Week weekk)
	{
		specialization = spec.spec;
		course = cour.cour;
		week = weekk.week;
	}

	string specialization;
	string course;
	string week;
};
