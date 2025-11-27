/* ulstr 	if argc == 2, display argv[1] swapping lowercase into uppercase and vice-versa, \n at end */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert(char *s)
{
	while(*s)
	{
		if(*s >= 'a' && *s <= 'z')
			ft_putchar(*s - 32);
		else if(*s >= 'A' && *s <= 'Z')
			ft_putchar(*s + 32);
		else
			ft_putchar(*s);
		s++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("can accept only on string");
		return 0;
	}
	ft_convert(argv[1]);
	return 0;

}