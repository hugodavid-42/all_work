
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
    int len = ft_lstlen(stackA);
    int chunks = len / 10;
    if (len % 10 != 0)
        chunks ++;
    return len / chunks;
}

// void findClosestPos(Stack **stackA, int min, int max)
// {
//     int i = 0;
//     int len = ft_lstlen(*stackA);

//     while(*stackA)
//     {
//         if ((*stackA)->index >= min && (*stackA)->index < max)
//             break ;
//         i ++;
//         *stackA = (*stackA)->next;
//     }
//     if (len / 2 < i)
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


bool findClosestPos(Stack **stackA, int min, int max)
{
    if (!stackA || !*stackA) return false;

    // Parcours avec un pointeur temporaire
    Stack *tmp = *stackA;
    int i = 0;

    while (tmp && !(tmp->index >= min && tmp->index < max)) {
        i++;
        tmp = tmp->next;
    }

    if (!tmp) {
        // Aucun élément dans le range
        return false;
    }

    // Choisir le sens minimal de rotation
    int len = ft_lstlen(*stackA);
    if (i <= len / 2) {
        while (i-- > 0) 
            ra(stackA);         // avance i fois
    } 
    else 
    {
        int steps = len - i;                 // recule len - i fois
        while (steps-- > 0) 
            rra(stackA);
    }

    return true;
}


void    chunkSort(Stack **stackA, Stack **stackB)
{
    int chunk = sizeChunk(*stackA);
    int i = 0;
    int min = 0;
    int max = min + chunk;

    while(*stackA)
    {
        i = 0;
        while(i < chunk && *stackA)
        {
            findClosestPos(stackA, min, max);
            if((*stackA)->index >= min && (*stackA)->index < max)
            {
                pb(stackA, stackB);
                i ++;  
            }
        }
        min = max;
        max = min + chunk;
    }
}

int main(void)
{
	int size = 22;
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
    i = 0;
    printStack(stackA);
	int *nbr = buildArray(stackA);
    while(i < size)
    {
        printf("%d --> ", nbr[i]);
        i ++;
    }
    printf("\n%d\n", sizeChunk(stackA));
    chunkSort(&stackA, &stackB);
    printStack(stackA);
    printStack(stackB);
	return 0; 
}

