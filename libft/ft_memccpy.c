/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:57:37 by lmartyny          #+#    #+#             */
/*   Updated: 2019/12/25 17:38:56 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n > 0)
	{
		*(ptr1) = *(ptr2);
		if (*ptr2 == (unsigned char)c)
			return ((void*)(ptr1 + 1));
		ptr1++;
		ptr2++;
		n--;
	}
	return (NULL);
}
