/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:03:03 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 14:03:16 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_push *ps)
{
	int	rank;

	rank = ps->len;
	while (rank > 0)
	{
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
