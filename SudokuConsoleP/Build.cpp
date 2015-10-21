#include "stdafx.h"
#include "Build.h"
#include <map>

 R_P Build::active_row;
 C_P Build::active_column;
 B_P Build::active_block;
 shared_ptr<Position> Build::active_pos_ptr;
 int Build::active_int_pos_ptr;
 set<pair<const int, shared_ptr<Position>>>::iterator Build::active_pIter;

class Position;


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

void Build::set_active(set<pair<const int, shared_ptr<Position>>>::iterator &p)
{
	active_row = p->second->return_active_ptr(active_row);
	active_column = p->second->return_active_ptr(active_column);
	active_block = p->second->return_active_ptr(active_block);
	active_pos_ptr = p->second;
	active_int_pos_ptr = p->second->return_active_ptr(active_int_pos_ptr);
	active_pIter = p;
}

void Build::reset_active()
{

	active_row = nullptr;
	active_column = nullptr;
	active_block = nullptr;
	active_pos_ptr = nullptr;
	active_int_pos_ptr = NULL;
	active_pIter._Orphan_me();
	
}

void Build::set_rcb_pos()
{
	for (set<pair<const int, shared_ptr<Position>>>::iterator p = set_positions.begin(); p != set_positions.end(); ++p)
	{
		set_active(p);
		active_pos_ptr->solve_set_address_RCB(row_op_map, col_op_map, block_op_map);
		reset_active();
	}
}

void Build::delete_pointer_position(set<pair<const int, shared_ptr<Position>>>::iterator & p)
{
	printf("Before nullcheck: ");
	if (p->second!= nullptr)
	{
		printf("Post nullcheck: ");

		p = set_positions.erase(p);
	}
	
}

void Build::remove_available_pos()
{
	int rn = active_pos_ptr->get_vector_value();
	active_row->remove_availablein(rn);
	active_column->remove(rn);
	active_block->remove(rn);
	active_pos_ptr->read_availablein();
}

void Build::delete_position()
{

		printf("Position: %d    ", active_int_pos_ptr);
		printf("Value: %d    ", active_pos_ptr->get_vector_value());
		active_row->readrow();
		active_column->readcolumn();
		active_block->readblock();
		remove_available_pos();

		active_row->delete_pointer_position(active_pos_ptr);
		active_column->delete_pointer_position(active_pos_ptr);
		active_block->delete_pointer_position(active_pos_ptr);

	//delete_pointer_position();
}

bool Build::delete_check_zero()
{
	if (active_pos_ptr->get_vector_value() == 0)
	{
		printf("Position %d Is Zero Checking next position: \n\n", active_pos_ptr->return_active_int());
		return true;
	}
	else

	return false;
}

void Build::check_initial_positions()
{
	for (set<pair<const int, shared_ptr<Position>>>::iterator p = set_positions.begin(); p != set_positions.end() && p->second != 0;)
	{
			set_active(p);
			if (delete_check_zero() == false)
			{
				printf("Position %d Is not zero: \n\n", active_pos_ptr->return_active_int());
				delete_position();
				delete_pointer_position(p);

			}
			else

				++p;
	}
	reset_active();
}

void Build::read_set_positions()
{
	for (auto p : set_positions)
	{
		printf("%d, \n", p.second->return_active_int());
	}
}

Build::Build()
{
}


Build::~Build()
{
}
