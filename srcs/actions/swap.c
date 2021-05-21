/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:42:36 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 14:13:57 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_push *ps, t_list *list_a, t_list *list_b, char c)
{
	t_data	*tmp;

	if (list_a && list_a->next && (c == 'a' || c == 's'))
	{
		tmp = list_a->content;
		list_a->content = list_a->next->content;
		list_a->next->content = tmp;
	}
	if (list_b && list_b->next && (c == 'b' || c == 's'))
	{
		tmp = list_b->content;
		list_b->content = list_b->next->content;
		list_b->next->content = tmp;
	}
	if (c == 'a')
		ft_putstr(ps, "sa\n");
	else if (c == 'b')
		ft_putstr(ps, "sb\n");
	else if (c == 's')
		ft_putstr(ps, "ss\n");
}
