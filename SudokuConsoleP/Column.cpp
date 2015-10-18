#include "stdafx.h"
#include "Column.h"

std::set<int>* Column::available_in_CIS()
{
	return &available_in_IS;
}

void Column::read_availablein()
{
	for (auto p: available_in_IS)
	{
		printf("%d ", p);
	}
}

void Column::column_positions(Position* p)
{
	positions_incol_set.insert(p);
}

const int& Column::getcol()
{
	return column;
}

void Column::readcolumn()
{
	printf("Column: %d    ",column);
}

void Column::remove(int a)
{
	available_in_IS.erase(a);
	for(auto p :  positions_incol_set)
	{
		printf("Removing from position: %d\n", p->cn_pos());
		p->delete_available_pos(a);
		this->read_availablein();
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
