#include "ft_fillit.h"

int			compute_solution_size(int tetr_count)
{
	int		sol_size;

	sol_size = 0;
	while (sol_size * sol_size < tetr_count * 4)
		sol_size++;
	return (sol_size);
}

char		***generate_tetr_list(char *input)
{
	char	***list;
	int		num_tetr;
	int		index;
	char	convert_char;

	convert_char = 'A';
	index = 0;
	num_tetr = count_tetr(input);
	list = (char***)malloc(sizeof(char**) * num_tetr);
	fill_tetr_list(list, input, num_tetr);
	while (index < num_tetr)
	{
		convert_tetr(list[index], convert_char + index);
		shift_tetr(list[index]);
		index++;
	}
	return (list);
}

void		fill_square(char **sol, int sol_size)
{
	int		row_index;
	int		col_index;

	row_index = 0;
	while (row_index < sol_size)
	{
		col_index = 0;
		while (col_index < sol_size)
		{
			if (sol[row_index][col_index] == '\0' ||\
			!ft_isalpha(sol[row_index][col_index]))
				sol[row_index][col_index] = '.';
			col_index++;
		}
		row_index++;
	}
}

int			solve_tetr(char **sol, char ***tetrs, int count_index, int sol_size)
{
	int		row;
	int		col;
	int		tetr_count;
	int		index;

	fill_square(sol, sol_size);
	row = -1;
	tetr_count = count_index / 100;
	index = count_index % 100;
	while (row++ < sol_size)
	{
		col = -1;
		while (col++ < sol_size)
		{
			if (is_tetr_valid(sol, tetrs[index], row + col * 100, sol_size))
			{
				place_tetr(sol, tetrs[index], row, col);
				if (index + 1 == tetr_count ||\
				solve_tetr(sol, tetrs, count_index + 1, sol_size))
					return (1);
				remove_tetr(sol, tetrs[index], row, col);
			}
		}
	}
	return (0);
}
