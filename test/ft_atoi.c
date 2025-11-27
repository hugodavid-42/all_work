/* atoi return an int value parsed from the source string, behavior based on strtol as described in manual.*/

#include <stdio.h>

int ft_strlen(char *str)
{
	int count;

	count = 0;
	while(str[count] != '\0')
	{
		count ++;
	}
	return count;
}

int	ft_atoi(char *s)
{
	int res;
	int i;
	int sign;

	sign = 1;
	i = 0;
	res = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Mauvais Nombre d'argument\n");
		return 0;
	}

	printf("%d\n", ft_atoi(argv[1]));
	return 0;
}	