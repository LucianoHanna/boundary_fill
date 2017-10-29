#include <stdio.h>
#include <stdlib.h>

void boundary_fill(int** matrix, int x, int y, int color, int color_original, int sizex, int sizey){

	// avoid matrix overflow
	if (x<0 || x>sizex || y<0 || y>sizey)
	{
		return;
	}

	// pickup original color at the first point(x,y)
	if (color_original == -1)
	{
		color_original = matrix[x][y];
	}

	// avoid infinite loop
	if (matrix[x][y] == color)
	{
		return;
	}

	// if the color at the point (x,y) is different than color_original
	if (matrix[x][y] != color_original)
	{
		return;
	}

	matrix[x][y] = color;

	// do the boundary fill in the neighbours recursively
	boundary_fill(matrix, x-1, y, color, color_original, sizex, sizey);
	boundary_fill(matrix, x+1, y, color, color_original, sizex, sizey);
	boundary_fill(matrix, x, y-1, color, color_original, sizex, sizey);
	boundary_fill(matrix, x, y+1, color, color_original, sizex, sizey);
	
}