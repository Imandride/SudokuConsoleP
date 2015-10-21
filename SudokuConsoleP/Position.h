#pragma once
#include <set>
#include <vector>
#include <map>
#include <memory>
#include "Row.h"
#include "Column.h"
#include "Block.h"


using namespace std;


typedef shared_ptr<Row> R_P;
typedef shared_ptr<Column> C_P;
typedef shared_ptr<Block> B_P;


class Position
{
public:

private:
	R_P row_;
	C_P column_;
	B_P block_;
	int cnPos = 0;
	std::vector<int>::const_iterator iter_pos_vect;
	std::set<int> available_pos_is{1,2,3,4,5,6,7,8,9};
	Position() = delete;
public:

	R_P& return_active_ptr(R_P);

	C_P& return_active_ptr(C_P);

	B_P& return_active_ptr(B_P);

	int& return_active_ptr(int);

	int return_active_int();

	void read_availablein();

	void solve_set_address_RCB(std::map<int, R_P>& ropr, std::map<int, C_P>& copr, std::map<int, B_P>& bopr);

	const int& get_vector_value();

	void delete_available_pos(int i);

	explicit Position(std::vector<int>& build_vector);

	explicit Position(int nPos, std::vector<int>::const_iterator p);
	~Position();
};
