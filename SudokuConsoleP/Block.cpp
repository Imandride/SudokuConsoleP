#include "stdafx.h"
#include "Block.h"



const int& Block::getblock()
{
	return block;
}

void Block::readblock()
{
	printf("Block: %d\n    ", block);
}

void Block::block_positions(Position* p)
{
	positions_in_PS.insert(p);
}

void Block::read_availablein()
{
	for (auto p : available_in_IS)
	{
		printf("%d ", p);
	}
}

std::set<int>* Block::available_in_BIS()
{
		return &available_in_IS;
}

void Block::remove(int a)
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

Block::Block(int key): block(key)
{
}


Block::~Block()
{
	printf("Block destructor called:\n");
}
