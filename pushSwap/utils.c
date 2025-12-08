/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:48:41 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/08 13:47:25 by hdavid           ###   ########.fr       */
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

void	sa(Stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	printf("sa\n");
}

void	sb(Stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	printf("sb\n");
}

/*================== ss ==================*/


void    ss(Stack **a, Stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
    printf("ss\n");
}


/*================== pa && pb ==================*/


void    pa(Stack **stackA, Stack **stackB)
{
    if (!stackB || !*stackB) 
		return ;
    Stack *x = *stackB;
    *stackB = x->next;
    x->next = *stackA;
    *stackA = x;
    printf("pa\n");
}

void    pb(Stack **stackA, Stack **stackB) 
{
    if (!stackA || !*stackA)
		return ;
    Stack *x = *stackA;
    *stackA = x->next;
    x->next = *stackB;
    *stackB = x;
    printf("pb\n");
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


void    ra(Stack **a)
{
    if (!a || !*a || !(*a)->next) 
		return ;
	rotate(a);
    printf("ra\n");
}


void    rb(Stack **b)
{
    if (!b || !*b || !(*b)->next) 
		return ;
	rotate(b);
    printf("rb\n");
}

void	rr(Stack **a, Stack **b)
{
    if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next) 
		return ;
	rotate(a);
	rotate(b);
	printf("rr\n");
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


void    rra(Stack **a)
{
    if (!a || !*a || !(*a)->next) 
		return ;
	rev_rotate(a);
    printf("rra\n");
}


void    rrb(Stack **b)
{
    if (!b || !*b || !(*b)->next) 
		return ;
	rev_rotate(b);
    printf("rrb\n");
}

void	rrr(Stack **a, Stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	rev_rotate(a);
	rev_rotate(b);
	printf("rrr\n");
}