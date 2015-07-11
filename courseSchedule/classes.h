//°à¼¶½á¹¹

#include "stdafx.h"

class Class
{
	friend class Timetable;
public:
	Class(){S=0;}
	Class(int id, std::string department, std::string name, int totPeople):id(id),department(department),name(name),totPeople(totPeople){S=0;}

private:
	void insertSubjects(int s) { Subjects.push_back(s);S++;}

	int id;
	std::string department;
	std::string name;
	int totPeople;
	std::vector<int> Subjects;
	int S;
};