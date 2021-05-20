/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:24:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 13:49:09 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_500(t_push *ps)
{
	float	min;
	float	max;
	int		i;

	min = 0.0;
	max = (float)ps->len / 10.0;
	while (max <= ps->len)
	{
		find_chunks(ps, min, max);
		min += ps->len / 10.0;
		max += ps->len / 10.0;
	}
	ps->count_chunk = ps->count;
	sort(ps);
}