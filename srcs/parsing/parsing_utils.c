/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:34:36 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/21 09:54:02 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	loop_list(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp_previous;

	tmp = list;
	while (list && list->next && !list->end)
	{
		tmp_previous = list;
		list = list->next;
		list->previous = tmp_previous;
	}
	list->end = 1;
	list->next = tmp;
	tmp->previous = list;
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
