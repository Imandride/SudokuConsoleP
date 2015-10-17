#pragma once
#include <set>

class Position;

class Block
{
protected:
	int block = 0;
		std::set<Position*> positions_in_PS;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	Block() = delete;

public:
	void block_positions(Position*);
	void read_availablein();
	std::set<int>* available_in_BIS();
	const int& getblock();
	void readblock();
	void remove(int a);
	explicit Block(int key);
	~Block();
};
