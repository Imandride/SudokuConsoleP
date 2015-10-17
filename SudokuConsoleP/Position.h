#pragma once
#include "Row.h"
#include "Column.h"
#include "Block.h"
#include <vector>
#include <set>


class Position
{
	int r = 0; 	
	int c = 0; 
	int b = 0; 
	Row* row_; 
	Column* column_;
	Block* block_;
	const int cnPos = 0; 
	std::vector<int>::const_iterator vector_const_iterator_p; 
	std::set<int> available_pos_is{1,2,3,4,5,6,7,8,9};
	Position() = delete;
public:

	void read_availablein();


	Row*& row();
	Column*& column();
	Block*& block();

	void row(Row*);
	void column(Column*);
	void block(Block*);

	const int& cn_pos();

	const int& get_vector_value();

	void solve_Positionrcb();

	void delete_available_pos(int i);

	const int& Rr();
	const int& Rc();
	const int& Rb();

	explicit Position(std::vector<int>& build_vector);

	explicit Position(int nPos, std::vector<int>::const_iterator p);
	~Position();
};
