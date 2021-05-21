/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:24:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 13:57:28 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_500(t_push *ps)
{
	float	min;
	float	max;
	int		i;

	min = 0.0;
	max = (float)ps->len / 12;
	while (max <= ps->len)	
	{
		find_chunks(ps, min, max);
		min += (float)ps->len / 12;
		max += (float)ps->len / 12;
	}
	if (ps->pile_a && max > ps->len)
		find_chunks(ps, min, ps->len);
	ps->count_chunk = ps->count;
	sort(ps);
}