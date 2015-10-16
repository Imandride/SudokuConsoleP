#pragma once
class Row
{
	int row = 0;
	std::set<int> available_in_is{ 1,2,3,4,5,6,7,8,9 };
	std::set<Position*> positions_inrow_set;
	Row() = delete;
public:

	const int& getrow() const{return row;}
	void read_available_in();
	void remove(int a);
	explicit Row(int key);
	~Row();
};

