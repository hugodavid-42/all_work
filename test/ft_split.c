/*split ' ' '\t' '\n' split source string into strings that are separated by the start or end of the source or ' ', '\t' or '\n', return a malloc'ed array of the resulted string.*/

#include <stdio.h>
#include <stdlib.h>

int separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return(0);

}

int ft_strlen(char *s, int start)
{
	int count;

	count = 0;
	while (!separator(s[start]) && s[start] != '\0')
	{
		count ++;
		start ++;
	}
	return count;
}

int ft_wordCount(char *s)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while(s[i] != '\0')
	{
		while(separator(s[i]))
			i ++;
		if (s[i])
		{
			count ++;
			while(s[i] && !separator(s[i]))
				i ++;
		}
	}
	return (count);
}

char *extract_line(char *s, int start)
{
	char *word;
	int i;

	i = 0;
	word = malloc((ft_strlen(s, start) + 1) * sizeof(char));
	if (!word)
		return NULL;
	while (s[start + i] != '\0' && !separator(s[start + i]))
	{
		word[i] = s[start + i];
		i ++;
	}
	word[i] = '\0';
	return word;
}

char	**ft_split(char *s)
{
	int word;
	char **dst;
	int start;

	start = 0;
	word = 0;
	dst = (char **)malloc(sizeof(char *) * (ft_wordCount(s) + 1));
	if (!dst)
		return NULL;
	while(word < ft_wordCount(s))
	{
		while(separator(s[start]))
			start ++;
		if(!separator(s[start]))
		{
			dst[word] = extract_line(s, start);
		}
		word ++;
		start += ft_strlen(s, start);
	}
	dst[word] = '\0';
	return dst;
}

int main(void)
{
	char *s = "Hello World, \n42\t thats all";
	printf("%d\n", ft_wordCount(s));


	char **dst= ft_split(s);
	while(*dst)
	{
		char *line = *dst;
		printf("%s\n", line);
		free(dst);
		dst ++;
	}
	return 0;
}