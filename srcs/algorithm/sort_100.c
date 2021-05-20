/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:01:30 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 13:20:06 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_push *ps)
{
	int	rank;

	rank = ps->len;
	while (rank > 0)
	{
		dprintf(1, "rank = %d\n", rank);
		find_limit(ps, ps->pile_b, rank - 1, rank);
		while (!find_small(ps->pile_b, rank - 1, rank))
		{
			if (ps->limit == 's')
				rotate(ps, ps->pile_a, ps->pile_b, 'b');
			else if (ps->limit == 'e')
				r_rotate(ps, ps->pile_a, ps->pile_b, 'b');
		}
		push(ps, ps->pile_a, ps->pile_b, 'a');
		rank--; 
	}
}

void	find_chunks(t_push *ps, int min, int max)
{
	int	i;

	find_limit(ps, ps->pile_a, min, max);
	i = min;
	// dprintf(1, "len = %d min = %d, max = %d\n", ps->len, min, max);
	while (i < max)
	{
		while (!find_small(ps->pile_a, min, max))
		{
			if (ps->limit == 's')
				rotate(ps, ps->pile_a, ps->pile_b, 'a');
			else if (ps->limit == 'e')
				r_rotate(ps, ps->pile_a, ps->pile_b, 'a');
		}
		push(ps, ps->pile_a, ps->pile_b, 'b');
		i++;
	}
}

void	sort_100(t_push *ps)
{
	float	min;
	float	max;
	int		i;

	min = 0.0;
	max = (float)ps->len / 4.0;
	while (max <= ps->len)
	{
		find_chunks(ps, min, max);
		min += ps->len / 4.0;
		max += ps->len / 4.0;
	}
	ps->count_chunk = ps->count;
	sort(ps);
}