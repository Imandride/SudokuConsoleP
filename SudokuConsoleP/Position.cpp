#pragma once
#include "Position.h"


Position::Position(std::vector<int>& build_vector)
{
	std::vector<int> vtest_vector{0,0,0,8,9,0,0,7,0,0,4,0,1,7,0,9,0,3,9,6,0,0,4,2,1,0,0,0,9,0,4,0,0,5,0,0,5,0,0,0,6,0,2,0,7,0,1,4,5,2,0,0,8,9,0,0,0,0,0,3,7,1,2,0,0,6,2,8,9,0,3,0,2,5,3,0,0,0,0,0,6};
	for (auto i: vtest_vector)
	{
		printf("%d ", i);
	}

	printf("\n");
	build_vector = vtest_vector;
}

Position::Position(int nPos, std::vector<int>::const_iterator p): cnPos(nPos), iter_pos_vect(p)
{
	printf("Constructor for position %d called:\n", nPos);
}

R_P& Position::return_active_ptr(R_P)
{
	return row_;
}

B_P& Position::return_active_ptr(B_P)
{
	return block_;
}

int& Position::return_active_ptr(int)
{
	return cnPos;
}

int Position::return_active_int()
{
	return cnPos;
}

C_P& Position::return_active_ptr(C_P)
{
	return column_;
}

void Position::read_availablein()
{
	printf("Positions in Row:\n");
	row_->read_availablein();
	printf("\n");
	printf("Positions in Column:\n");
	column_->read_availablein();
	printf("\n");
	printf("Positions in Block:\n");
	block_->read_availablein();
	printf("\n");
	printf("\n");
}

void Position::solve_set_address_RCB(std::map<int, R_P>& ropr, std::map<int, C_P>& copr, std::map<int, B_P>& bopr)
{
	int row = cnPos / 9;
	int columb = cnPos % 9;
	int block = ((row / 3) * 3 + columb / 3);

	row_ = ropr.at(row);
	column_ = copr.at(columb);
	block_ = bopr.at(block);
}


const int& Position::get_vector_value()
{
	return *iter_pos_vect;
}

void Position::delete_available_pos(int i)
{
	available_pos_is.erase(i);
}


Position::~Position()
{
	printf("Destructor called:\n");
}
