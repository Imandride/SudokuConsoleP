#pragma once
class Position;

class Block
{
protected:
	int block = 0;
	
	std::set<Position*> positions_inblock_set;
	Block() = delete;
public:
	std::set<int> available_in_is{1,2,3,4,5,6,7,8,9};
	void block_positions(Position*);
	const int& getblock();

	void read_available_in();
	void remove(int a);
	explicit Block(int key);
	~Block();
};
