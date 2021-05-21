/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:56:13 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 14:14:47 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_5(t_push *ps)
{
	while (!find_small(ps->pile_a, 0, 2))
	{
		if (ps->pile_a->next->content->rank < 3)
			rotate(ps, ps->pile_a, ps->pile_b, 'a');
		else
			r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
	}
	push(ps, ps->pile_a, ps->pile_b, 'b');
	if (ps->len == 5)
	{
		while (!find_small(ps->pile_a, 0, 2))
		{
			if (ps->pile_a->next->content->rank < 3)
				rotate(ps, ps->pile_a, ps->pile_b, 'a');
			else
				r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
		}
		push(ps, ps->pile_a, ps->pile_b, 'b');
	}
	sort_3(ps);
	if (ps->pile_b->content->rank == 1)
		rotate(ps, ps->pile_a, ps->pile_b, 'b');
	push(ps, ps->pile_a, ps->pile_b, 'a');
	push(ps, ps->pile_a, ps->pile_b, 'a');
}
