/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 09:50:59 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sorted(t_list *pile_a, t_list *pile_b)
{
	if (pile_b)
		return (0);
	while (!pile_a->end)
	{
		if (pile_a && pile_a->next 
			&& pile_a->content->number > pile_a->next->content->number)
			return (0);
		pile_a = pile_a->next;
	}
	dprintf(1, "SORTED\n");
	return (1);
}

void	process_3(t_push *ps)
{
	int	rank;
	int	rank_2;
	int	rank_3;

	rank = ps->pile_a->content->rank;
	rank_2 = ps->pile_a->next->content->rank;
	rank_3 = ps->pile_a->next->next->content->rank;
	if (rank < rank_3 && rank_2 > rank_3)
	{
		swap(ps, ps->pile_a, ps->pile_b, 'a');
		rotate(ps, ps->pile_a, ps->pile_b, 'a');
	}
	if (rank > rank_2 && rank < rank_3)
		swap(ps, ps->pile_a, ps->pile_b, 'a');
	if (rank < rank_2 && rank > rank_3)
		r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
	if (rank > rank_3 && rank_2 < rank_3)
		rotate(ps, ps->pile_a, ps->pile_b, 'a');
	if (rank > rank_2 && rank_2 > rank_3)
	{
		swap(ps, ps->pile_a, ps->pile_b, 'a');
		r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
	}
}

int	find_small(t_list *pile_a)
{
	if (pile_a->content->rank == 1
		|| pile_a->content->rank == 2)
		return (1);
	return (0);
}

void	process_5(t_push *ps)
{
	while (!find_small(ps->pile_a))
	{
		if (ps->pile_a->next->content->rank < 3)
			rotate(ps, ps->pile_a, ps->pile_b, 'a');
		else 
			r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
	}
	push(ps, ps->pile_a, ps->pile_b, 'b');
	if (ps->len == 5)
	{
		while (!find_small(ps->pile_a))
		{
			if (ps->pile_a->next->content->rank < 3)
				rotate(ps, ps->pile_a, ps->pile_b, 'a');
			else 
				r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
		}
		push(ps, ps->pile_a, ps->pile_b, 'b');
	}
	process_3(ps);
	if (ps->pile_b->content->rank == 1)
		rotate(ps, ps->pile_a, ps->pile_b, 'b');
	push(ps, ps->pile_a, ps->pile_b, 'a');
	push(ps, ps->pile_a, ps->pile_b, 'a');
}

void	push_swap(t_push *ps)
{
	while (!sorted(ps->pile_a, ps->pile_b))
	{
		if (ps->len == 2 && ps->pile_a->content->rank == 2)
			swap(ps, ps->pile_a, ps->pile_b, 'a');
		else if (ps->len == 3)
			process_3(ps);
		else if (ps->len > 3 && ps->len < 6)
			process_5(ps);
	}
}
