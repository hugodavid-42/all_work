/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:57:43 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/04 16:32:12 by hdavid           ###   ########.fr       */
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
void	selectionSort(Stack **stackA, Stack **stackB, int len);
void	bubbleSort(Stack **stackA, Stack **stackB, int len);

/* Utils */

// sa && sb
// Swap the first two elements at the top of stack.
// Do nothing if there is only one or no elements.
void	ft_swapA(Stack **head);
void	ft_swapB(Stack **head);

// ss
// sa and sb at the same time.
void	ft_swap2Stack(Stack **stackA, Stack **stackB);

// pa && pb
// Take the first element at the top of a stack and put it at the top of the other.
// Do nothing if b is empty.
void ft_pushAndPopA(Stack **stackA, Stack **stackB);
void ft_pushAndPopB(Stack **stackA, Stack **stackB);

// ra && rb
// Shift up all elements of a stack by one.
// The first element becomes the last one.
void	ft_rotateA(Stack **head);
void	ft_rotateB(Stack **head);

// rr
// ra and rb at the same time.
void	ft_rotate2Stack(Stack **stackA, Stack **stackB);

// rra && rrb
// Shift down all elements of a stack by one.
// The last element becomes the first one.
void	ft_reverseRotateB(Stack **head);
void	ft_reverseRotateA(Stack **head);

// rrr
// rra and rrb at the same time.
void	ft_reverseRotate2Stack(Stack **stackA, Stack **stackB);

/* Others */
Stack *createNode(int content);
void    printStack(Stack *stack);
Stack	*ft_lstlast(Stack *lst);
int	ft_lstlen(Stack *head);
float compute_disorder(Stack *head);

#endif
