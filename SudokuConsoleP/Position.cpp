#pragma once
#include "Position.h"
#include "stdafx.h"


Position::Position(std::vector<int>& build_vector)
{
	std::vector<int> vtest_vector{0,0,0,8,9,0,0,7,0,0,4,0,1,7,0,9,0,3,9,6,0,0,4,2,1,0,0,0,9,0,4,0,0,5,0,0,5,0,0,0,6,0,2,0,7,0,1,4,5,2,0,0,8,9,0,0,0,0,0,3,7,1,2,0,0,6,2,8,9,0,3,0,2,5,3,0,0,0,0,0,6};
	//Temporary vec definition.
	for (std::vector<int>::iterator i = vtest_vector.begin(); i != vtest_vector.end(); ++i)
	{
		printf("%d ", *i); //printing vec sequentially
	}
	printf("\n");
	build_vector = vtest_vector; //currently indirectly setting vector will optimize later.
}

Position::Position(int nPos, std::vector<int>::const_iterator p): cnPos(nPos), vector_const_iterator_p(p)
{
	printf("constructor for position %d called: %d\n", nPos, nPos);
} //constructor for a new position object

void Position::read_availableinr()
{
	for (auto iter : row_->available_in_is)
		printf("%d, ", iter);

}

void Position::read_availableinc()
{
	for (auto iter : column_->available_in_is)
		printf("%d, ", iter);

}

void Position::read_availableinb()
{
	for (auto iter : block_->available_in_is)
		printf("%d, ", iter);

}

void Position::row(Row* rp)
{
	row_ = rp;
	
}

void  Position::column(Column* cp)
{
	column_ = cp;

}

void  Position::block(Block* bp)
{
	block_ = bp;

}

int Position::cn_pos() const
{
	return cnPos;
}

void Position::solve_Positionrcb()
{
	r = cnPos / 9;
	c = cnPos % 9;
	b = ((r / 3) * 3 + c / 3);
}
const int& Position::r1()
{
	return r;
}

const int& Position::c1()
{
	return c;
}

const int& Position::b1()
{
	return b;
}

Position::~Position()
{
	printf("Destructor called:\n");
}
