#include <stdio.h>
#include <stdlib.h>

void boundary_fill(int** matrix, int x, int y, int color, int original_color, int sizex, int sizey){

	// avoid matrix overflow
	if (x<0 || x>sizex || y<0 || y>sizey)
	{
		return;
	}

	// pickup original color at the first point(x,y)
	if (original_color == -1)
	{
		original_color = matrix[x][y];
	}

	// avoid infinite loop
	if (matrix[x][y] == color)
	{
		return;
	}

	// if the color at the point (x,y) is different than original_color
	if (matrix[x][y] != original_color)
	{
		return;
	}

	matrix[x][y] = color;

	// do the boundary fill in the neighbours recursively
	boundary_fill(matrix, x-1, y, color, original_color, sizex, sizey);
	boundary_fill(matrix, x+1, y, color, original_color, sizex, sizey);
	boundary_fill(matrix, x, y-1, color, original_color, sizex, sizey);
	boundary_fill(matrix, x, y+1, color, original_color, sizex, sizey);
	
}