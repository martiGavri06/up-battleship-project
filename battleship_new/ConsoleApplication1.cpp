#include <iostream>

#include <cstdlib>
#include <ctime>
#include <thread>
#include <fstream>

const int CALM_WATER = 10;
const int ROUGH_SEAS = 12;
const int STORM_OF_STEEL = 15;


void clearScreen()
{
	std::system("cls");
}

void print(char** playerGrid, char** computerGrid, int size)
{
	std::cout << "        Computer";

	for (int i = 0; i <= 3 * size; i++) //distance between headers
	{
		std::cout << ' ';
	}

	std::cout << "Player" << std::endl;

	std::cout << "   ";
	for (int i = 0; i < size; i++)
	{
		std::cout << i;
		if (i < 10)
			std::cout << "  ";
		else
			std::cout << " ";
	}

	std::cout << "   ";

	for (int i = 0; i < size; i++)
	{
		std::cout << i;
		if (i < 10)
			std::cout << "  ";
		else
			std::cout << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (i < 10)
			std::cout << " " << i << " ";
		else
			std::cout << i << " ";

		for (int j = 0; j < size; j++)
		{
			std::cout << playerGrid[i][j];
			if (j < 10)
				std::cout << "  ";
			else
				std::cout << "  ";
		}

		std::cout << ' ' << '|' << ' ';

		for (int j = 0; j < size; j++)
		{
			if (playerGrid[i][j] == '#' || computerGrid[i][j] == '~')
			{
				std::cout << '~';
			}
			else
			{
				std::cout << computerGrid[i][j];
			}

			if (j < 10)
				std::cout << "  ";
			else
				std::cout << "  ";
		}

		std::cout << std::endl;
	}
}

char** fillPlayerGrid(int size)
{
	char** grid = new char* [size];
	for (int i = 0; i < size; i++) 
	{
		grid[i] = new char[size];
		for (int j = 0; j < size; j++) 
		{
			grid[i][j] = '~';
		}
	}
	return grid;
}

int main()
{
	std::cout << "Ready for a battle?" << std::endl;
	int difficulty;
	int gridSize;
	char** playerGrid;
	char** computerGrid;

	std::cout << "Select 1 for option one and 2 for option two:" << std::endl;
	std::cout << "1) Start previous game" << std::endl;
	std::cout << "2) Start new game" << std::endl;

	int start;
	std::cin >> start;

	if (start == 2)
	{
		std::cout << "Select a number from 1 to 3 to choose a difficulty level:" << std::endl;
		std::cout << "1) Calm Water (10x10)" << std::endl;
		std::cout << "2) Rough Seas (12x12)" << std::endl;
		std::cout << "3) Storm of Steel (15x15)" << std::endl;

		std::cin >> difficulty;

		if (difficulty < 1 || difficulty > 3)
		{
			std::cout << "Invalid choice. Select a number again (from 1 to 3): " << std::endl;
			std::cin >> difficulty;
		}

		if (difficulty == 1)
		{
			gridSize = CALM_WATER;
		}
		else if (difficulty == 2)
		{
			gridSize = ROUGH_SEAS;
		}
		else if (difficulty == 3)
		{
			gridSize = STORM_OF_STEEL;
		}

		playerGrid = fillPlayerGrid(gridSize);
		computerGrid = fillPlayerGrid(gridSize);

		std::cout << "How would you like to place your ships?" << std::endl;
		std::cout << "1. Manually" << std::endl;
		std::cout << "2. Automatically" << std::endl;
		int placementChoice;
		std::cin >> placementChoice;

		clearScreen();

		print(playerGrid, computerGrid, gridSize);
	}