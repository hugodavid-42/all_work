/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:48:41 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/04 16:40:09 by hdavid           ###   ########.fr       */
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

/*================== Utils==================*/

Stack *createNode(int content)
{
    Stack *newnode;

    newnode = malloc(sizeof(Stack));
    newnode->data = content;
    newnode->next = NULL;
    return (newnode);
}

void    printStack(Stack *stack)
{
    while(stack)
    {
        printf("%d --> ", stack->data);
        stack = stack->next;
    }
    printf("NULL");
    printf("\n");
}

int	ft_lstlen(Stack *head)
{
	int count;

	count = 0;
	while(head)
	{
		head = head->next;
		count ++;
	}
	return (count);
}

/*================== Find Last ==================*/


Stack	*ft_lstlast(Stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*================== Remove ==================*/

Stack *removeLastNode(Stack *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Stack *secondLast = head;
    while (secondLast->next->next != NULL)
    {
        secondLast = secondLast->next;
    }
    free(secondLast->next);
    secondLast->next = NULL;

    return head;
}

Stack	*removeFirstNode(Stack *head)
{
	if(head == NULL)
		return NULL;
	Stack *temp = head;
	head = head->next;
	free(temp);

	return head;
}

/*================== SA && SB ==================*/

void	ft_swapA(Stack **head)
{
	Stack	*next = (*head)->next;
	int temp;

	temp = (*head)->data;
	(*head)->data = next->data;
	next->data = temp;
	printf("sa\n");
}

void	ft_swapB(Stack **head)
{
	Stack	*next = (*head)->next;
	int temp;

	temp = (*head)->data;
	(*head)->data = next->data;
	next->data = temp;
	printf("sb\n");
}

/*================== SS ==================*/

void	ft_swap2Stack(Stack **stackA, Stack **stackB)
{
	ft_swapA(stackA);
	ft_swapB(stackB);
}

/*================== PA && PB ==================*/

void ft_pushAndPopA(Stack **stackA, Stack **stackB) 
{
	Stack *newNode = createNode((*stackB)->data);
	newNode->next = *stackA;
	*stackA = newNode;
	*stackB = removeFirstNode(*stackB);
	printf("pa\n");
}

void ft_pushAndPopB(Stack **stackA, Stack **stackB) 
{
	Stack *newNode = createNode((*stackB)->data);
	newNode->next = *stackA;
	*stackA = newNode;
	*stackB = removeFirstNode(*stackB);
	printf("pb\n");
}

/*================== Rotate ==================*/

void	ft_rotateA(Stack **head)
{
	if(!(*head)->next)
		return ;
	Stack *last = ft_lstlast(*head);
	int temp = (*head)->data;

	*head = removeFirstNode(*head);
	last->next = createNode(temp);
	printf("ra\n");
}

void	ft_rotateB(Stack **head)
{
	if(!(*head)->next)
		return ;
	Stack *last = ft_lstlast(*head);
	int temp = (*head)->data;

	*head = removeFirstNode(*head);
	last->next = createNode(temp);
	printf("rb\n");
}

void	ft_rotate2Stack(Stack **stackA, Stack **stackB)
{
	ft_rotateA(stackA);
	ft_rotateB(stackB);
}

/*============= Reverse rotate ===============*/

void	ft_reverseRotateA(Stack **head)
{
	Stack *newNode;
	int temp = ft_lstlast(*head)->data;
	newNode = createNode(temp);
	newNode->next = *head;
	removeLastNode(*head);
	*head = newNode;
	printf("rra\n");
}

void	ft_reverseRotateB(Stack **head)
{
	Stack *newNode;
	int temp = ft_lstlast(*head)->data;
	newNode = createNode(temp);
	newNode->next = *head;
	removeLastNode(*head);
	*head = newNode;
	printf("rrb\n");
}

void	ft_reverseRotate2Stack(Stack **stackA, Stack **stackB)
{
	ft_reverseRotateA(stackA);
	ft_reverseRotateB(stackB);
}

/*================== Main ==================*/

// int main (void)
// {
//     Stack *stackA = createNode(40);
//     stackA->next = createNode(10);
//     stackA->next->next = createNode(30);
//     stackA->next->next->next = createNode(20);
// 	stackA->next->next->next->next = createNode(50);

// 	Stack *stackB = createNode(60);
//     stackB->next = createNode(70);
//     stackB->next->next = createNode(80);
//     stackB->next->next->next = createNode(90);

// // 	printf("==================  Initiate Stack  ===================\n");

// // 	printStack(stackA);
// // 	printStack(stackB);

// // 	printf("==================  Push && Pop  ===================\n");
// // 	ft_pushAndPop(&stackA, &stackB);
// // 	printStack(stackA);
//  	printStack(stackB);

// // 	printf("==================  Swap  ===================\n");
// 	ft_swap(&stackB);
// 	printStack(stackB);
// 	printStack(stackA);
// 	ft_rotate(&stackA);
// 	printStack(stackA);

// 	ft_reverseRotate(&stackA);
// 	printStack(stackA);


// 	return 0;

// }