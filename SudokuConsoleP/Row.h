#pragma once
#include "Position.h"

class Position;

class Row 
{
protected:
	int row = 0;
	std::set<Position*> positions_inrow_set;
	Row() = delete;
public:
	std::set<int> available_in_is{1,2,3,4,5,6,7,8,9};
	void row_positions(Position*);
	const int& getrow();

	void read_available_in();
	void remove(int a);
	explicit Row(int key);
	~Row();
};
