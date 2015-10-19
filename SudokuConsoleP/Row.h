#pragma once

#include "Build.h"
using namespace std;

class Build;

class Row
{
protected:
	int row = 0;
	Row() = delete;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	std::set<std::shared_ptr<Position>> positions_in_PS;
	std::set<int>* available_in_RIS();
public:
	void row_positions();
	const int& getrow();
	void readrow();
	void read_availablein();
	void remove_availablein(int a);
	void delete_pointer_position();
	explicit Row(int key);
	~Row();
};
