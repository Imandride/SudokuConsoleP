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

void remove_available_pos(Position* p)
{
	printf("\nVector value read");
	int rn = p->get_vector_value();
	printf("%d", rn);
	active_row->remove(rn);
	active_column->remove(rn);
	active_block->remove(rn);
	p->read_availablein();

	printf("\nRow being read");
	active_row->readrow();

	printf("\nColumn being read");
	active_column->readcolumn();

	printf("\nBlock being read");
	active_block->readblock();
	
	

}

void read_VecI(vector<int> vec)
{
	for (auto p : vec)
		printf("%d, ", p);
}

void setrcb_objects()
{
	for (int key = 0; key != 9; ++key)
	{
		row_op_map.insert(make_pair(key, new Row(key)));
		col_op_map.insert(make_pair(key, new Column(key)));
		block_op_map.insert(make_pair(key, new Block(key)));
		continue;
	}
	printf("\n");
	
}

void buildVec(vector<int>& Sud)
{
	if (Sud.empty()) 
	{ 
		puts("Sud is empty: "); 
		Sud.resize(81, 0);
		unique_ptr<Position> build(new Position(Sud)); 
	}
	else
	{
		int p = 0;
		for (vector<int>::iterator i = Sud.begin(); i != Sud.end(); ++p, ++i)
		{
			set_positions.insert(new Position(p, i));
			
		}
		
	}

}

void set_rcb_pos()
{
	for (auto p: set_positions)
	{
		p->solve_Positionrcb();

		p->row(row_op_map.at(p->Rr()));
		p->column(col_op_map.at(p->Rc()));
		p->block(block_op_map.at(p->Rb()));

		(p->row())->row_positions(p);
		(p->column())->column_positions(p);
		(p->block())->block_positions(p);

		//printf("%d\n", iter->cn_pos());
		// iter->read_availablein();
	}
}
void check_positions()
{
	for (auto p : set_positions)
	{
		printf("%d ", p->cn_pos());

		if (p->get_vector_value() != 0)
		{
			printf("%d ", p->get_vector_value());

			active_row = p->row();
			active_row->readrow();

			active_column= p->column();
			active_column->readcolumn();

			active_block= p->block();
			active_block->readblock();

			remove_available_pos(p);

			__debugbreak();
		}

		printf("\n");
		
	}

}

int main()
{
	setrcb_objects();
	vector<int> Sud; 
	buildVec(Sud); 
	buildVec(Sud); 
	set_rcb_pos();
	check_positions();

	
	//read_VecI(Sud);

	cin.get();
	return 0;
}
