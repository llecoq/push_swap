/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:28:18 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 16:05:55 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_push_swap(t_push *ps, t_list *pile_a, t_list *pile_b)
{
	pile_a = NULL;
	pile_b = NULL;
	ps->tab = NULL;
	ps->pile_a = pile_a;
	ps->pile_b = pile_b;
	ps->len = 0;
	ps->count = 0;
	ps->limit = 's';
}

int	main(int ac, char **av)
{
	t_push	push;
	t_list	pile_a;
	t_list	pile_b;

	if (ac <= 1)
		return (0);
	init_push_swap(&push, &pile_a, &pile_b);
	if (!store_list(&push, av, ac))
		handle_error(&push);
	push_swap(&push);
	clear_memory(push.pile_a, &push);
	clear_memory(push.pile_b, &push);
	return (0);
}
