/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:57:43 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/05 17:01:27 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
    struct stack   *next;
    int				data;
}   Stack;


/* Sorting algorithms */
int insertionSort(Stack **stackA, Stack **stackB);

/* Shuffle algo */
void randomize ( int arr[], int n );

/* Utils */
int	findMax(Stack *stackA);
int	findMin(Stack *stackA);
int	locateMin(Stack *stackA);

// sa && sb
// Swap the first two elements at the top of stack.
// Do nothing if there is only one or no elements.
int	sa(Stack **a);
int sb(Stack **b);

// ss
// sa and sb at the same time.
int	ss(Stack **stackA, Stack **stackB);

// pa && pb
// Take the first element at the top of a stack and put it at the top of the other.
// Do nothing if b is empty.
int pa(Stack **stackA, Stack **stackB);
int pb(Stack **stackA, Stack **stackB);

// ra && rb
// Shift up all elements of a stack by one.
// The first element becomes the last one.
int	ra(Stack **a);
int	rb(Stack **b);

// rr
// ra and rb at the same time.
int	rr(Stack **stackA, Stack **stackB);

// rra && rrb
// Shift down all elements of a stack by one.
// The last element becomes the first one.
int	rra(Stack **a);
int	rrb(Stack **b);

// rrr
// rra and rrb at the same time.
int	rrr(Stack **stackA, Stack **stackB);

/* Others */
Stack *createNode(int content);
void    printStack(Stack *stack);
Stack	*ft_lstlast(Stack *lst);
int	ft_lstlen(Stack *head);
float compute_disorder(Stack *head);
void push(Stack **head, int i);
void free_stack(Stack **stack);

#endif
