#pragma once
#include <vector>
#include <set>
#include "Row.h"
#include "Column.h"
#include "Block.h"


class Position
{
	int r = 0; // row	
	int c = 0; // column
	int b = 0; // block
	Row* row_;
	Column* column_;
	Block* block_;
	const int cnPos = 0; //position
	std::vector<int>::const_iterator vector_const_iterator_p; // address of iteration of vector in which position resides
	std::set<int> available_pos_is{1,2,3,4,5,6,7,8,9};
	Position() = delete;
public:

	void read_availableinr();

	void read_availableinc();

	void read_availableinb();

	void row(Row*);

	void column(Column*);

	void block(Block*);

	int cn_pos() const;

	void solve_Positionrcb();

	const int& r1();

	const int& c1();

	const int& b1();

	explicit Position(std::vector<int>& build_vector);

	explicit Position(int nPos, std::vector<int>::const_iterator p);
	~Position();
};
