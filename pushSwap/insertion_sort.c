/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:58:26 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/03 17:59:52 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void insertSort(Stack **stackA, Stack **stackB)
// {
// 	ft_pushAndPop(&*stackB, &*stackA);
// 	while(*stackA)
// 	{
// 		while(*stackB)
// 		{
// 			if((*stackA)->data < (*stackB)->data)
// 				ft_pushAndPop(&*stackB, &*stackA);
// 			else
// 				(*stackB)->next;
// 		}
// 		ft_rotate(&*stackA);
// 	}
// }


// int main(void)
// {
// 	Stack *stackB = NULL;

// 	Stack *stackA = createNode(100);
// 	stackA->next =createNode(40);
// 	stackA->next->next = createNode(30);
// 	stackA->next->next->next = createNode(14);
// 	stackA->next->next->next->next = createNode(5);
// 	stackA->next->next->next->next->next = createNode(60);

// 	//int len = ft_lstlen(stackA);
// 	printf("Disorder = %f\n", compute_disorder(stackA));

// 	printStack(stackA);
// 	insertSort(&stackA, &stackB);
// 	printStack(stackB);
// 	printStack(stackA);
// 	printf("Disorder = %f\n", compute_disorder(stackA));


// 	return 0;
// }