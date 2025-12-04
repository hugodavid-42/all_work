/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:57:32 by hdavid            #+#    #+#             */
/*   Updated: 2025/12/04 15:49:25 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

float compute_disorder(Stack *head)
{
    Stack *current = head;
    Stack *next;
    float mistake = 0;
    float total_pairs = 0;

    while(current->next)
    {
        next = current->next;
		while(next)
		{
			if(current->data > next->data)
			{
				mistake ++;
				break ;
			}
			next = next->next;
		}
		current = current->next;
		total_pairs ++;
    }
    return(mistake / total_pairs);
}

// int main(void)
// {
// 	Stack *stackA = createNode(1);
// 	stackA->next =createNode(2);
// 	stackA->next->next = createNode(53);
// 	stackA->next->next->next = createNode(4);
// 	stackA->next->next->next->next = createNode(5);
// 	stackA->next->next->next->next->next = createNode(60);

// 	printf("Disorder = %f\n", compute_disorder(stackA));

// 	return 0;
// }
