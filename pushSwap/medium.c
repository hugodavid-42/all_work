#include "pushswap.h"
#include <stdio.h>


// void partionning(Stack **stackA, Stack **stackB, int len)
// {
// 	int part = (len / 4);
// 	int i = 0;
// 	while(*stackA)
// 	{
// 		while(i < part)
// 		{
// 			ft_pushAndPop(&*stackB, &*stackA);
// 			printf("test\n");
// 			printStack(*stackA);
// 			i ++;
// 		}
// 		i = 0;
// 		selectionSort(&*stackB, &*stackA, part);
// 	}
// 	selectionSort(&*stackB, &*stackA, len);
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
// 	stackA->next->next->next->next->next->next = createNode(7);
// 	stackA->next->next->next->next->next->next->next = createNode(6);
// 	stackA->next->next->next->next->next->next->next->next = createNode(48);
// 	stackA->next->next->next->next->next->next->next->next->next = createNode(78);

// 	printf("Disorder = %f\n", compute_disorder(stackA));


// 	int len = ft_lstlen(stackA);
// 	//printf("%d\n", len);
// 	// printStack(stackA);
// 	// printStack(stackB);
// 	partionning(&stackA, &stackB, len);
// 	// printStack(stackA);
// 	// printStack(stackB);
// 	printf("Disorder = %f\n", compute_disorder(stackB));


// 	return 0;
	
// }

