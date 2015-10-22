#include "stdafx.h"
#include "Column.h"

std::set<int>* Column::P_aval_int_val()
{
	return &aval_int_val;
}

void Column::read_availablein()
{
	for (auto p: aval_int_val)
	{
		printf("%d ", p);
	}
}

void Column::column_positions(std::shared_ptr<Position> p)
{
	positions_in_PS.insert(p);
}

const int& Column::getcol()
{
	return column;
}

void Column::readcolumn()
{
	printf("Column: %d    ", column);
}

void Column::delete_pointer_position(std::shared_ptr<Position> p)
{
	printf("Deleting position %d from column: \n", p->return_active_int());
	positions_in_PS.erase(p);
}

void Column::remove(int a)
{
	aval_int_val.erase(a);
	for (auto p : positions_in_PS)
	{
		printf("Removing from position: %d\n", p->return_active_int());
		p->delete_available_pos(a);
		read_availablein();
		printf("\n");
	}
}

Column::Column(int key): column(key)
{
}


Column::~Column()
{
	printf("Column destructor called:\n");
}
