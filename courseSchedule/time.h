//时间结构

#include "stdafx.h"

class Time
{
	friend class Timetable;
public:
	Time(){}
	Time(int id, std::string name, int lesson):id(id),name(name), lesson(lesson){}

private:
	int id;
	std::string name;
	int lesson;
};