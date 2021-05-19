/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:48:13 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 15:02:59 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	r_rotate(t_list *list_a, t_list *list_b, char c)
{
	if (list_a->next && (c == 'a' || c == 'r'))
	{
		list_a->previous->end = 0;
		list_a->previous->previous->end = 1;
		list_a = list_a->previous;
	}
	if (list_b->next && (c == 'b' || c == 'r'))
	{
		list_b->previous->end = 0;
		list_b->previous->previous->end = 1;
		list_b = list_b->previous;
	}
	if (c == 'a')
		ft_putstr("rra\n");
	else if (c == 'b')
		ft_putstr("rrb\n");
	else if (c == 'r')
		ft_putstr("rrr\n");
}

void	rotate(t_list *list_a, t_list *list_b, char c)
{
	if (list_a->next && (c == 'a' || c == 'r'))
	{
		list_a->previous->end = 0;
		list_a->end = 1;
		list_a = list_a->next;
	}
	if (list_b->next && (c == 'b' || c == 'r'))
	{
		list_b->previous->end = 0;
		list_b->end = 1;
		list_b = list_b->next;
	}
	if (c == 'a')
		ft_putstr("ra\n");
	else if (c == 'b')
		ft_putstr("rb\n");
	else if (c == 'r')
		ft_putstr("rr\n");
}
