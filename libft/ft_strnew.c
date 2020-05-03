/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:48:09 by lmartyny          #+#    #+#             */
/*   Updated: 2019/12/13 11:41:03 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	result = (char*)malloc(sizeof(char) * (size + 1));
	if (!(result == NULL))
	{
		i = 0;
		while (i <= size)
		{
			result[i] = '\0';
			i++;
		}
		return (result);
	}
	else
		return (NULL);
}
