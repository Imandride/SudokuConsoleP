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
	if (Sud.empty()) // Checks if initial vector is empty;
	{ //
		puts("Sud is empty: "); // Verbose of above.
		printf("Vector has capacity of %d\n", Sud.capacity()); // Test script wont be included in post
		Sud.resize(81, 0); // Needed in post when input will be file based.
		printf("Vector has capacity of %d\n", Sud.capacity()); //	Test !post
		unique_ptr<Position> build(new Position(Sud)); // creates a temp *->object that builds vector
	}
	else
	{
		puts("Sud is !empty: "); // If vector is populated
		int p = 0; // Creates a position int to supplement
		for (vector<int>::iterator i = Sud.begin(); i != Sud.end(); ++p , ++i) // vector iterator reference
		{ //	
			if (*i == 0) // Check for unsolved position
			{ //
				set_positions.insert(new Position(p, i)); // Creates a new object on heap for every position that needs solving.
				// !! Note to delete on solving, ?? Or create threads to monitor the objects
				//printf("%p\n", &set_positions);										// Old code for checking if building in same set.
				continue; //resumes to the next position.
			}
			else
			{
				unique_ptr<Position> solved_position(new Position(p, i)); //temporary object deletes when done.
				solved_position->solve_Positionrcb();

				active_row = row_op_map.at(solved_position->r1());
				active_column = col_op_map.at(solved_position->c1());
				active_block = block_op_map.at(solved_position->b1());
				/*
				printf("Row number: %d\n", active_row->getrow());
				active_row->read_available_in();
				printf("Column number: %d\n", active_column->getcol());
				active_column->read_available_in();
				printf("Block number: %d\n", active_block->getblock());
				active_block->read_available_in();
				printf("\n");
				*/
				active_row->remove(*i);
				active_block->remove(*i);
				active_column->remove(*i);
				/*
				printf("Row number: %d\n", active_row->getrow());
				active_row->read_available_in();
				printf("Column number: %d\n", active_column->getcol());
				active_column->read_available_in();
				printf("Block number: %d\n", active_block->getblock());
				active_block->read_available_in();
				printf("\n");
				*/
			}
		}
	}
}

void read_VecI(vector<int> vec)
{
	for (auto iter: vec)
		printf("%d, ", iter);
}

int main()
{
	setrcb_objects();
	vector<int> Sud; // creation of an empty vector.
	buildVec(Sud); // loading as empty vec arg into function to set size and define positions.
	buildVec(Sud); // loading as a populated vector to create objects for solving.
	for (auto s : set_positions) // iterating through objects sequentially from least address location onwards.
	{ 
		s->solve_Positionrcb(); // solving for row column and block;
		active_row = row_op_map.at(s->r1());
		active_column = col_op_map.at(s->c1());
		active_block = block_op_map.at(s->b1());

		s->row(active_row);
		s->column(active_column);
		s->block(active_block);

		printf("Available in r for %d\n", s->cn_pos());
		
		s->read_availableinr();
		printf("\n");
		
		s->read_availableinc();
		printf("\n");
		
		s->read_availableinb();
		printf("\n");
	
		active_row->row_positions(s);
		active_column->column_positions(s);
		active_block->block_positions(s);
	}
	active_block->positions_inblock_set
	read_VecI(Sud);

	cin.get();
	return 0;
}
