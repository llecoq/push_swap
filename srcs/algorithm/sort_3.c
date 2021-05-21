/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:54:10 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 16:06:15 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_push *ps)
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
