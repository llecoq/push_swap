/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:57:48 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 13:30:41 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_limit(t_push *ps, t_list *pile, int min, int max)
{
	t_list *tmp;
	int		i;
	int		j;

	tmp = pile;
	i = 0;
	while (!pile->end && !find_small(pile, min, max))
	{
		pile = pile->next;
		i++;
	}
	pile = tmp;
	j = 0;
	while (!pile->previous->previous->end && !find_small(pile, min, max))
	{
		pile = pile->previous;
		j++;
	}
	pile = tmp;
	if (j < i)
		ps->limit = 'e';
	else if (j > i)
		ps->limit = 's';
}

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

int	find_small(t_list *pile, int min, int max)
{
	if (pile->content->rank > min
		&& pile->content->rank <= max)
			return (1);
	return (0);
}
