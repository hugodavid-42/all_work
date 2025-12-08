
#include <stdbool.h>
#include "pushswap.h"
#include <stdio.h>

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

int	findClosestPos(Stack **stackA, int min, int max)
{
	int move = 0;
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
		{
            ra(stackA);
			move ++;
		}
    } 
    else 
    {
        int steps = len - i;
        while (steps-- > 0)
		{ 
            rra(stackA);
			move ++;
		}
    }
	return move;
}

void    pushA(Stack **stackA, Stack **stackB)
{
    int chunk = sizeChunk(*stackA);
    int i = 0;
    int min = 0;
    int max = chunk;

    while(*stackA)
    {
		i = 0;
        while(i < chunk && *stackA)
        {
			int pos = findClosestPos(stackA, min, max);
            if(pos == 0)
            {
                pb(stackA, stackB);
				i ++;
            }
        }
        min = max;
        max += chunk;
    }

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

void   pushBackB(Stack **stackA, Stack **stackB)
{
	if (!(*stackB))
		return;
    while(*stackB)
    {
        int max = ft_lstlen(*stackB) - 1;
        if((*stackB)->index == max)
            pa(stackA, stackB);
        else if(posOfMax(*stackB, max) <= max / 2)
            rb(stackB);
        else
            rrb(stackB);
    }
}

void chunkSort(Stack **stackA, Stack **stackB)
{
	if (!(*stackA) || !(*stackA)->next)
		return;
	buildArray(*stackA);
    pushA(stackA, stackB);
	pushBackB(stackA, stackB);
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

//     chunkSort(&stackA, &stackB);
// 	// printf("\nTotal moove : %i\n", insertionSort(&stackA, &stackB));

//     printf("\n===========================================\n");
// 	printStack(stackB);
// 	printStack(stackA);
// 	printf("Disorder = %f\n", compute_disorder(stackA));
// 		free(arr);
// 	free_stack(&stackA);
// 	return 0;
	
// }

