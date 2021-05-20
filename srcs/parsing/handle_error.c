/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:56:47 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/20 10:00:30 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	handle_error(t_push	*push)
{
	clear_memory(push->pile_a);
	clear_memory(push->pile_b);
	ft_putstr(push, "Error\n");
	exit (0);
}
