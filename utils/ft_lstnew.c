/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:47:23 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 16:46:06 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstnew(t_data *data, long int number, int i)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	data = init_data(data, number);
	if (!new_elem)
		return (NULL);
	new_elem->content = data;
	new_elem->content->rank = i;
	new_elem->next = 0;
	new_elem->previous = 0;
	new_elem->end = 0;
	return (new_elem);
}
