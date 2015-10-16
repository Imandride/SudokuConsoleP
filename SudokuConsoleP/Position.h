#pragma once
#include <vector>
#include <set>


class Position
{
	int r =0;				// row	
	int c =0;				// column
	int b =0;				// block
	const int cnPos = 0;	//position
	std::vector<int>::const_iterator vector_const_iterator_p; // address of iteration of vector in which position resides
	std::set<int> available_pos_is{ 1,2,3,4,5,6,7,8,9 };
	Position() = delete;
public:

	int cn_pos() const;
	void solve_Position();

	const int& r1() const
	{
		return r;
	}

	const int& c1() const
	{
		return c;
	}

	const int& b1() const
	{
		return b;
	}

	explicit Position(std::vector<int>& build_vector);
	explicit Position(int nPos, std::vector<int>::const_iterator p);
	~Position();
};
