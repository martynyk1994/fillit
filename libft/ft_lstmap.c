/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:19:51 by lmartyny          #+#    #+#             */
/*   Updated: 2019/12/26 12:56:31 by lmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *current;
	t_list *new_elem;

	new_lst = f(lst);
	lst = lst->next;
	current = new_lst;
	while (lst)
	{
		new_elem = f(lst);
		if (new_elem == NULL)
			return (NULL);
		current->next = new_elem;
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}
