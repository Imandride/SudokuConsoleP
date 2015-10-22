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
void delete_pointer_position(set<pair<const int, shared_ptr<Position>>>::iterator& p);
void reset_active();

class Position
{
protected:
	set<int>::iterator ret_begin(shared_ptr <class Row> &p)
	{
		return p->available_int_begin();
	};
	set<int>::iterator ret_end(shared_ptr <class Row> &p)
	{ 
		return p->available_int_end();
	};
	set<int>::iterator ret_begin(shared_ptr <class Block> &p)
	{
		return p->available_int_begin();
	};
	set<int>::iterator ret_end(shared_ptr <class Block> &p)
	{
		return p->available_int_end();
	};
	set<int>::iterator ret_begin(shared_ptr <class Column> &p)
	{
		return p->available_int_begin();
	};
	set<int>::iterator ret_end(shared_ptr <class Column> &p)
	{
		return p->available_int_end();
	};

private:
	R_P row_;
	C_P column_;
	B_P block_;
	int cnPos = 0;
	std::vector<int>::const_iterator iter_pos_vect;
	std::set<int> available_pos_is{1,2,3,4,5,6,7,8,9};
	Position() = delete;
public:

	void solve_set_address_RCB(std::map<int, R_P>& ropr, std::map<int, C_P>& copr, std::map<int, B_P>& bopr);


	R_P& return_active_ptr(R_P);
	C_P& return_active_ptr(C_P);
	B_P& return_active_ptr(B_P);
	int& return_active_ptr(int);
	int return_active_int();
	const int& get_vector_value();


	void read_availablein();
	void check_against(shared_ptr<Row>& p);
	void check_against(shared_ptr<Column>& p);
	void check_against(shared_ptr<Block>& p);

	void read_available_pos_is()
	{
		printf("Available in position %d: ", cnPos);
		for (auto p: available_pos_is)
		{
			printf("%d, ", p);
		}

		//printf("\n\n ");
	}

	//void check_against_RCB();


	void delete_available_pos(int i);


	explicit Position(std::vector<int>& build_vector);
	explicit Position(int nPos, std::vector<int>::const_iterator p);
	~Position();
};
