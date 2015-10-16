#include "stdafx.h"
#include "Column.h"


void Column::read_available_in()
{
	for (auto iter : available_in_is)
		printf("%d, ", iter);

	printf("\n");
}

void Column::remove(int a)
{
	available_in_is.erase(a);
}

Column::Column(int key): column(key)
{
}


Column::~Column()
{
	printf("Column destructor called:\n");

}