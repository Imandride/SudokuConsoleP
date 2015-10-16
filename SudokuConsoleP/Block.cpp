#include "stdafx.h"
#include "Block.h"


void Block::read_available_in()
{
	for (auto iter : available_in_is)
		printf("%d, ", iter);

	printf("\n");
}

void Block::remove(int a)
{
	available_in_is.erase(a);
}

Block::Block(int key): block(key)
{
}



Block::~Block()
{
	printf("Block destructor called:\n");
}
