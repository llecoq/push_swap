/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:04:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/15 15:41:24 by llecoq           ###   ########lyon.fr   */
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

int	check_duplicate(long int temp, t_list *list)
{
	while (list)
	{
		if (temp == (long int)list->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	store_list(t_list *list, char **av)
{
	int			i;
	long int	temp;

	i = 0;
	while (av[++i])
	{
		if (valid_arg(av[i]))
		{
			temp = ft_atoi(av[i]);
			if (!(temp > 2147483647 || temp < -2147483648)
				&& check_duplicate(temp, list))
				ft_lstadd_back(&list, ft_lstnew(temp));
			else
				return (0);	
		}
	}
	while (list)
	{
		dprintf(1, "content = %d\n", list->content);
		list = list->next;
	}
	return (1);
}