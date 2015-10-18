#include "stdafx.h"
#include "Row.h"


std::set<int>* Row::available_in_RIS()
{
	return &available_in_IS;
}

void Row::row_positions(Position* p)
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

void Row::remove(int a)
{
	available_in_IS.erase(a);
	for (auto p : positions_in_PS)
	{
		printf("Removing from position: %d\n", p->cn_pos());
		p->delete_available_pos(a);
		this->read_availablein();
		printf("\n");
	}
}

Row::Row(int key): row(key)
{
}


Row::~Row()
{
	printf("Row destructor called:\n");
}
