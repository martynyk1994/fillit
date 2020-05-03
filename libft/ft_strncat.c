/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:46:18 by lmartyny          #+#    #+#             */
/*   Updated: 2019/12/03 22:20:28 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t c;

	i = 0;
	while (s1[i])
		i++;
	c = 0;
	while (s2[c] && n > 0)
	{
		s1[i] = s2[c];
		i++;
		c++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
