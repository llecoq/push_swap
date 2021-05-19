/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:21:37 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 16:48:55 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	clear_memory(t_list *list)
{
	t_list	*next_elem;

	if (list)
	{
		loop_list(list);
		while (!list->end)
		{
			next_elem = list->next;
			free(list->content);
			free(list);
			list = next_elem;
		}
		free(list->content);
		free(list);
	}
	// if (ps->pile_b)
	// {
	// 	ps->pile_b->previous->next = NULL;
	// 	while (ps->pile_b)
	// 	{
	// 		next_elem = ps->pile_b->next;
	// 		free(ps->pile_b->content);
	// 		free(ps->pile_b->content);
	// 		ps->pile_b = next_elem;
	// 	}
	// }
	return (1);
}
