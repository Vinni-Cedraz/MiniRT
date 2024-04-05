/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/17 16:44:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

typedef struct s_nodes	t_intersect;
typedef unsigned int	t_ui;
typedef struct s_sphere	t_sphere;

typedef struct s_nodes
{
	double				t;
	t_sphere			*object;
}						t_intersect;

// LINKED LISTS BASIC FUNCTIONS
// ft_lstnew creates a new node
t_intersect					*ft_lstnew(double content);
// ft_lstadd_back adds a new element at the end of a list
void					ft_lstadd_back(t_intersect **head, t_intersect *new_node);
// ft_lstadd_front adds a new element at the beginning of a list
void					ft_lstadd_front(t_intersect **head, t_intersect *new_node);
// ft_lstfree frees each node in a list and frees the list itself at the end
void					ft_lstfree(t_intersect **list);

// LINKED LISTS SPECIFIC OPERATIONS
// ft_lstlast returns the last element of the list
t_intersect					*ft_lstlast(t_intersect *first_node);
// ft_lstsize returns the number of elements in a list
int						ft_lstsize(t_intersect *first_node);
// ft_lst_print prints the content of a list
void					ft_lstprint(t_intersect **lst);
// adds a node at a specific position in the list and returns a pointer to it
t_intersect					*ft_lstadd_here(t_intersect **lst, t_intersect *n, t_ui index);
// del a node at a given index
void					ft_lstdel_here(t_intersect **lst, t_ui index);
// returns a pointer to the node at the index position in the list
t_intersect					*ft_lstgetby_index(t_intersect *lst, t_ui index);
// returns the index at which a given content is found within a list
int						ft_lstgetby_content(t_intersect *lst, void *content);
// frees the last node of a list
void					ft_lstshift(t_intersect **lst);
// frees the first node of a list
t_intersect					*ft_lstpop(t_intersect **lst);
// makes a list become a circular list
void					ft_lst_circular(t_intersect **head);
// frees a circular list
void					ft_lstcircular_free(t_intersect **head);

#endif
