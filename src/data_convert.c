#include "ft_fillit.h"

void		convert_tetr(char **tetr, char c)
{
	int row_index;
	int col_index;

	col_index = -1;
	while (++col_index < 4)
	{
		row_index = -1;
		while (++row_index < 4)
		{
			if (tetr[row_index][col_index] == '#')
				tetr[row_index][col_index] = c;
		}
	}
}

int			find_offset_row(char **tetr)
{
	int row_index;
	int col_index;

	row_index = -1;
	while (++row_index < 4)
	{
		col_index = -1;
		while (++col_index < 4)
		{
			if (tetr[row_index][col_index] != '.')
			{
				return (row_index);
			}
		}
	}
	return (0);
}

int			find_offset_col(char **tetr)
{
	int row_index;
	int col_index;

	col_index = -1;
	while (++col_index < 4)
	{
		row_index = -1;
		while (++row_index < 4)
		{
			if (tetr[row_index][col_index] != '.')
			{
				return (col_index);
			}
		}
	}
	return (0);
}

void		shift_tetr(char **tetr)
{
	int row;
	int col;
	int offset_x;
	int offset_y;

	row = -1;
	offset_x = find_offset_row(tetr);
	offset_y = find_offset_col(tetr);
	while (++row < 4 && (offset_x || offset_y))
	{
		col = -1;
		while (++col < 4)
		{
			if (tetr[row][col] != '.')
			{
				tetr[row - offset_x][col - offset_y] = tetr[row][col];
				tetr[row][col] = '.';
			}
		}
	}
}

void		fill_tetr_list(char ***list, char *input, int num)
{
	int		index;
	int		row;
	int		col;

	index = 0;
	while (index < num)
	{
		list[index] = (char**)malloc(sizeof(char*) * 4);
		row = 0;
		while (row < 4)
		{
			list[index][row] = (char*)malloc(sizeof(char) * 4);
			col = 0;
			while (col < 4)
			{
				list[index][row][col] = *input;
				input++;
				col++;
			}
			input++;
			row++;
		}
		input++;
		index++;
	}
}
