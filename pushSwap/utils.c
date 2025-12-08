/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:48:41 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/08 10:15:02 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Stack Example :
//         Top of the stack
//         /
//         10      ------
//         4            |
//         16           | Stack of size 6
//         72           |
//         9            |
//         3       ------    
//         /
//Bottom of the stack

#include "pushswap.h"
#include <stdio.h>

/*================== sa && sb ==================*/

static void	swap(Stack **s)
{
	if (!s || !*s || !(*s)->next)
		return;
	Stack	*next = (*s)->next;
	int temp;

	temp = (*s)->data;
	(*s)->data = next->data;
	next->data = temp;
}

int	sa(Stack **a)
{
	if (!a || !*a || !(*a)->next)
		return 0;
	swap(a);
	printf("sa\n");
	return 1;
}

int	sb(Stack **b)
{
	if (!b || !*b || !(*b)->next)
		return 0;
	swap(b);
	printf("sb\n");
	return 1;
}

/*================== ss ==================*/


int    ss(Stack **a, Stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return 0;
	swap(a);
	swap(b);
    printf("ss\n");
	return 1;
}


/*================== pa && pb ==================*/


int    pa(Stack **stackA, Stack **stackB)
{
    if (!stackB || !*stackB) 
		return 0;
    Stack *x = *stackB;
    *stackB = x->next;
    x->next = *stackA;
    *stackA = x;
    printf("pa\n");
	return 1;
}

int    pb(Stack **stackA, Stack **stackB) 
{
    if (!stackA || !*stackA)
		return 0;
    Stack *x = *stackA;
    *stackA = x->next;
    x->next = *stackB;
    *stackB = x;
    printf("pb\n");
	return 1;
}


/*================== ra && rb && rr ==================*/


static void rotate(Stack **s)
{
    if (!s || !*s || !(*s)->next) 
		return ;
    Stack *first = *s;
    Stack *last = *s;
    while (last->next) 
		last = last->next;
    *s = first->next;
    first->next = NULL;
    last->next = first;
}


int    ra(Stack **a)
{
    if (!a || !*a || !(*a)->next) 
		return 0;
	rotate(a);
    printf("ra\n");
	return 1;
}


int    rb(Stack **b)
{
    if (!b || !*b || !(*b)->next) 
		return 0;
	rotate(b);
    printf("rb\n");
	return 1;
}

int	rr(Stack **a, Stack **b)
{
    if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next) 
		return 0;
	rotate(a);
	rotate(b);
	printf("rr\n");
	return 1;
}

/*============= rra & rrb && rrr ===============*/


static void rev_rotate(Stack **s)
{
    if (!s || !*s || !(*s)->next) 
		return ;
    Stack *prev = NULL;
	Stack *last = *s;
    while (last->next)
	{
		prev = last;
		last = last->next;
	}
    prev->next = NULL;
    last->next = *s;
    *s = last;
}


int    rra(Stack **a)
{
    if (!a || !*a || !(*a)->next) 
		return 0;
	rev_rotate(a);
    printf("rra\n");
	return 1;
}


int    rrb(Stack **b)
{
    if (!b || !*b || !(*b)->next) 
		return 0;
	rev_rotate(b);
    printf("rrb\n");
	return 1;
}

int	rrr(Stack **a, Stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return 0;
	// stackB
	rev_rotate(a);
	rev_rotate(b);
	printf("rrr\n");
	return 1;
}