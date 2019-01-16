#pragma once
#include <iostream>
#include <list>

class Cell
{
public:
	Cell();
	~Cell();

	std::list <Cell> cellList;

private:
	int state; //stan
	int time; //czas bycia odporn¹
};


