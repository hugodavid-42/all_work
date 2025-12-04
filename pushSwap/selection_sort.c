/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:52:50 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/04 19:28:55 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

// void	sendToStackA(Stack **stackA, Stack **stackB)
// {
// 	while(*stackB)
// 	{
// 		ft_pushAndPopB(&(*stackA), &(*stackB));
// 	}
// }

// void selectionSort(Stack **stackA, Stack **stackB, int len)
// {
// 	int i = 0;
// 	int min = (*stackA)->data;
// 	while((*stackA)->next)
// 	{
// 		min = (*stackA)->data;
// 		i = 0;
// 		while(i <= len)
// 		{
// 			ft_rotateA(&(*stackA));
// 			if ((*stackA)->data < min)
// 				min = (*stackA)->data;
// 			i ++;
// 		}
// 		i = 0;
// 		while(i <= len)
// 		{
// 			if ((*stackA)->data == min)
// 				break ;
// 			ft_rotateA(&(*stackA));
// 			i ++;
// 		}
// 		ft_pushAndPopA(&(*stackB), &(*stackA));
// 		len --;
// 	}
// 	ft_pushAndPopA(&(*stackB), &(*stackA));
// 	sendToStackA(&*stackA, &*stackB);
// }

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

void	sort3Number(Stack **stackA)
{
	int a = (*stackA)->data;
	int b = (*stackA)->next->data;
	int c = (*stackA)->next->next->data;

	// 2,1,3
	if (a > b && b < c && a < c)
		ft_swapA(&*stackA);
	// 3,2,1
	else if (a > b && b > c && a > c)
	{
		ft_swapA(&*stackA);
		ft_reverseRotateA(&*stackA);
	}
	// 3,1,2
	else if (a > b && b < c && a > c)
		ft_rotateA(&*stackA);
	// 1,3,2
	else if (a < b && b > c && a < c)
	{
		ft_swapA(&*stackA);
		ft_rotateA(&*stackA);
	}
	// 2,3,1
	else if (a < b && b > c && a > c)
		ft_reverseRotateA(&*stackA);
}


void sort5Number(Stack **stackA, Stack **stackB) 
{
    ft_pushAndPopA(&*stackB, &*stackA);
    ft_pushAndPopA(&*stackB, &*stackA);

    sort3Number(&*stackA);

    if ((*stackB)->data < (*stackB)->next->data) {
        ft_swapB(stackB);
    }


    while (*stackB) 
	{
        if ((*stackA && (*stackA)->data < (*stackB)->data) && (ft_lstlast(*stackA)->data > (*stackB)->data)) 
            ft_rotateA(stackA);
		else 
            ft_pushAndPopB(stackA, stackB);
    }
	while((*stackA)->data != findMin(*stackA))
		ft_rotateA(&*stackA);
}


int main(void)
{
	Stack *stackB = NULL;

	Stack *stackA = createNode(5);
	stackA->next =createNode(4);
	stackA->next->next = createNode(3);
	stackA->next->next->next = createNode(2);
	stackA->next->next->next->next = createNode(1);
	// stackA->next->next->next->next->next = createNode(60);
	// stackA->next->next->next->next->next->next = createNode(7);
	// stackA->next->next->next->next->next->next->next = createNode(6);
	// stackA->next->next->next->next->next->next->next->next = createNode(48);
	// stackA->next->next->next->next->next->next->next->next->next = createNode(78);

	printf("Disorder = %f\n", compute_disorder(stackA));


	//int len = ft_lstlen(stackA);
	//printf("%d\n", len);
	printStack(stackA);
	//printStack(stackB);
	printf("===========================================\n");
	//selectionSort(&stackA, &stackB, len);
	//sort3Number(&stackA);
	sort5Number(&stackA, &stackB);
	printf("===========================================\n");
	printStack(stackA);
	//printStack(stackB);
	printf("Disorder = %f\n", compute_disorder(stackA));
	return 0;
	
}

