#pragma once
class Position;

class Column
{
protected:
	int column = 0;
	
	std::set<Position*> positions_incol_set;
	Column() = delete;
public:
	std::set<int> available_in_is{1,2,3,4,5,6,7,8,9};
	void column_positions(Position*);

	const int& getcol();

	void read_available_in();

	void remove(int a);

	explicit Column(int key);

	~Column();
};
