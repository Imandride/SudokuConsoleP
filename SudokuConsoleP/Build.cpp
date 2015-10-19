#include "stdafx.h"
#include "Build.h"
#include <map>


void Build::setrcb_objects()
{
	for (int key = 0; key != 9; ++key)
	{
		row_op_map.insert(make_pair(key, make_shared<Row>(key)));
		col_op_map.insert(make_pair(key, make_shared<Column>(key)));
		block_op_map.insert(make_pair(key, make_shared<Block>(key)));
		continue;
	}
	printf("\n");
}

void Build::buildVec(vector<int>& Sud)
{
	{
		if (Sud.empty())
		{
			puts("Sud is empty: ");
			Sud.resize(81, 0);
			unique_ptr<Position> build(new Position(Sud));
		}
		else
		{
			int p = 0;
			for (auto i = Sud.begin(); i != Sud.end(); ++p , ++i)
			{
				set_positions.insert(make_pair(p, make_shared<Position>(p, i)));
			}
		}
	}
}

void Build::read_VecI(vector<int> vec)
{
	for (auto p : vec)
		printf("%d, ", p);
}

void Build::set_active(P_P& p)
{
	active_row = p->return_active_ptr(active_row);
	active_column = p->return_active_ptr(active_column);
	active_block = p->return_active_ptr(active_block);
	active_pos_ptr = p;
	active_int_pos_ptr = p->return_active_ptr(active_int_pos_ptr);
}

void Build::reset_active()
{
	active_row = __nullptr;
	active_column = __nullptr;
	active_block = __nullptr;
	active_pos_ptr = __nullptr;
	active_int_pos_ptr = NULL;
}

void Build::set_rcb_pos()
{
	for (auto p : set_positions)
	{
		set_active(p);
		active_pos_ptr->solve_set_address_RCB(row_op_map, col_op_map, block_op_map);
		reset_active();
	}
}

void Build::delete_pointer_position()
{
	printf("Deleting position %d: \n\n", active_int_pos_ptr);
}

void Build::remove_available_pos()
{
	int rn = active_pos_ptr->get_vector_value();
	active_row->remove_availablein(rn);
	active_column->remove(rn);
	active_block->remove(rn);
	//p->read_availablein();
}

void Build::delete_position()
{
	printf("Position: %d    ", active_int_pos_ptr);
	printf("Value: %d    ", active_pos_ptr->get_vector_value());
	active_row->readrow();
	active_column->readcolumn();
	active_block->readblock();
	remove_available_pos();

	active_row->delete_pointer_position();
	active_column->delete_pointer_position();
	active_block->delete_pointer_position();

	delete_pointer_position();
}

void Build::delete_check_zero()
{
	if (active_pos_ptr->get_vector_value() == 0)
	{
		printf("Position %d Is Zero Checking next position: \n\n", active_pos_ptr->return_active_int());
	}
	else
	{
		delete_position();
	}
}

void Build::check_initial_positions()
{
	for (auto p : set_positions)
	{
		set_active(p);
		delete_check_zero();
		reset_active();
	}
}

void Build::read_set_positions()
{
	for (auto p : set_positions)
	{
		printf("%d, \n", p->return_active_int());
	}
}

Build::Build()
{
}


Build::~Build()
{
}
