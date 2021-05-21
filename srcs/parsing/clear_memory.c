/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:21:37 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 15:23:21 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	clear_split(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	clear_memory(t_list *list, t_push *ps)
{
	t_list	*next_elem;

	if (list)
	{
		loop_list(list);
		while (!list->end)
		{
			next_elem = list->next;
			free(list->content);
			free(list);
			list = next_elem;
		}
		free(list->content);
		free(list);
	}
	if (ps->tab)
		clear_split(ps->tab);
	ps->tab = NULL;
	return (1);
}
