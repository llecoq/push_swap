/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:56:47 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/16 17:31:14 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_error(t_list	*list)
{
	if (list)
		ft_lstclear(&list);
	ft_putstr("Error\n");
	exit (0);
}
