/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 19:13:44 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	process_3(t_push *ps)
{
	int	rank;
	int	rank_2;
	int	rank_3;

	rank = ps->pile_a->content->rank;
	rank_2 = ps->pile_a->next->content->rank;
	rank_3 = ps->pile_a->next->next->content->rank;
	if (rank < rank_2 && rank < rank_3)
	{
		swap(ps->pile_a, ps->pile_b, 'a');
		rotate(ps, ps->pile_a, ps->pile_b, 'a');	
	}
	if (rank > rank_2 && rank < rank_3)
		swap(ps->pile_a, ps->pile_b, 'a');
	if (rank < rank_2 && rank > rank_3)
		r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
	if (rank > rank_3 && rank_2 < rank_3)
		rotate(ps, ps->pile_a, ps->pile_b, 'a');
	if (rank > rank_2 && rank_2 > rank_3)
	{
		swap(ps->pile_a, ps->pile_b, 'a');
		r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
	}
}

void	process_5(t_push *ps)
{
	push(ps, ps->pile_a, ps->pile_b, 'b');
	if (ps->len == 5)
		push(ps, ps->pile_a, ps->pile_b, 'b');
	process_3(ps);
}

void	push_swap(t_push *ps)
{
	if (ps->len == 2 && ps->pile_a->content->rank == 2)
		swap(ps->pile_a, ps->pile_b, 'a');
	else if (ps->len == 3)
		process_3(ps);
	else if (ps->len > 3 && ps->len < 6)
		process_5(ps);
}