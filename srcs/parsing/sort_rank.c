/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:37:42 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 13:05:14 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	**copy_tab(t_list *list, int i)
{
	int		**copy;
	int		j;

	copy = malloc(sizeof(int *) * i + 1);
	if (!copy)
		return NULL;
	copy[i - 1] = NULL;
	j = -1;
	while (++j < i - 1 && list)
	{
		copy[j] = malloc(sizeof(int) * 3);
		if (!copy[j])
			return NULL;
		copy[j][0] = (int)list->content->number;
		copy[j][1] = list->content->rank;
		copy[j][2] = 0;
		list = list->next;
	}
	return (copy);	
}

void	swap_rank(int **copy, int i, int j)
{
	int	tmp;

	tmp = copy[i][0];
	copy[i][0] = copy[j][0];
	copy[j][0] = tmp;
}

void	clear_tab(int **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	sort_rank(t_list *list, int k)
{
	int		i;
	int		j;
	int		**copy;
	
	copy = copy_tab(list, k);	
	if (!copy)
		return (0);
	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[++j])
			if (copy[j][0] > copy[i][0])
				swap_rank(copy, i, j);
	}
	while (list)
	{
		i = 0;
		while ((int)list->content->number != copy[i][0])
			i++;
		list->content->rank = copy[i][1];
		list = list->next;
	}
	clear_tab(copy);
	return (1);
}