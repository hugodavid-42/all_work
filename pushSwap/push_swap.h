/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psi-mous <psi-mous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:23:59 by psi-mous          #+#    #+#             */
/*   Updated: 2025/12/01 15:52:27 by psi-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

//creation d'un type pour les nodes: les nombres fournis qui seront stockes
typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}					t_list;

int		ft_isnumber(char *str);
int		has_dup(int argc, char *argv[]);
int		isargv_ok(int argc, char *argv[]);

long    ft_atol(char *str);
int		ft_atoi(char *str);

t_list	*ft_lstnew(int nbr);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	free_lst(t_list *stack);
t_list	*fill_stacka(int argc, char *argv[]);

#endif
