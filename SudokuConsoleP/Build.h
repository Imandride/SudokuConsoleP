#pragma once
#include "stdafx.h"
#include "Position.h"

using namespace std;


typedef shared_ptr<Position> P_PR;
typedef _Simple_types<std::pair<const int, std::shared_ptr<Position>>>::value_type P_P;

class Build
{
public:
	map<int, P_PR> set_positions;
	map<int, R_P> row_op_map;
	map<int, C_P> col_op_map;
	map<int, B_P> block_op_map;

	static R_P active_row;
	static C_P active_column;
	static B_P active_block;
	static P_PR active_pos_ptr;
	static int active_int_pos_ptr;

	void setrcb_objects();

	void buildVec(vector<int>& Sud);

	void read_VecI(vector<int> vec);

	void set_active(P_P& p);

	void reset_active();

	void set_rcb_pos();

	void delete_pointer_position();

	void remove_available_pos();

	void delete_position();

	void delete_check_zero();

	void check_initial_positions();

	void read_set_positions();
	Build();
	~Build();
};
