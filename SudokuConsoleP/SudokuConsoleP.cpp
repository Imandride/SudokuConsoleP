// SudokuConsoleP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"



int active_key;

int main(int argc, char* argv[])
{
	unique_ptr<Build> build(new Build());

	build->setrcb_objects();
	vector<int> Sud;
	build->buildVec(Sud);
	build->buildVec(Sud);
	build->set_rcb_pos();
	build->check_initial_positions();
	build->check_remaining_zero();
	

	//read_set_positions();
	//read_VecI(Sud);

	cin.get();
	return 0;
}
