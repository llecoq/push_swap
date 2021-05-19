/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:28:18 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 16:50:59 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_push_swap(t_push *push, t_list *pile_a, t_list *pile_b)
{
	pile_a = NULL;
	pile_b = NULL;
	push->pile_a = pile_a;
	push->pile_b = pile_b;
}

int	main(int ac, char **av)
{
	t_push	push;
	t_list	pile_a;
	t_list	pile_b;

	if (ac <= 1)
		handle_error(&push);
	init_push_swap(&push, &pile_a, &pile_b);
	if (!store_list(&push, av))
		handle_error(&push);
	// push_swap(&push);
	clear_memory(push.pile_a);
	clear_memory(push.pile_b);
	return (0);
}
