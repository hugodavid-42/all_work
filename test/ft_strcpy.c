/* strcpy copy s2 into s1 ('\0' included)*/

#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *s1, char *s2)
{
    char *dst = s1;
    while (*s2)
    {
        *dst++ = *s2++;
    }
    *dst = '\0';
    return s1;
}

int main(void)
{
    char s1[20] = "Hello";
    char s2[] = "First Try";
    printf("%s\n", ft_strcpy(s1, s2));
    return 0;
}
