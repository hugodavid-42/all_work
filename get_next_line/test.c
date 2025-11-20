#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 35
#endif

char *ft_strchr(char *str, char sep)
{
    if (!str) 
        return NULL;
    while (*str)
    {
        if (*str == sep)
            return str;
        str++;
    }
    return NULL;
}

int ft_strlen(char *str)
{
    int count = 0;
    if (!str) 
        return 0;
    while (str[count] != '\0')
        count++;
    return count;
}


char    *ft_strdup(char *s)
{
    size_t len = ft_strlen(s);
    char *dup = malloc(len + 1);
    int i;
    if (!dup) 
        return NULL;

    i = 0;
    while(i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return dup;
}

char *ft_strjoin(char *stash, char *buffer)
{
    int size_dst = ft_strlen(stash) + ft_strlen(buffer);
    char *dst = malloc(size_dst + 1);
    if (!dst)
        return NULL;

    char *start = dst;
    if (stash)
        while (*stash)
            *dst++ = *stash++;
    if (buffer)
        while (*buffer)
            *dst++ = *buffer++;
    *dst = '\0';

    return start;
}

//char *extract_line()
char    *extract_line(char **stash)
{
    if (!*stash || **stash == '\0') 
        return NULL;

    char *newline = ft_strchr(*stash, '\n');
    size_t len = newline ? (newline - *stash + 1) : ft_strlen(*stash);

    char *line = malloc(len + 1);
    if (!line) 
        return NULL;
    for (size_t i = 0; i < len; i++)
        line[i] = (*stash)[i];
    line[len] = '\0';

    // Reste après la ligne
    size_t rest_len = ft_strlen(*stash + len);
    char *rest = rest_len ? ft_strdup(*stash + len) : NULL;
    free(*stash);
    *stash = rest;

    return line;
}

char *ft_get_next_line(int fd)
{
    static char *stash;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    return extract_line(&stash);
}

int main(void)
{
    int fd = open("foo.txt", O_RDONLY);
    if (fd == -1) return 1;

    char *line;
    while ((line = ft_get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}