#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 9

#endif

char    *readline(int fd)
{
    char *buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer || fd < 0)
        return NULL;
    ssize_t len = read(fd, buffer, BUFFER_SIZE);
    if (len <= 0)
    {
        free(buffer);
        return NULL;    
    }
    buffer[len] = '\0';    
    printf("%ld\n", len);
    return buffer;
}
// char    extract_line()
// {

// }

char *ft_get_next_line(int fd)
{
    
}

int main(void)
{
    int fd = open("foo.txt", O_RDONLY);

    printf("%d\n", fd);
    printf("%s\n", readline(fd));
    close(fd);
    return 0;
}