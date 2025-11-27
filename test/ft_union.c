#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_union(char *s1, char *s2)
{
	char tmp;
	int flag[256] = {0};
	int i;

	while(*s1)
	{
		tmp = *s1;
		i = 1;
		while (s1[i] != '\0')
		{
			if (tmp != s1[i] && flag[(int)tmp] == 0)
			{
				ft_putchar(tmp);
				flag[(int)tmp] = 1;
			}
			i ++;
		}
		s1 ++;
	}
	while(*s2)
	{
		tmp = *s2;
		i = 1;
		while (s2[i] != '\0')
		{
			if (tmp != s2[i] && flag[(int)tmp] == 0)
			{
				ft_putchar(tmp);
				flag[(int)tmp] = 1;
			}
			i ++;
		}
		s2 ++;
	}
}


int main(void)
{
	char *s1 = "kabcdefg";
	char *s2 = "abcdefla";
	
	ft_union(s1, s2);

	return 0;
}