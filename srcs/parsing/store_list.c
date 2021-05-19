/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_list->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student->42lyon->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:04:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/16 16:59:25 by llecoq           ###   ########lyon->fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	valid_arg(char *av)
{
	int	i;

	i = 0;
	if (!av[0])
		return (0);
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
		if (temp == (long int)list->content->number)
			return (0);
		list = list->next;
	}
	return (1);
}

t_data	*init_data(t_data *data, long int number)
{
	t_data	*new_elem;

	new_elem = malloc(sizeof(t_data));
	if (!new_elem)
		return (NULL);
	new_elem->number = number;
	return (new_elem);
}

void	loop_list(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp_previous;

	tmp = list;
	while (list->next && !list->end)
	{
		tmp_previous = list;
		list = list->next;
		list->previous = tmp_previous;
	}
	list->end = 1;
	list->next = tmp;
	tmp->previous = list;
}

int	store_list(t_push *ps, char **av)
{
	int			i;
	t_data		*data;
	long int	temp;

	i = 0;
	while (av[++i])
	{
		if (valid_arg(av[i]))
		{
			temp = ft_atoi(av[i]);
			if (!(temp > 2147483647 || temp < -2147483648)
				&& check_duplicate(temp, ps->pile_a))
				ft_lstadd_back(&ps->pile_a, ft_lstnew(data, temp, i));
			else
				return (0);
		}
		else
			return (0);
	}
	if (!sort_rank(ps->pile_a, i))
		return (0);
	ps->len = i - 1;
	loop_list(ps->pile_a);
	return (1);
}
