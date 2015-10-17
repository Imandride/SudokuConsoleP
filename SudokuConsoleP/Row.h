#pragma once
#include <set>

class Position;

class Row
{
protected:
	int row = 0;
	Row() = delete;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	std::set<Position*> positions_in_PS;
public:
	std::set<int>* available_in_RIS();
	void row_positions(Position*);
	const int& getrow();
	void readrow();
	void read_availablein();
	void remove(int a);
	explicit Row(int key);
	~Row();
};
