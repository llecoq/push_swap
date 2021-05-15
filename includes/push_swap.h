/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:29:42 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/15 16:10:04 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}				t_list;

/* UTILS */

int				ft_isdigit(int c);
long int		ft_atoi(const char *str);
int				store_list(t_list *list, char **av);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_putstr(char *s);
void			ft_putchar(char c);
void			clear_memory(t_list *pile_a, t_list *pile_b);
t_list			*ft_lstnew(int content);
t_list			*ft_lstlast(t_list *lst);

/* PARSING */
int				handle_error(t_list *list);

/* PUSH_SWAP */

#endif