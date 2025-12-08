
#include <stdbool.h>
#include "pushswap.h"
#include <stdio.h>

int    *buildArray(Stack *stackA)
{
    int n = ft_lstlen(stackA);
    Stack *current;
    Stack *dataToCompare = stackA;
    int i = 0;
    int index;
    int *arr = malloc(sizeof(int) * n);

    while(i < n)
    {
        index = 0;
        current = stackA;
        while(current)
        {
            if(dataToCompare->data > current->data)
                index ++;
            current = current->next;
        }
        arr[i] = index;
        dataToCompare->index = index;
        dataToCompare = dataToCompare->next;
        i ++;
    }
    return(arr);
}

int sizeChunk(Stack *stackA)
{
	if (stackA == 0)
		return 0;
    int len = ft_lstlen(stackA);
    int chunks = len / 10;
    if (len % 10 != 0)
        chunks ++;
    return (int)(len / chunks);
}

// void findClosestPos(Stack **stackA, int min, int max)
// {
//     int i = 0;
//     int len = ft_lstlen(*stackA);
// 	Stack *tmp = *stackA;

//     while(tmp)
//     {
//         if (tmp->index >= min && tmp->index < max)
//             break ;
//         i ++;
//         tmp = tmp->next;
//     }
//     if (i > len / 2)
//     {
//         while(i-- > 0)
//             rra(stackA);
//     }
//     else
//     {
//         while(i-- > 0)
//             ra(stackA);
//     }
// }


int findClosestPos(Stack **stackA, int min, int max)
{
    int mov = 0;
    if (!stackA || !*stackA) 
        return 0;
    Stack *tmp = *stackA;
    int i = 0;

    while (tmp && !(tmp->index >= min && tmp->index < max)) {
        i++;
        tmp = tmp->next;
    }

    if (!tmp) {
        return 0;
    }
    int len = ft_lstlen(*stackA);
    if (i <= len / 2) {
        while (i-- > 0) 
            mov += ra(stackA);
    } 
    else 
    {
        int steps = len - i;
        while (steps-- > 0) 
            mov += rra(stackA);
    }
    return mov;
}

int    pushA(Stack **stackA, Stack **stackB)
{
    int chunk = sizeChunk(*stackA);
    int i = 0;
    int min = 0;
    int max = chunk;
    int mov = 0;

    while(*stackA)
    {
		i = 0;
        while(i < chunk && *stackA)
        {
			int pos = findClosestPos(stackA, min, max);
            if(pos == 0)
            {
                mov += pb(stackA, stackB);
				i ++;
            }
        }
        min = max;
        max += chunk;
    }
    return mov;
}

int posOfMax(Stack *stackB, int max)
{
    if (!stackB)
        return -1;
    int i = 0;
    Stack *tmp = stackB;
    if (!tmp)
        return -1;

    while(tmp->index != max && tmp)
    {
        i ++;
        tmp = tmp->next;
    }
    return i;
}

int   pushBackB(Stack **stackA, Stack **stackB)
{
    int mov = 0;
    while(*stackB)
    {
        int max = ft_lstlen(*stackB) - 1;
        if((*stackB)->index == max)
            mov += pa(stackA, stackB);
        else if(posOfMax(*stackB, max) <= max / 2)
            mov += rb(stackB);
        else
            mov += rrb(stackB);
    }
    return mov;
}

int chunkSort(Stack **stackA, Stack **stackB)
{
    int mov = 0;

	buildArray(*stackA);
    mov += pushA(stackA, stackB);
    mov += pushBackB(stackA, stackB);
    return mov;
}

// int main(void)
// {
// 	int size = 500;
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
// 	printf("%d\n", sizeChunk(stackA));
// 	//printStack(stackA);
// 	//i = 0;
// 	// Stack *temp = stackA;
// 	// while(i < size)
// 	// {
// 	// 	printf("%d --> ", temp->index);
// 	// 	temp = temp->next;
// 	// 	i ++;
// 	// }
// 	printStack(stackA);

//     printf("\nTotal moove : %i\n", chunkSort(&stackA, &stackB));
// 	// printf("\nTotal moove : %i\n", insertionSort(&stackA, &stackB));

//     printf("\n===========================================\n");
// 	printStack(stackB);
// 	printStack(stackA);
// 	printf("Disorder = %f\n", compute_disorder(stackA));
// 		free(arr);
// 	free_stack(&stackA);
// 	return 0;
	
// }

