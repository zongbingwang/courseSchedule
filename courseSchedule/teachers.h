//教师结构

#include "stdafx.h"

class Teacher
{
	friend class Timetable;
public:
	Teacher(){S=0;}
	Teacher(int id, std::string name):id(id),name(name){S=0;}

private:
	void insertSubjects(int s) { Subjects.push_back(s);S++;}

	int id;
	std::string name;
	std::vector<int> Subjects;
	int S;
};