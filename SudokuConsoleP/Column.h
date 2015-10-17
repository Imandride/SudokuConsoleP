#pragma once
#include <set>

class Position;

class Column
{
protected:
	int column = 0;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};


	std::set<Position*> positions_incol_set;
	Column() = delete;
public:
	//std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<int>>>begin()
//	{
	//	return available_in_IS.begin();
//	};

	std::set<int>* available_in_CIS();

	void read_availablein();

	void column_positions(Position*);

	const int& getcol();
	
	void readcolumn();

	void remove(int a);

	explicit Column(int key);

	~Column();
};
