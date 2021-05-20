/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:48:13 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 08:46:19 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	r_rotate(t_push *ps, t_list *list_a, t_list *list_b, char c)
{
	if (list_a && list_a->next && (c == 'a' || c == 'r'))
	{
		list_a->previous->end = 0;
		list_a->previous->previous->end = 1;
		ps->pile_a = list_a->previous;
	}
	if (list_b && list_b->next && (c == 'b' || c == 'r'))
	{
		list_b->previous->end = 0;
		list_b->previous->previous->end = 1;
		ps->pile_b = list_b->previous;
	}
	if (c == 'a')
		ft_putstr(ps, "rra\n");
	else if (c == 'b')
		ft_putstr(ps, "rrb\n");
	else if (c == 'r')
		ft_putstr(ps, "rrr\n");
}

void	rotate(t_push *ps, t_list *list_a, t_list *list_b, char c)
{
	if (list_a && list_a->next && (c == 'a' || c == 'r'))
	{
		list_a->previous->end = 0;
		list_a->end = 1;
		ps->pile_a = list_a->next;
	}
	if (list_b && list_b->next && (c == 'b' || c == 'r'))
	{
		list_b->previous->end = 0;
		list_b->end = 1;
		ps->pile_b = list_b->next;
	}
	if (c == 'a')
		ft_putstr(ps, "ra\n");
	else if (c == 'b')
		ft_putstr(ps, "rb\n");
	else if (c == 'r')
		ft_putstr(ps, "rr\n");
}
