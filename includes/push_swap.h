/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:29:42 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/19 16:48:53 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_push
{
	struct s_list	*pile_a;
	struct s_list	*pile_b;
}				t_push;

typedef struct s_list
{
	struct s_data	*content;
	struct s_list	*next;
	struct s_list	*previous;
	int				end;
}				t_list;

typedef struct s_data
{
	long int	number;
	int			rank;
}				t_data;

/* UTILS */

long int		ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(const char *s);
int				tab_list(t_list *list, int i);
char			**ft_split(char const *s, char c);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_putstr(char *s);
void			ft_putchar(char c);
void			del(void *content);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
t_list			*ft_lstnew(t_data *data, long int number, int i);
t_list			*ft_lstlast(t_list *lst);
t_data			*init_data(t_data *data, long int number);

/* PARSING */
int				handle_error(t_push *list);
int				store_list(t_push *push, char **av);
int				sort_rank(t_list *list, int i);
int				clear_memory(t_list *list);
void			loop_list(t_list *list);


/* ACTIONS */
void			swap(t_list *list_a, t_list *list_b, char c);
void			push(t_list *list_a, t_list *list_b, char c);
void			rotate(t_list *list_a, t_list *list_b, char c);
void			r_rotate(t_list *list_a, t_list *list_b, char c);

/* PUSH_SWAP */
void			push_swap(t_push *ps);

#endif