#pragma once

class Position;

using namespace std;
class Build;

class Row
{
protected:
	int row = 0;
	Row() = delete;
	std::set<int> available_in_IS{1,2,3,4,5,6,7,8,9};
	std::set<std::shared_ptr<Position>> positions_in_PS;
	std::set<int>* available_in_RIS();
public:
	set<int>::iterator available_int_begin() { return available_in_IS.begin(); };
	set<int>::iterator available_int_end() { return available_in_IS.end(); };
	
	void row_positions(std::shared_ptr<Position> p);
	const int& getrow();
	void readrow();
	void read_availablein();
	void remove_availablein(int & a);
	void delete_pointer_position(std::shared_ptr<Position> p);
	explicit Row(int key);
	~Row();
};
