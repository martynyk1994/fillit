/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <lmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:57:16 by lmartyny          #+#    #+#             */
/*   Updated: 2020/02/10 18:24:38 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			check_tetr(char *tetr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i <= 19)
	{
		if (tetr[i] && tetr[i] != '\n' && tetr[i] != '#' && tetr[i] != '.')
			return (0);
		if (tetr[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (tetr[i] == '#')
			count++;
		i++;
	}
	return (count);
}

static int	check_con(char *tetr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (tetr[i] == '#')
		{
			if (i + 1 <= 18 && tetr[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && tetr[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && tetr[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && tetr[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int			check_all_tetr(char *tetr, int size)
{
	int i;

	i = 0;
	if (size < 20 || (*(tetr + size - 2) == '\n' && *(tetr + size - 1) == '\n')\
	|| size > 545)
		return (0);
	while (i < size)
	{
		if (check_tetr(tetr + i) != 4)
			return (0);
		if (check_con(tetr + i) != 6 && check_con(tetr + i) != 8)
			return (0);
		if (*(tetr + i + 20))
		{
			if ((*(tetr + i + 20) != '\n') && (*(tetr + i + 21) != '#' ||\
						*(tetr + i + 21) != '.'))
				return (0);
		}
		if (*(tetr + i) == '\n')
			return (0);
		i += 21;
	}
	return (1);
}
