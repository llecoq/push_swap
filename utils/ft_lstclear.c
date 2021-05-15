/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:42:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/15 11:42:45 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_elem;

	if (!lst)
		return ;
	while (*lst)
	{
		next_elem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_elem;
	}
	*lst = NULL;
}
