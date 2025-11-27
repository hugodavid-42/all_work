
/*print s1 from s2 if argc == 3, print s1 if every of its character is found in order in s2, n\ at end.*/
#include <stdio.h>

int	ft_prtcmp(char *s1, char *s2)
{
	while(*s1)
	{
		if (*s1 != *s2)
			return 0;
		s1++;
		s2++;
	}
	return 1;
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Mauvais nombre d'argument");
		return 0;
	}
	if (ft_prtcmp(argv[1], argv[2]))
		printf(argv[1]);

	return 0;

}
