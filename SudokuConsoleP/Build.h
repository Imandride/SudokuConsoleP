#pragma once
#include "stdafx.h"
#include "Position.h"


using namespace std;

class Position;

//typedef shared_ptr<Position> shared_ptr<Position>;
typedef _Simple_types<std::pair<const int, std::shared_ptr<Position>>>::value_type P_P;

class Build
{
public:
	
	map<int, R_P> row_op_map;
	map<int, C_P> col_op_map;
	map<int, B_P> block_op_map;
	
	static map<int, shared_ptr<Position>> set_positions;
	static R_P active_row;
	static C_P active_column;
	static B_P active_block;
	static shared_ptr<Position> active_pos_ptr;
	static int active_int_pos_ptr;
	static set<pair<const int, shared_ptr<Position>>>::iterator active_pIter;
	 

	void setrcb_objects();

	void buildVec(vector<int>& Sud);

	void read_VecI(vector<int> vec);

	void set_active(set<pair<const int, shared_ptr<Position>>>::iterator & p);

	//void reset_active();

	void set_rcb_pos();

	//void delete_pointer_position(set<pair<const int, shared_ptr<Position>>>::iterator &p);

	void remove_available_pos();

	void delete_position();

	bool delete_check_zero();
	bool delete_check_zero_again();
	void check_initial_positions();
	void check_remaining_zero();
	void solve_for_zero();

	void read_set_positions();
	Build();
	~Build();
};
