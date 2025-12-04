/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psi-mous <psi-mous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:33:25 by psi-mous          #+#    #+#             */
/*   Updated: 2025/12/01 14:54:04 by psi-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	free_lst(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

t_list	*fill_stacka(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*new;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
		{
			free_lst(stack_a);
			write(2, "Error", 6);
			return (NULL);
		}
		ft_lstadd_front(&stack_a, new);
		i++;
	}
	return (stack_a);
}
