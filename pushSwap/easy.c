/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:52:50 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/05 16:48:24 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

/*=========== Sorting Algo =================*/

int	sort3Number(Stack **stackA)
{
	int a = (*stackA)->data;
	int b = (*stackA)->next->data;
	int c = (*stackA)->next->next->data;
	int mov = 0;

	// 2,1,3
	if (a > b && b < c && a < c)
		mov += sa(stackA);
	// 3,2,1
	else if (a > b && b > c && a > c)
	{
		mov += sa(stackA);
		mov += rra(stackA);
	}
	// 3,1,2
	else if (a > b && b < c && a > c)
		mov += ra(stackA);
	// 1,3,2
	else if (a < b && b > c && a < c)
	{
		mov += sa(stackA);
		mov += ra(stackA);
	}
	// 2,3,1
	else if (a < b && b > c && a > c)
		mov += rra(stackA);
	return mov;
}


int sort5Number(Stack **stackA, Stack **stackB) 
{
	int mov = 0;
	int min = findMin(*stackA);
	while((*stackA)->data != min)
	{
		mov += ra(stackA);
	}
    mov += pb(stackA, stackB);
	min = findMin(*stackA);
	while((*stackA)->data != min)
	{
		ra(stackA);
	}
    mov += pb(stackA, stackB);
    mov += sort3Number(stackA);
    if ((*stackB)->data < (*stackB)->next->data) {
        mov += sb(stackB);
    }
    while (*stackB) 
	{
			mov += pa(stackA, stackB);
    }
	while((*stackA)->data != findMin(*stackA))
		mov += ra(stackA);
	return mov;
}

int insertionSort(Stack **stackA, Stack **stackB)
{
	int mov = 0;
    while (*stackA)
    {
        int len = ft_lstlen(*stackA);
        int pos = locateMin(*stackA);

        if (pos <= len / 2) 
		{
            while (pos-- > 0)
                mov += ra(stackA);
        } 
		else 
		{
            int k = len - pos;
            while (k-- > 0)
                mov += rra(stackA);
        }
        mov += pb(stackA, stackB);
    }
    while(*stackB)
		mov += pa(stackA, stackB);
	return mov;
}

int main(void)
{
	int size = 5;
	Stack *stackB = NULL;
	Stack *stackA = NULL;
	int *arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return printf("Memory not alloctaed\n");
	int i = 0;
	while(i < size)
	{
		arr[i] = i;
		i ++;
	}
    randomize (arr, size);
	i = 0;
	while(i < size)
	{
		push(&stackA, arr[i]);
		i ++;
	}
	printf("Disorder = %f\n", compute_disorder(stackA));

	printStack(stackA);
	if(size == 3)
		printf("Total moove : %d\n", sort3Number(&stackA));
	else if (size == 5)
		printf("Total moove : %d\n", sort5Number(&stackA, &stackB));
	else 
		printf("Total moove : %d\n", insertionSort(&stackA, &stackB));
	printf("===========================================\n");
	printStack(stackA);
	//printStack(stackB);
	printf("Disorder = %f\n", compute_disorder(stackA));
		free(arr);
	free_stack(&stackA);
	return 0;
	
}
