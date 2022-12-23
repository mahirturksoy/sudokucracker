#include <stdbool.h>
#include <stdio.h>

//Creates a 9x9 board
int		wood[9][9];

//Checks if given digit already exists in row and column
bool	rccontrol(int row, int column, int digits)
{
	for (int i = 0; i < 9; i++)
		if (wood[row][i] == digits || wood[i][column] == digits)
			return (true);
	return (false);
}

//checks 3x3 boxes
bool	boxcontrol(int rowhead, int columnhead, int digits)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (wood[i + rowhead][j + columnhead] == digits)
				return (true);
	return (false);
}

//checks if we can insert the digit
bool	control(int row, int column, int digits)
{
	return (!rccontrol(row, column, digits) && !boxcontrol(row - row % 3, column - column % 3, digits));
}

//checks for an empty cell
bool	isitempty(int *row, int *column)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (wood[i][j] == 0)
			{
				*row = i;
				*column = j;
				return (true);
			}
	return (false);
}

// check if there is a solution
bool	solution(void)
{
	int row, column;
	if (!isitempty(&row, &column))
		return (true);
	for (int digits = 1; digits <= 9; digits++)
	{
		if (control(row, column, digits))
		{
			wood[row][column] = digits;
			if (solution())
				return (true);
			wood[row][column] = 0;
		}
	}
	return (false);
}

//prints numbers
void	printwood(void)
{
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
			printf("%2d", wood[row][column]);
		printf("\n");
	}
}

int	main(void)
{
	// place it
	int ornek[9][9] = {{6, 0, 0, 1, 0, 0, 0, 0, 0},
			   {0, 0, 9, 0, 5, 6, 0, 0, 8},
			   {0, 3, 0, 0, 0, 0, 0, 4, 0},
			   {0, 0, 6, 0, 7, 8, 0, 0, 5},
			   {0, 0, 0, 0, 0, 2, 0, 0, 0},
			   {9, 0, 0, 0, 0, 0, 6, 0, 0},
			   {0, 0, 0, 9, 0, 0, 0, 0, 1},
			   {4, 0, 0, 0, 1, 7, 0, 8, 0},
			   {0, 0, 7, 2, 0, 0, 0, 0, 0}};
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			wood[i][j] = ornek[i][j];
	if (solution())
        printwood();
	else
		printf("No solution found.\n");
	return (0);
}
