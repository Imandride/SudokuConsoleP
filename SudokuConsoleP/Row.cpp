#include "stdafx.h"
#include "Row.h"


void Row::read_available_in()
{
	for (auto iter: available_in_is)
		printf("%d, ", iter);

	printf("\n");
}

void Row::remove(int a)
{
	available_in_is.erase(a);
}

Row::Row(int key): row(key)
{
}



Row::~Row()
{
	printf("Row destructor called:\n");

}
