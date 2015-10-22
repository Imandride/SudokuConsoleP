#pragma once
#include "stdafx.h"



class Build;

Position::Position(std::vector<int>& build_vector)
{
	std::vector<int> vtest_vector{0,0,0,8,9,0,0,7,0,0,4,0,1,7,0,9,0,3,9,6,0,0,4,2,1,0,0,0,9,0,4,0,0,5,0,0,5,0,0,0,6,0,2,0,7,0,1,4,5,2,0,0,8,9,0,0,0,0,0,3,7,1,2,0,0,6,2,8,9,0,3,0,2,5,3,0,0,0,0,0,6};
	for (auto i: vtest_vector)
	{
		printf("%d ", i);
	}

	printf("\n");
	build_vector = vtest_vector;
}

Position::Position(int nPos, std::vector<int>::const_iterator p): cnPos(nPos), iter_pos_vect(p)
{
	printf("Constructor for position %d called:\n", nPos);
}

void Position::solve_set_address_RCB(std::map<int, R_P>& ropr, std::map<int, C_P>& copr, std::map<int, B_P>& bopr)
{
	int row = cnPos / 9;
	int columb = cnPos % 9;
	int block = ((row / 3) * 3 + columb / 3);

	row_ = ropr.at(row);
	column_ = copr.at(columb);
	block_ = bopr.at(block);
}

R_P& Position::return_active_ptr(R_P)
{
	return row_;
}

B_P& Position::return_active_ptr(B_P)
{
	return block_;
}

int& Position::return_active_ptr(int)
{
	return cnPos;
}

int Position::return_active_int()
{
	return cnPos;
}

C_P& Position::return_active_ptr(C_P)
{
	return column_;
}

const int& Position::get_vector_value()
{
	return *iter_pos_vect;
}

void Position::read_availablein()
{
	printf("Positions in Row:\n");
	row_->read_availablein();
	printf("\n");
	printf("Positions in Column:\n");
	column_->read_availablein();
	printf("\n");
	printf("Positions in Block:\n");
	block_->read_availablein();
	printf("\n");
	printf("\n");
}
void delete_position()
{
	printf("Delete Position: %d    ", Build::active_int_pos_ptr);
	Build::active_pos_ptr->read_available_pos_is();

	Build::active_row->readrow();
	Build::active_column->readcolumn();
	Build::active_block->readblock();

	int rn = Build::active_pos_ptr->get_vector_value();

	Build::active_row->remove_availablein(rn);
	Build::active_column->remove(rn);
	Build::active_block->remove(rn);
	Build::active_pos_ptr->read_availablein();
	Build::active_row->delete_pointer_position(Build::active_pos_ptr);
	Build::active_column->delete_pointer_position(Build::active_pos_ptr);
	Build::active_block->delete_pointer_position(Build::active_pos_ptr);

}


void Position::check_against(shared_ptr<Row> & p)
{
	for (set<int>::iterator ca = available_pos_is.begin(); ca != available_pos_is.end() && &ca != nullptr;)
	{
		read_available_pos_is();
		printf("  Row \n ");
		bool match = false;
		printf("Position  %d: Row ", *ca);

		for (set<int>::iterator r = ret_begin(p); r != ret_end(p) && &r != nullptr;)
		{
			printf("%d, ", *r);
			if (*ca == *r)
			{
				printf("\nMatch found: \n \n");
				match = true;
			}
			
			if (match == false)
			{
				match = false;
				++r;
			}
			else
				break;
			
		}
		if (match == false)
		{
			printf("\nNo match found:\n \n");

			if (&ca != nullptr)
			{
			
				ca = available_pos_is.erase(ca);
				//printf("Number of available options is: %d \n\n", available_pos_is.size());
				printf("\n");
				if (available_pos_is.size() <= 1)
				{
					delete_position();
					delete_pointer_position(Build::active_pIter);
					reset_active();
				}
			
				
			}
		}
		else
			if (&ca != nullptr)
			{
				++ca;
			}
	}
	

}

void Position::check_against(shared_ptr<Column> & p)
{
	for (set<int>::iterator ca = available_pos_is.begin(); ca != available_pos_is.end() && &ca != nullptr;)
	{
		read_available_pos_is();
		printf(" Column \n ");
		bool match = false;
		printf("Position  %d: Column : ", *ca);

		for (set<int>::iterator r = ret_begin(p); r != ret_end(p) && &r != nullptr;)
		{
			printf("%d, ", *r);
			if (*ca == *r)
			{
				printf("\nMatch found: \n \n");
				match = true;
			}

			if (match == false)
			{
				match = false;
				++r;
			}
			else
				break;

		}
		if (match == false)
		{
			printf("\nNo match found:\n \n");

			if (&ca != nullptr)
			{

				ca = available_pos_is.erase(ca);
				//printf("Number of available options is: %d \n", available_pos_is.size());
				printf("\n");
				if (available_pos_is.size() <= 1)
				{
					delete_position();

				}
			}
		}
		else
			if (&ca != nullptr)
			{
				++ca;
			}
	}
	

}

void Position::check_against(shared_ptr<Block> & p)
{
	for (set<int>::iterator ca = available_pos_is.begin(); ca != available_pos_is.end() && &ca != nullptr;)
	{
		read_available_pos_is();
		printf(" Block \n ");
		bool match = false;
		printf("Position available %d: Block available: ", *ca);

		for (set<int>::iterator r = ret_begin(p); r != ret_end(p) && &r != nullptr;)
		{
			printf("%d, ", *r);
			if (*ca == *r)
			{
				printf("\nMatch found: \n \n");
				match = true;
			}

			if (match == false)
			{
				match = false;
				++r;
			}
			else
				break;

		}
		if (match == false)
		{
			printf("\nNo match found:\n \n");

			if (&ca != nullptr)
			{

				ca = available_pos_is.erase(ca);
				//printf("Number of available options is: %d \n", available_pos_is.size());
				printf("\n");
				if (available_pos_is.size() <= 1)
				{
					delete_position();

				}
			}
		}
		else
			if (&ca != nullptr)
			{
				++ca;
			}
	}
	read_available_pos_is();

}


void Position::delete_available_pos(int i)
{
	available_pos_is.erase(i);
}


Position::~Position()
{
	printf("Destructor called:\n");
}
