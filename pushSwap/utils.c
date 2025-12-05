/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:48:41 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/05 16:59:58 by hdavid           ###   ########.fr       */
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

void push(Stack **head, int i)
{
	Stack *newNode = createNode(i);
	newNode->next = *head;
	*head = newNode;
}

/*=========== Utils algo ===============*/

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

int	ft_swapA(Stack **head)
{
	Stack	*next = (*head)->next;
	int temp;

	temp = (*head)->data;
	(*head)->data = next->data;
	next->data = temp;
	printf("sa\n");
	return 1;
}

int	ft_swapB(Stack **head)
{
	Stack	*next = (*head)->next;
	int temp;

	temp = (*head)->data;
	(*head)->data = next->data;
	next->data = temp;
	printf("sb\n");
	return 1;
}

/*================== SS ==================*/

int	ft_swap2Stack(Stack **stackA, Stack **stackB)
{
	// stackA
	Stack	*next = (*stackA)->next;
	int temp;
	temp = (*stackA)->data;
	(*stackA)->data = next->data;
	next->data = temp;

	//stackB
	next = (*stackB)->next;
	temp = (*stackB)->data;
	(*stackB)->data = next->data;
	next->data = temp;

	printf("ss\n");
	return 1;
}

/*================== PA && PB ==================*/

int ft_pushAndPopA(Stack **stackA, Stack **stackB) 
{
	Stack *newNode = createNode((*stackB)->data);
	newNode->next = *stackA;
	*stackA = newNode;
	*stackB = removeFirstNode(*stackB);
	printf("pa\n");
	return 1;
}

int ft_pushAndPopB(Stack **stackA, Stack **stackB) 
{
	Stack *newNode = createNode((*stackB)->data);
	newNode->next = *stackA;
	*stackA = newNode;
	*stackB = removeFirstNode(*stackB);
	printf("pb\n");
	return 1;
}

/*================== Rotate ==================*/

int	ft_rotateA(Stack **head)
{
	if(!(*head)->next)
		return 0;
	Stack *last = ft_lstlast(*head);
	int temp = (*head)->data;

	*head = removeFirstNode(*head);
	last->next = createNode(temp);
	printf("ra\n");
	return 1;
}

int	ft_rotateB(Stack **head)
{
	if(!(*head)->next)
		return 0;
	Stack *last = ft_lstlast(*head);
	int temp = (*head)->data;

	*head = removeFirstNode(*head);
	last->next = createNode(temp);
	printf("rb\n");
	return 1;
}

int	ft_rotate2Stack(Stack **stackA, Stack **stackB)
{
	// stackA
	if(!(*stackA)->next || !(*stackB)->next)
		return 0;
	Stack *last = ft_lstlast(*stackA);
	int temp = (*stackA)->data;
	*stackA = removeFirstNode(*stackA);
	last->next = createNode(temp);

	// stackB
	last = ft_lstlast(*stackB);
	temp = (*stackB)->data;
	*stackB = removeFirstNode(*stackB);
	last->next = createNode(temp);
	printf("rr\n");
	return 1;
}

/*============= Reverse rotate ===============*/

int	ft_reverseRotateA(Stack **head)
{
	Stack *newNode;
	int temp = ft_lstlast(*head)->data;
	newNode = createNode(temp);
	newNode->next = *head;
	removeLastNode(*head);
	*head = newNode;
	printf("rra\n");
	return 1;
}

int	ft_reverseRotateB(Stack **head)
{
	Stack *newNode;
	int temp = ft_lstlast(*head)->data;
	newNode = createNode(temp);
	newNode->next = *head;
	removeLastNode(*head);
	*head = newNode;
	printf("rrb\n");
	return 1;
}

int	ft_reverseRotate2Stack(Stack **stackA, Stack **stackB)
{
	// stackA
	Stack *newNode;
	int temp = ft_lstlast(*stackA)->data;
	newNode = createNode(temp);
	newNode->next = *stackA;
	removeLastNode(*stackA);
	*stackA = newNode;

	// stackB
	temp = ft_lstlast(*stackB)->data;
	newNode = createNode(temp);
	newNode->next = *stackB;
	removeLastNode(*stackB);
	*stackB = newNode;
	printf("rrr\n");
	return 1;
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