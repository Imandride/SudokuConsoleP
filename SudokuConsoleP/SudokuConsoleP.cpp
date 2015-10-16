// SudokuConsoleP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


set<Position*> set_positions;
map<int, Row*> row_op_map;
map<int, Column*> col_op_map;
map<int, Block*> block_op_map;
Row* active_row;
Column* active_column;
Block* active_block;

void setrcb_objects()
{
	for (int key = 0; key != 9; ++key)
		{	
			printf("%d  ", key);
			row_op_map.insert(make_pair(key, new Row(key)));
			continue;
		}
	printf("\n");
	for (int key = 0; key != 9; ++key)
	{
		printf("%d  ", key);
		col_op_map.insert(make_pair(key, new Column(key)));
		continue;
	}
	printf("\n");
	for (int key = 0; key != 9; ++key)
	{
		printf("%d  ", key);
		block_op_map.insert(make_pair(key, new Block(key)));
		continue;
	}

}

void buildVec(vector<int>& Sud)
{
	if (Sud.empty())												// Checks if initial vector is empty;
	{																//
		puts("Sud is empty: ");										// Verbose of above.
		printf("Vector has capacity of %d\n", Sud.capacity());		// Test script wont be included in post
		Sud.resize(81, 0);											// Needed in post when input will be file based.
		printf("Vector has capacity of %d\n", Sud.capacity());		//	Test !post
		unique_ptr<Position> build(new Position(Sud));				// creates a temp *->object that builds vector
	}
	else
	{
		puts("Sud is !empty: ");														// If vector is populated
		int p = 0;																		// Creates a position int to supplement
		for (vector<int>::iterator i = Sud.begin(); i != Sud.end(); ++p , ++i)			// vector iterator reference
		{																				//	
			if (*i == 0)																// Check for unsolved position
			{																			//
				set_positions.insert(new Position(p, i));								// Creates a new object on heap for every position that needs solving.
																						// !! Note to delete on solving, ?? Or create threads to monitor the objects
				//printf("%p\n", &set_positions);										// Old code for checking if building in same set.
				continue;																//resumes to the next position.
			}
			else
			{
				unique_ptr<Position> solved_position(new Position(p,i)); //temporary object deletes when done.
				solved_position->solve_Position();

				active_row = row_op_map.at(solved_position->r1());
				active_column = col_op_map.at(solved_position->c1());
				active_block = block_op_map.at(solved_position->b1());

				printf("Row number: %d\n", active_row->getrow());
				active_row->read_available_in();
				printf("Column number: %d\n", active_column->getcol());
				active_column->read_available_in();
				printf("Block number: %d\n", active_block->getblock());
				active_block->read_available_in();
				printf("\n");

				active_row->remove(*i);
				active_block->remove(*i);
				active_column->remove(*i);

				printf("Row number: %d\n", active_row->getrow());
				active_row->read_available_in();
				printf("Column number: %d\n", active_column->getcol());
				active_column->read_available_in();
				printf("Block number: %d\n", active_block->getblock());
				active_block->read_available_in();
				printf("\n");


			}
		}
	}
}

int main()
{
	setrcb_objects();
	int* Pos;											// Position as a a pointer. don't actually know if i'm using it still ill check later.
	vector<int> Sud;									// creation of an empty vector.
	buildVec(Sud);										// loading as empty vec arg into function to set size and define positions.
	buildVec(Sud);										// loading as a populated vector to create objects for solving.
	Position* ppos;										// Creating a pointer to objects are unnamed only reference addresses is set_positions.
	for (auto s : set_positions)						// iterating through objects sequentially from least address location onwards.
	{													//
		ppos = s;										// setting the pointer to the address of first available object
		printf("%d\n", ppos->cn_pos());					// outputting object position;
		ppos->solve_Position();							// solving for row column and block;
		printf("%d ", ppos->r1());						// outputting row
		printf("%d ", ppos->c1());						// outputting column
		printf("%d\n\n", ppos->b1());					// outputting block
	}
	

	cin.get();
	return 0;
}
