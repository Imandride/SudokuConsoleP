// SudokuConsoleP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Position.h"
#include <iostream>
#include <set>

set<Position*> set_positions;

void buildVec(vector<int>& Sud)
{
	if (Sud.empty())
	{
		puts("Sud is empty: ");
		printf("Vector has capacity of %d\n", Sud.capacity());
		Sud.resize(81, 0);
		printf("Vector has capacity of %d\n", Sud.capacity());
		unique_ptr<Position> build(new Position(Sud));
	}
	else
	{
		puts("Sud is !empty: ");
		int p = 0;
		for (vector<int>::iterator i = Sud.begin(); i != Sud.end(); ++p , ++i)
		{
			if (*i == 0)
			{
				set_positions.insert(new Position(p, i));
				//printf("%p\n", &set_positions);
				continue;
			}
		}
	}
}

int main()
{
	int* Pos;
	vector<int> Sud;
	buildVec(Sud);
	buildVec(Sud);

	Position* ppos;
	for (auto s : set_positions)
	{
		ppos = s;
		printf("%d\n", ppos->cn_pos());
		ppos->solve_Position();
		printf("%d ", ppos->r1());
		printf("%d ", ppos->c1());
		printf("%d\n\n", ppos->b1());
	}


	cin.get();
	return 0;
}
