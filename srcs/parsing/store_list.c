/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:58:15 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 16:13:30 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	valid_arg(char *av, int ac, t_push *ps)
{
	int	i;

	i = 0;
	if (!av[0] && ac == 2)
		exit (0);
	if (av[0] == '-')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] || (av[0] == '-' && i == 1))
		return (0);
	return (1);
}

int	store_args(t_push *ps, char **av, int ac)
{
	int			i;
	t_data		*data;
	long int	temp;

	i = -1;
	if (ac > 2)
		i++;
	while (av[++i])
	{
		if (valid_arg(av[i], ac, ps))
		{
			temp = ft_atoi(av[i]);
			if (!(temp > 2147483647 || temp < -2147483648)
				&& check_duplicate(temp, ps->pile_a))
				ft_lstadd_back(&ps->pile_a, ft_lstnew(data, temp, i));
			else
				handle_error(ps);
		}
		else
			handle_error(ps);
	}
	return (i);
}

int	store_list(t_push *ps, char **av, int ac)
{
	if (ac == 2)
	{
		if (!av[1][0])
			exit (0);
		ps->tab = ft_split(av[1], ' ');
		ps->len = store_args(ps, ps->tab, ac);
	}
	else
		ps->len = store_args(ps, av, ac) - 1;
	if (!sort_rank(ps->pile_a, ps->len + 1, ps))
		return (0);
	loop_list(ps->pile_a);
	return (1);
}
