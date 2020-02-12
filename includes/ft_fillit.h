/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <lmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:38:50 by lmartyny          #+#    #+#             */
/*   Updated: 2020/02/10 17:38:35 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

int			read_file(char *fname, char *input_buffer);
int			check_tetr(char *tetr);
int			check_all_tetr(char *tetr, int size);
int			count_tetr(char *input);
char		***generate_tetr_list(char *input);
void		convert_tetr(char **tetr, char c);
void		shift_tetr(char **tetr);
void		fill_tetr_list(char ***list, char *input, int num);
int			error_handling(int mode);
void		print_map(char **sol, int sol_size);
int			is_tetr_valid(char **sol, char **tetr, int row_col, int sol_size);
void		place_tetr(char **sol, char **tetr, int row, int col);
void		remove_tetr(char **sol, char **tetr, int row, int col);
int			solve_tetr(char **sol, char ***tetr_list, int count_index,
			int sol_size);
char		**free_map(char **map, int sol_size);
int			compute_solution_size(int tetr_count);
#endif
