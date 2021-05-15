/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:04:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/15 14:36:05 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_memory(t_list *pile_a, t_list *pile_b)
{
	if (pile_a)
		ft_lstclear(&pile_a);
	if (pile_b)
		ft_lstclear(&pile_b);
}
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	valid_arg(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i])
		return (0);
	return (1);
}

int	store_list(t_list *list, char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (valid_arg(av[i]))
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
		else
			return (0);
	}
	// while (list)
	// {
	// 	dprintf(1, "content = %d\n", list->content);
	// 	list = list->next;
	// }
	return (1);
}