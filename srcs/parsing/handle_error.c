/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:56:47 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 16:49:19 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	handle_error(t_push	*push)
{
	clear_memory(push->pile_a);
	clear_memory(push->pile_b);
	ft_putstr("Error\n");
	exit (0);
}
