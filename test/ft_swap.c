
/* swap swap int values between pointers a and b.*/
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


int main (void)
{
	int a = 10;
	int b = 188;

	printf("Before -> Value a = %d || Value b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("Before -> Value a = %d || Value b = %d\n", a, b);

	return 0;
}