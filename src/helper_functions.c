/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:58:17 by lmartyny          #+#    #+#             */
/*   Updated: 2020/02/10 17:32:10 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	print_map(char **sol, int sol_size)
{
	int		row_index;
	int		col_index;

	row_index = 0;
	col_index = 0;
	while (row_index < sol_size && sol[row_index][col_index])
	{
		while (col_index < sol_size && sol[row_index][col_index])
		{
			write(1, &sol[row_index][col_index], 1);
			col_index++;
		}
		write(1, "\n", 1);
		row_index++;
		col_index = 0;
	}
}

int		is_tetr_valid(char **sol, char **tetr, int row_col, int sol_size)
{
	int		row_index;
	int		col_index;
	int		row;
	int		col;

	row = row_col % 100;
	col = row_col / 100;
	row_index = 0;
	while (row_index < 4)
	{
		col_index = 0;
		while (col_index < 4)
		{
			if (ft_isalpha(tetr[row_index][col_index]))
			{
				if (row_index + row > sol_size - 1 ||\
						col_index + col > sol_size - 1 ||\
						sol[row_index + row][col_index + col] != '.')
					return (0);
			}
			col_index++;
		}
		row_index++;
	}
	return (1);
}

void	place_tetr(char **sol, char **tetr, int row, int col)
{
	int		y_index;
	int		x_index;

	y_index = 0;
	while (y_index < 4)
	{
		x_index = 0;
		while (x_index < 4)
		{
			if (ft_isalpha(tetr[y_index][x_index]))
				sol[row + y_index][col + x_index] = tetr[y_index][x_index];
			x_index++;
		}
		y_index++;
	}
}

void	remove_tetr(char **sol, char **tetr, int row, int col)
{
	int		row_index;
	int		col_index;

	row_index = 0;
	while (row_index < 4)
	{
		col_index = 0;
		while (col_index < 4)
		{
			if (ft_isalpha(tetr[row_index][col_index]))
				sol[row + row_index][col + col_index] = '.';
			col_index++;
		}
		row_index++;
	}
}

int		count_tetr(char *input)
{
	int		count;
	char	*scanner;

	count = 0;
	scanner = input;
	while (*scanner)
	{
		if (*scanner == '\n')
			count++;
		scanner++;
	}
	return ((count + 1) / 5);
}
