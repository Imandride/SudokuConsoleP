#pragma once


class Position;

using namespace std;

class Block
{
protected:
	int block = 0;
	std::set<std::shared_ptr<Position>> positions_in_PS;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	Block() = delete;
	std::set<int>* available_in_BIS();
public:
	set<int>::iterator available_int_begin() { return available_in_IS.begin(); };
	set<int>::iterator available_int_end() { return available_in_IS.end(); };

	void read_availablein();
	void delete_pointer_position(std::shared_ptr<Position> p);
	const int& getblock();
	void readblock();
	void block_positions(std::shared_ptr<Position>& p);
	void remove(int a);
	explicit Block(int key);
	~Block();
};
