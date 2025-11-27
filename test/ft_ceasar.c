/* rot 13 display string in first argument applying a code caesar of 13, \n at end */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_index(char c)
{
	int i = 0;
	while ((c + i >= 'a' && c + i <= 'z') || (c + i >= 'A' && c + i <= 'Z'))
	{
		if (i == 13)
			return i;
		i ++;
	}
	int j = i - 26;
	while (i != 13)
	{
		j++;
		i++;
	}
	return (j);


}

void	ft_ceasar_13(char *str)
{

	int i = 0;

	while(str[i] != '\0')
	{
		ft_putchar(str[i] + ft_index(str[i]));
		i ++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("can accept only on string");
		return 0;
	}
	ft_ceasar_13(argv[1]);
	return 0;
}