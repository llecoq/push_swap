/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:38:42 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 19:33:55 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_push *ps, t_list *list_a, t_list *list_b, char c)
{
	t_list	*tmp;

	if (list_b && list_b->next && c == 'a')
	{
		tmp = list_b->next;
		ft_lstadd_front(&list_a, list_b);
		ps->pile_a = list_b;
		ps->pile_b = tmp;
		loop_list(ps->pile_a);
		loop_list(ps->pile_b);
		ft_putstr("pa\n");
	}
	if (list_a && list_a->next && c == 'b')
	{
		tmp = list_a->next;
		ft_lstadd_front(&list_b, list_a);
		ps->pile_b = list_b;
		ps->pile_a = tmp;
		loop_list(ps->pile_a);
		loop_list(ps->pile_b);
		ft_putstr("pb\n");
	}
}