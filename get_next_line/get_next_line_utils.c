#include "get_next_line.h"

/* --- utils --- */
char *ft_strchr(const char *str, char sep)
{
    if (!str)
        return NULL;
    while (*str)
    {
        if (*str == sep)
            return (char*)str;
        str++;
    }
    return NULL;
}

size_t ft_strlen(const char *str)
{
    size_t count = 0;
    if (!str)
        return 0;
    while (str[count] != '\0')
        count++;
    return count;
}

char *ft_strdup(const char *s)
{
    if (!s) return NULL;
    size_t len = ft_strlen(s);
    char *dup = malloc(len + 1);
    if (!dup) return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return dup;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d; 
    const unsigned char *s;
    
    s = (const unsigned char *)src;
    d = (unsigned char *)dest;
    if (!d || !s)
        return NULL;
    size_t i = 0;
    while (i < n) {
        d[i] = s[i];
        i++;
    }

    return dest;
}