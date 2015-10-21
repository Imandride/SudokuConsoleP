#include "stdafx.h"
#include "Block.h"


const int& Block::getblock()
{
	return block;
}

void Block::readblock()
{
	printf("Block: %d\n\n", block);
}

void Block::block_positions(std::shared_ptr<Position> &p)
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

void Block::delete_pointer_position(std::shared_ptr<Position> p)
{
	printf("Deleting position %d from block: \n", p->return_active_int());
	positions_in_PS.erase(p);
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
		printf("Removing from position: %d\n", p->return_active_int());
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
