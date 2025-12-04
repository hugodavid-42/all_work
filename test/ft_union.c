#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_union(char *s1, char *s2)
{
	int flag[127] = {0};
	
	while(*s1)
	{
		if(flag[(int)*s1] == 0)
		{
			ft_putchar(*s1);
			flag[(int)*s1] = 1;
		}
		s1++;
	}
	while(*s2)
	{
		if(flag[(int)*s2] == 0)
		{
			ft_putchar(*s2);
			flag[(int)*s2] = 1;
		}
		s2++;
	}
}


int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "2 strings allowed", 17);
	}
	
	ft_union(argv[1], argv[2]);

	return 0;
}