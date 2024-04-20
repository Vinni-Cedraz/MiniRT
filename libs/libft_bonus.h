/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/20 19:31:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

typedef struct s_nodes	t_node;
typedef unsigned int	t_ui;
typedef struct s_shape 	t_shape;

typedef struct s_nodes
{
	double				t;
	const t_shape		*object;
	t_node				*next;
}						t_node;

// LINKED LISTS BASIC FUNCTIONS
// ft_lstnew creates a new node
t_node					*ft_lstnew(double content, const t_shape *obj);
// ft_lstadd_back adds a new element at the end of a list
void					ft_lstadd_back(t_node **head, t_node *new_node);
// ft_lstadd_front adds a new element at the beginning of a list
void					ft_lstadd_front(t_node **head, t_node *new_node);
// ft_lstfree frees each node in a list and frees the list itself at the end
void					ft_lstfree(t_node **list);

// LINKED LISTS SPECIFIC OPERATIONS
// ft_lstlast returns the last element of the list
t_node					*ft_lstlast(t_node *first_node);
// ft_lstsize returns the number of elements in a list
int						ft_lstsize(t_node *first_node);
// ft_lst_print prints the content of a list
void					ft_lstprint(t_node **lst);
// adds a node at a specific point in the list and returns a pointer to it
t_node					*ft_lstadd_here(t_node **lst, t_node *n, t_ui index);
// del a node at a given index
void					ft_lstdel_here(t_node **lst, t_ui index);
// returns a pointer to the node at the index point in the list
t_node					*ft_lstgetby_index(t_node *lst, t_ui index);
// returns the index at which a given content is found within a list
int						ft_lstgetby_content(t_node *lst, void *content);
// frees the last node of a list
void					ft_lstshift(t_node **lst);
// frees the first node of a list
t_node					*ft_lstpop(t_node **lst);
// makes a list become a circular list
void					ft_lst_circular(t_node **head);
// frees a circular list
void					ft_lstcircular_free(t_node **head);

#endif
