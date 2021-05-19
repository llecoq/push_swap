/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:38:42 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 13:47:56 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_list *list_a, t_list *list_b, char c)
{
	t_list	*tmp;

	if (list_b->next && c == 'a')
	{
		tmp = list_b->next;
		ft_lstadd_front(&list_a, list_b);
		list_b = tmp;
		loop_list(list_a);
		loop_list(list_b);
		ft_putstr("pa\n");
	}
	if (list_a->next && c == 'b')
	{
		tmp = list_a->next;
		ft_lstadd_front(&list_b, list_a);
		list_a = tmp;
		loop_list(list_b);
		loop_list(list_a);
		ft_putstr("pb\n");
	}
}