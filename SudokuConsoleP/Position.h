#pragma once
#include <vector>


class Position
{
	int r =0;
	int c =0;
	int b =0;
	const int cnPos = 0;
	std::vector<int>::const_iterator vector_const_iterator_p;
	Position();
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
