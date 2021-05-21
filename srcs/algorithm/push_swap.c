/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:34:54 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 14:16:34 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_push *ps)
{
	while (!sorted(ps->pile_a, ps->pile_b))
	{
		if (ps->len == 2 && ps->pile_a->content->rank == 2)
			swap(ps, ps->pile_a, ps->pile_b, 'a');
		else if (ps->len == 3)
			sort_3(ps);
		else if (ps->len > 3 && ps->len <= 5)
			sort_5(ps);
		else if (ps->len > 5 && ps->len <= 100)
			sort_100(ps);
		else if (ps->len > 100 && ps->len <= 500)
			sort_500(ps);
	}
}
