#include "pushswap.h"
#include <stdio.h>

/*============ Find moove ==================*/

// int findDoubleMoove(Stack *stackA, Stack *stackB)
// {

// }

int mediumSort(Stack **stackA, Stack **stackB)
{
	int halfSize = ft_lstlen(*stackA) / 2;
	int i = 0;
	while(i < halfSize)
	{
		ft_pushAndPopA(stackB, stackA);
		i ++;
	}
	printStack(*stackA);
	printStack(*stackB);
	insertionSort(stackB, stackA);
	printStack(*stackA);

	return 0;

}




// int main(void)
// {
// 	int size = 10;
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

// 	mediumSort(&stackA, &stackB);
// 	printf("Disorder = %f\n", compute_disorder(stackA));
// 	return 0;
	
// }

