/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:01:30 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 16:05:22 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_100(t_push *ps)
{
	float	min;
	float	max;
	int		i;

	min = 0.0;
	max = (float)ps->len / 5.0;
	while (max <= ps->len)
	{
		find_chunks(ps, min, max);
		min += (float)ps->len / 5.0;
		max += (float)ps->len / 5.0;
	}
	if (ps->pile_a && max > ps->len)
		find_chunks(ps, min, ps->len);
	ps->count_chunk = ps->count;
	sort(ps);
}
