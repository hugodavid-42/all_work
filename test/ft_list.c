/*lstsize return size of chained list, include .h file.*/

#include "pointh.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_lstsize(t_list *list)
{
	int i = 0;
	while(list)
	{
		list = list->next;
		i ++;
	}
	return i;
}

t_list *ft_lstnew(void *data)
{
	t_list *newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return(NULL);
	newnode->content = data;
	newnode->next = NULL;
	return (newnode);
}

void printList(t_list *list)
{
	while(list)
	{	
		int *value = (int *)list->content;
		if (list->next != NULL)
			printf("%d-->", *value);
		else 
			printf("%d\n", *value);
		list = list->next;
	}
}

/*list_remove_if ft_list_remove_if: remove elements from the list that are equal with data_ref. cmp returns 0 if both arguments are equal. free the element but NOT its data. DO NOT include .h file.*/

int ft_intcmp(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

void add(void *a)
{
	printf("%d\n", *(int *)a *10);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
    t_list *current = *begin_list;
    t_list *prev = NULL;

    while (current)
    {
        t_list *next_node = current->next;

        if (cmp(data_ref, current->content) == 0)
        {
            if (prev)
                prev->next = next_node;
            else
                *begin_list = next_node;
            free(current);
        }
        else
        {
            prev = current;
        }
        current = next_node;
    }
}

/*lstiteri apply function pointed to to every element of the list.*/

void	ft_lstiter(t_list *list_begin, void (*f)(void *))
{
	if (!list_begin)
		return ;

	while(list_begin)
	{
		f(list_begin->content);
		list_begin = list_begin->next;
	}
}

/*lstsort sort a list based on the return value of the cmp function pointed to. DO NOT include .h file.*/

void	ft_lstsort(t_list **list, int (*cmp)(void *, void *))
{
	t_list *current = *list;
	t_list *next_node;
	t_list *dst = NULL;
	void *tmp;

	while(current->next != dst)
	{
		next_node = current->next;
		if(cmp(current->content, next_node->content) > 0)
		{
			tmp = current->content;
			current->content = next_node->content;
			next_node->content = tmp;
		}
		current = current->next;
	}
	dst = current;
}

// void ft_lstsort(t_list **list, int (*cmp)(void *, void *))
// {
//     if (!list || !*list)
//         return;

//     t_list *current = *list;
//     t_list *next_node = NULL;
//     t_list *last = NULL;
// 	void *temp;

//     while (current->next != last)
//     {
//         next_node = current->next;
//         if (cmp(current->content, next_node->content) > 0)
//         {
//             temp = current->content;
//             current->content = next_node->content;
//             next_node->content = temp;
//         }
//         current = current->next;
//     }
//     last = current;
// }

int main(void)
{
	int data1= 10;
	int data2= 20;
	int data3= 30;
	int data4= 40;
	t_list* head = ft_lstnew(&data1);
    head->next = ft_lstnew(&data3);
    head->next->next = ft_lstnew(&data2);
    head->next->next->next = ft_lstnew(&data4);

	printf("%d\n", ft_lstsize(head));
    printList(head);

	// ft_list_remove_if(&head, &data3, ft_intcmp);
	// printList(head);

	ft_lstiter(head, add);

	printList(head);
	ft_lstsort(&head, ft_intcmp);
	printList(head);

	return 0;


}