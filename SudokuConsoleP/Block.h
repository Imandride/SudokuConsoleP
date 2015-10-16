#pragma once
class Block
{
	int block = 0;
	std::set<int> available_in_is{ 1,2,3,4,5,6,7,8,9 };
	std::set<Position*> positions_inblock_set;
	Block() = delete;
public:
	const int& getblock() const{return block;}
	void read_available_in();
	void remove(int a);
	explicit Block(int key);
	~Block();
};

