#pragma once
#include "Build.h"

class Build;
using namespace std;
class Block
{
protected:
	int block = 0;
	std::set<P_PR> positions_in_PS;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	Block() = delete;
	std::set<int>* available_in_BIS();
public:
	
	void read_availablein();
	void delete_pointer_position(P_PR p);
	const int& getblock();
	void readblock();
	void block_positions(P_PR& p);
	void remove(int a);
	explicit Block(int key);
	~Block();
};
