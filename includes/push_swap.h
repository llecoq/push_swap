/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:29:42 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/15 11:50:46 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	void *content;
	t_list *next;
	t_list *previous;
}				t_list;

/* UTILS */

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_putstr(char *s);
void	ft_putchar(char c);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);

/* PARSING */


/* PUSH_SWAP */

#endif