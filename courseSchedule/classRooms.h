//¿ÎÌÃ½á¹¹

#include "stdafx.h"

class ClassRoom
{
	friend class Timetable;
public:
	ClassRoom(){}
	ClassRoom(int id, std::string name, int capacity):id(id),name(name),capacity(capacity){}

private:
	int id;
	std::string name;
	int capacity;
};