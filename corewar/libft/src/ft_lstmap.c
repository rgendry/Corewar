/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:37:06 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/30 15:38:04 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*initialization(t_list *(*f)(t_list *elem), t_list *lst)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new = (*f)(lst)))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	start = initialization(f, lst);
	tmp = start;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new = initialization(f, lst);
		tmp->next = new;
		tmp = new;
	}
	return (start);
}
