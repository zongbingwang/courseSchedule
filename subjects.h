//¿ÎÌÃ½á¹¹

#include "stdafx.h"

class Subject
{
	friend class Timetable;
public:
	Subject(){}
	Subject(int id, int class_id, std::string name, int tot_lesson, int week_lesson, int teacher_id):
		id(id),class_id(class_id), name(name),tot_lesson(tot_lesson), week_lesson(week_lesson), teacher_id(teacher_id){}

private:
	int id;
	int class_id;
	std::string name;
	int tot_lesson;
	int week_lesson;
	int teacher_id;
};