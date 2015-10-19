#pragma once
#include "Build.h"
using namespace std;

class Build;

class Column
{
protected:
	int column = 0;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	std::set<int>* available_in_CIS();
	std::set<std::shared_ptr<Position>> positions_in_PS;
	Column() = delete;
public:
	void read_availablein();

	void column_positions();

	const int& getcol();

	void readcolumn();

	void delete_pointer_position();

	void remove(int a);

	explicit Column(int key);

	~Column();
};
