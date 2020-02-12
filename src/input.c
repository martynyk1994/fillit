/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <lmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:01:35 by lmartyny          #+#    #+#             */
/*   Updated: 2020/02/10 17:30:36 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			read_file(char *fname, char *input_buffer)
{
	int		fd;
	size_t	index;

	fd = open(fname, O_RDONLY, 0);
	index = 0;
	if (fd == -1)
		return (-1);
	index = read(fd, input_buffer, 600);
	return (index);
}

int			error_handling(int mode)
{
	if (mode == 0)
	{
		write(1, "usage: ./fillit source_file\n", 28);
	}
	else if (mode == 1)
	{
		write(1, "error", 5);
	}
	return (-1);
}

char		**empty_map(int sol_size)
{
	int		index;
	char	**map;
	int		sub_index;

	map = (char **)malloc(sizeof(char*) * (sol_size));
	index = 0;
	while (index < sol_size)
	{
		map[index] = (char *)malloc(sizeof(char) * (sol_size));
		sub_index = 0;
		while (sub_index < sol_size)
		{
			map[index][sub_index] = 0;
			sub_index++;
		}
		index++;
	}
	return (map);
}

char		**free_map(char **map, int sol_size)
{
	int		i;

	i = 0;
	while (i < sol_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

int			main(int argc, char **argv)
{
	char		*file_input;
	char		***list;
	char		**sol;
	int			sol_size;
	int			fd;

	file_input = (char *)malloc(sizeof(char) * 600);
	fd = read_file(argv[1], file_input);
	if (argc != 2)
		return (error_handling(0));
	if (check_all_tetr(file_input, fd) && fd != -1)
	{
		sol_size = compute_solution_size(count_tetr(file_input));
		sol = empty_map(sol_size);
		list = generate_tetr_list(file_input);
		while (!solve_tetr(sol, list, count_tetr(file_input) * 100, sol_size++))
		{
			free_map(sol, sol_size - 1);
			sol = empty_map(sol_size);
		}
		print_map(sol, sol_size - 1);
		sol = free_map(sol, sol_size - 1);
	}
	else
		return (error_handling(1));
}
