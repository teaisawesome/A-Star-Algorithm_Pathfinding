#include "AStarAlgorithm.h"
#include <iostream>
#include <set>

AStarAlgorithm::AStarAlgorithm(const int& x1, const int& y1, const int& x2, const int& y2)
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			matrix[i][j] = new Spot(i, j);
		}
	}


	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			matrix[i][j]->addNeighbours(matrix);
		}
	}

	
	start = matrix[x1][y1];
	end = matrix[x2][y2];

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

				std::cout << "WINNER" << std::endl;

				break;
			}

			// ezt akarom -> openSet.remove(current);
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
	for (int i = 0; i < 25; i++)
	{
		std::cout << "	";
		for (int j = 0; j < 25; j++)
		{
			std::cout <<  matrix[i][j]->set << " ";
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