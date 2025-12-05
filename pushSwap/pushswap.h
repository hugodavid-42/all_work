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
int	ft_swapA(Stack **head);
int	ft_swapB(Stack **head);

// ss
// sa and sb at the same time.
int	ft_swap2Stack(Stack **stackA, Stack **stackB);

// pa && pb
// Take the first element at the top of a stack and put it at the top of the other.
// Do nothing if b is empty.
int ft_pushAndPopA(Stack **stackA, Stack **stackB);
int ft_pushAndPopB(Stack **stackA, Stack **stackB);

// ra && rb
// Shift up all elements of a stack by one.
// The first element becomes the last one.
int	ft_rotateA(Stack **head);
int	ft_rotateB(Stack **head);

// rr
// ra and rb at the same time.
int	ft_rotate2Stack(Stack **stackA, Stack **stackB);

// rra && rrb
// Shift down all elements of a stack by one.
// The last element becomes the first one.
int	ft_reverseRotateB(Stack **head);
int	ft_reverseRotateA(Stack **head);

// rrr
// rra and rrb at the same time.
int	ft_reverseRotate2Stack(Stack **stackA, Stack **stackB);

/* Others */
Stack *createNode(int content);
void    printStack(Stack *stack);
Stack	*ft_lstlast(Stack *lst);
int	ft_lstlen(Stack *head);
float compute_disorder(Stack *head);
void push(Stack **head, int i);

#endif
