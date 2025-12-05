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

/*=========== Utils ===============*/

int	findMax(Stack *stackA)
{
	int max = stackA->data;
	while(stackA)
	{
		if(stackA->data > max)
			max = stackA->data;
		stackA = stackA->next;
	}
	return max;
}

int	findMin(Stack *stackA)
{
	int min = stackA->data;
	while(stackA)
	{
		if(stackA->data < min)
			min = stackA->data;
		stackA = stackA->next;
	}
	return min;
}

int		locateMin(Stack *stackA)
{
	int min = findMin(stackA);
	int i = 0;
	while (stackA)
	{
		if (stackA->data == min)
			return i;
		i ++;
		stackA = stackA->next;
	}
	return i;
}

/*=========== Sorting Algo =================*/

int	sort3Number(Stack **stackA)
{
	int a = (*stackA)->data;
	int b = (*stackA)->next->data;
	int c = (*stackA)->next->next->data;
	int mov = 0;

	// 2,1,3
	if (a > b && b < c && a < c)
		mov += ft_swapA(stackA);
	// 3,2,1
	else if (a > b && b > c && a > c)
	{
		mov += ft_swapA(stackA);
		mov += ft_reverseRotateA(stackA);
	}
	// 3,1,2
	else if (a > b && b < c && a > c)
		mov += ft_rotateA(stackA);
	// 1,3,2
	else if (a < b && b > c && a < c)
	{
		mov += ft_swapA(stackA);
		mov += ft_rotateA(stackA);
	}
	// 2,3,1
	else if (a < b && b > c && a > c)
		mov += ft_reverseRotateA(stackA);
	return mov;
}


int sort5Number(Stack **stackA, Stack **stackB) 
{
	int mov = 0;
	int min = findMin(*stackA);
	while((*stackA)->data != min)
	{
		mov += ft_rotateA(stackA);
	}
    mov += ft_pushAndPopA(stackB, stackA);
	min = findMin(*stackA);
	while((*stackA)->data != min)
	{
		ft_rotateA(stackA);
	}
    mov += ft_pushAndPopA(stackB, stackA);
    mov += sort3Number(stackA);
    if ((*stackB)->data < (*stackB)->next->data) {
        mov += ft_swapB(stackB);
    }
    while (*stackB) 
	{
			mov += ft_pushAndPopB(stackA, stackB);
    }
	while((*stackA)->data != findMin(*stackA))
		mov += ft_rotateA(stackA);
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
                mov += ft_rotateA(stackA);
        } 
		else 
		{
            int k = len - pos;
            while (k-- > 0)
                mov += ft_reverseRotateA(stackA);
        }
        mov += ft_pushAndPopA(stackB, stackA);
    }
    while(*stackB)
		mov += ft_pushAndPopB(stackA, stackB);
	return mov;
}

void push(Stack **head, int i)
{
	Stack *newNode = createNode(i);
	newNode->next = *head;
	*head = newNode;
}

// int main(void)
// {
// 	int size = 100;
// 	Stack *stackB = NULL;
// 	Stack *stackA = NULL;
// 	int *arr = (int *)malloc(sizeof(int) * size);
// 	if (arr == NULL)
// 		return printf("Memory not alloctaed\n");
// 	int i = 0;
// 	while(i < size)
// 	{
// 		arr[i] = i;
// 		i ++;
// 	}
//     randomize (arr, size);
// 	i = 0;
// 	while(i < size)
// 	{
// 		push(&stackA, arr[i]);
// 		i ++;
// 	}
// 	printf("Disorder = %f\n", compute_disorder(stackA));

// 	printStack(stackA);
// 	if(size == 3)
// 		printf("Total moove : %d\n", sort3Number(&stackA));
// 	else if (size == 5)
// 		printf("Total moove : %d\n", sort5Number(&stackA, &stackB));
// 	else 
// 		printf("Total moove : %d\n", insertionSort(&stackA, &stackB));
// 	printf("===========================================\n");
// 	printStack(stackA);
// 	//printStack(stackB);
// 	printf("Disorder = %f\n", compute_disorder(stackA));
// 	return 0;
	
// }
