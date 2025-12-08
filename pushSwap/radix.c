/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:07:40 by psi-mous          #+#    #+#             */
/*   Updated: 2025/12/08 14:15:28 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pushswap.h"

int	power2(int bit)
{
	int	result;

	result = 1;
	while (bit > 0)
	{
		result *= 2;
		bit--;
	}
	return (result);
}

int	get_bit(int value, int bit)
{
	int	divisor;

	divisor = power2(bit);
	return ((value / divisor) % 2);
}

int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void	radix(Stack **stackA, Stack **stackB)
{
	int	max_bits;
	int	bit;
	int	i;
	int	initial_size;
	int	value;

	buildArray(*stackA);
	bit = 0;
	max_bits = count_bits(ft_lstlen(*stackA));
	while (bit < max_bits)
	{
		i = 0;
		initial_size = ft_lstlen(*stackA);
		while (i < initial_size)
		{
			value = (*stackA)->index;
			if (get_bit(value, bit) == 0)
				pb(stackA, stackB);
			else
				ra(stackA);
			i++;
		}
		while (*stackB)
			pa(stackA, stackB);
		bit++;
	}
}

int main(void)
{
	int size = 300;
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
	printf("Disorder = %f\n", compute_disorder(stackA));
	//printf("%d\n", sizeChunk(stackA));

	printStack(stackA);

	insertionSort(&stackA, &stackB);
    //printf("\nTotal moove : %i\n", chunkSort(&stackA, &stackB));
	// printf("\nTotal moove : %i\n", insertionSort(&stackA, &stackB));

    printf("\n===========================================\n");
	printStack(stackB);
	printStack(stackA);
	printf("Disorder = %f\n", compute_disorder(stackA));
		free(arr);
	free_stack(&stackA);
	return 0;
	
}