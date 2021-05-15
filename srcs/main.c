/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:28:18 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/15 15:55:43 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = NULL;
	if (ac <= 1)
		handle_error(pile_a);
	if (!store_list(pile_a, av))
		return (handle_error(pile_a));
	clear_memory(pile_a, pile_b);
	return (0);
}
