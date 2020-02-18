#include "AStarAlgorithm.h"
#include <iostream>


AStarAlgorithm::AStarAlgorithm(const int& rows, const int& cols, const int& x1, const int& y1, const int& x2, const int& y2) : ROWS(rows), COLS(cols)
{
	
	for (int i = 0; i < rows; i++)
	{
		std::vector<Spot*> temp;

		for (int j = 0; j < cols; j++)
		{
			temp.push_back( new Spot(i, j, rows, cols) );
		}

		matrix.push_back(temp);
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix.at(i).at(j)->addNeighbours(matrix);
		}
	}

	start = matrix.at(x1).at(y1);
	end = matrix.at(x2).at(y2);

	openSet.push_back(start);
	openSet.at(0)->set = '+';

	
	while (true)
	{

		if (openSet.size() > 0)
		{
			int winner = 0;

			for (int i = 0; i < openSet.size(); i++)
			{
				if (openSet.at(i)->f < openSet.at(winner)->f)
				{
					winner = i;
				}
			}

			auto current = openSet.at(winner);

			if (current == end)
			{

				auto temp = current;
				temp->set = 'x';
				path.push_back(temp);
				while (temp->previous)
				{
					temp->previous->set = 'x';
					path.push_back(temp->previous);
					temp = temp->previous;
				}

				start->set = 'S';
				end->set = 'E';

				break;
			}

			for (int i = 0; i < openSet.size(); i++)
			{
				if (openSet.at(i) == current)
				{
					openSet.erase(openSet.begin() + i);
				}
			}

			current->set = 'o';
			closedSet.push_back(current);

			auto neighbours = current->neighbours;

			for (int i = 0; i < neighbours.size(); i++)
			{
				auto neighbour = neighbours.at(i);

				if (std::count(closedSet.begin(), closedSet.end(), neighbour) == false)
				{
					auto tempG = current->g + 1;

					if (std::count(openSet.begin(), openSet.end(), neighbour))
					{
						if (tempG < neighbour->g)
						{
							neighbour->g = tempG;
						}
					}
					else
					{
						neighbour->g = tempG;

						neighbour->set = '+';
						openSet.push_back(neighbour);
					}

					neighbour->h = heuristic(neighbour, end);
					neighbour->f = neighbour->g + neighbour->h;
					neighbour->previous = current;
				}
			}

		}
		else
		{
			// no solution
			break;
		}

	}

}

void AStarAlgorithm::draw()
{
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << "  ";

		for (int j = 0; j < COLS; j++)
		{
			std::cout << matrix.at(i).at(j)->set << " ";
		}
		std::cout << std::endl;
	}
}

AStarAlgorithm::~AStarAlgorithm() = default;

int AStarAlgorithm::heuristic(Spot *s, Spot* end)
{
	int d = abs(s->x - end->x) + abs(s->y - end->y);
	return d;
}