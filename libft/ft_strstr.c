/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:11:02 by lmartyny          #+#    #+#             */
/*   Updated: 2019/12/06 21:49:31 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)&haystack[i]);
	while (haystack[i])
	{
		j = 0;
		n = i;
		while (haystack[n] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}
