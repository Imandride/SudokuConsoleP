#include "stdafx.h"
#include "Row.h"
#include "Block.h"


std::set<int>* Row::available_in_RIS()
{
	return &available_in_IS;
}


void Row::row_positions(std::shared_ptr<Position> p)
{
	positions_in_PS.insert(p);
}

const int& Row::getrow()
{
	return row;
}

void Row::readrow()
{
	printf("Row: %d    ", row);
}

void Row::read_availablein()
{
	for (auto p : available_in_IS)
	{
		printf("%d ", p);
	}
}


void Row::remove_availablein(int & a)
{
	available_in_IS.erase(a);
	for (auto p : positions_in_PS)
	{
		printf("Removing %d from position: %d\n",a, p->return_active_int());
		p->read_availablein();
		p->delete_available_pos(a);
		p->read_availablein();
		printf("\n");
	}
}


void Row::delete_pointer_position(std::shared_ptr<Position> p)
{
	printf("Deleting position %d from row: \n", p->return_active_int());

	positions_in_PS.erase(p);
}

Row::Row(int key): row(key)
{
}


Row::~Row()
{
	printf("Row destructor called:\n");
}
