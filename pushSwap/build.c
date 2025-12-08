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
        printf("%d -> ", stack->data);
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

/*============== Normalize =================*/

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


void free_stack(Stack **stack) 
{
    Stack *cur = *stack;
    while (cur) 
	{
        Stack *next = cur->next;
        free(cur);
        cur = next;
    }
    *stack = NULL;
}

