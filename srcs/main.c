/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:28:18 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 13:51:39 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_success(t_push *ps)
{
	t_list pile;
	t_list pile_b;

	if (ps->pile_a)
		pile = *ps->pile_a;
	if (ps->pile_b)
		pile_b = *ps->pile_b;
	if (ps->pile_a)
	while (!pile.end)
	{
		dprintf(1, "a rank = %d   number = %d\n", pile.content->rank,  pile.content->number);
		pile = *pile.next;
	}
	if (ps->pile_a)
	dprintf(1, "a rank = %d   number = %d\n\n", pile.content->rank,  pile.content->number);
	while (!pile_b.end)
	{
		dprintf(1, "b rank = %d   number = %d\n", pile_b.content->rank,  pile_b.content->number);
		pile_b = *pile_b.next;
	}
	if (ps->pile_b)
	dprintf(1, "b rank = %d   number = %d\n", pile_b.content->rank,  pile_b.content->number);
	dprintf(1, "count = %d   chunks = %d\n", ps->count, ps->count_chunk);
}

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

	check_success(&push);

	clear_memory(push.pile_a, &push);
	clear_memory(push.pile_b, &push);
	return (0);
}
