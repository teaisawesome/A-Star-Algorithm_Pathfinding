#include "Spot.h"

Spot::Spot(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}

bool Spot::operator==(const Spot& s) const
{
	if (x == s.x && y == s.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Spot::addNeighbours(Spot *matrix[25][25])
{
	int x = this->x;
	int y = this->y;

	// 5 = cols
	if (x < 25 - 1)
	{
		this->neighbours.push_back(matrix[x + 1][y]);
	}
	if (x > 0)
	{
		this->neighbours.push_back(matrix[x - 1][y]);
	}
	if (y < 25 - 1)
	{
		this->neighbours.push_back(matrix[x][y + 1]);
	}
	if (y > 0)
	{
		this->neighbours.push_back(matrix[x][y - 1]);
	}
}

Spot::~Spot() = default;