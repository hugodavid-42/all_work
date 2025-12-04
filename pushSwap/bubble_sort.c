#include "pushswap.h"
#include <stdio.h>

int ft_compare(int data1, int data2)
{
    return (data1 - data2);
}

// void bubbleSort(Stack **begin_list)
// {
//     Stack *current;
//     Stack *next;
//     int temp;

//     int swap = 1;
//     while(swap)
//     {
//         swap = 0;
//         current = *begin_list;
//         while(current->next)
//         {
//             next = current->next;
//             if(ft_compare(current->data, next->data) > 0)
//             {
//                 temp = current->data;
//                 current->data = next->data;
//                 next->data = temp;
//                 swap = 1;
//             }
//             current = current->next;
//         }
//     }
// }


// void bubbleSort(Stack **stackA, int len)
// {    
// 	if (len <= 1) 
// 		return;
// 	int i;
// 	int j;
// 	i = 0;
// 	while (i < len)
// 	{
//         Stack *current = *stackA;
// 		j = i + 1;
// 		while (j < len)
// 		{
//             if (current->data > current->next->data) {
//                 ft_swap(current);
//             }
//             current = current->next;
// 			j ++;
//         }
// 		i ++;
//     }
// }

// void bubbleSort(Stack **stackA, Stack **stackB, int len)
// {
// 	int i = 0;

// 	while(*stackA)
// 	{
// 		i = 0;
// 		while(i < len)
// 		{
// 			if((*stackA)->data <= (*stackB)->next->data)
// 				ft_pushAndPop(&*stackB, &*stackA);
// 			ft_rotate(stackB);
// 			i ++;
// 		}
// 		len --;
// 		ft_rotate(stackA);
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

// 	int len = ft_lstlen(stackA);
// 	printf("Disorder = %f\n", compute_disorder(stackA));

// 	printStack(stackA);
// 	bubbleSort(&stackA, &stackB, len);
// 	printStack(stackA);
// 	printf("Disorder = %f\n", compute_disorder(stackA));


// 	return 0;
// }