// SudokuConsoleP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Position.h"
#include <iostream>
#include <set>

set<Position*> set_positions;

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
		}
	}
}

int main()
{
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
