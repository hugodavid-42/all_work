#include "get_next_line.h"

/* ft_strjoin qui libère l'ancien stash pour éviter la fuite */
char *ft_strjoin_free(char *stash, const char *buffer)
{
    size_t len1 = ft_strlen(stash);
    size_t len2 = ft_strlen(buffer);
    char *dst = malloc(len1 + len2 + 1);
    if (!dst)
        return NULL;

    size_t i = 0;
    for (; i < len1; i++)
        dst[i] = stash[i];
    for (size_t j = 0; j < len2; j++)
        dst[i + j] = buffer[j];
    dst[len1 + len2] = '\0';

    /* libère l'ancien stash */
    free(stash);
    return dst;
}

/* --- extraction de ligne --- */
char *extract_line(char **stash)
{
    size_t len;
    size_t rest_len;
    char *line;
    char *rest;
    char *newline; 

    if (!stash || !*stash || **stash == '\0')
        return NULL;
    newline = ft_strchr(*stash, '\n');
    if (!newline)
        len = ft_strlen(*stash);
    else
        len = newline - *stash + 1;
    line = malloc(len + 1);
    if (!line)
        return NULL;
    ft_memcpy(line, *stash, len);
    line[len] = '\0';
    rest_len = ft_strlen(*stash + len);
    if (!rest_len)
        rest = NULL;
    else
        rest = ft_strdup(*stash + len);

    free(*stash);
    *stash = rest;
    return line;
}

char *read_file(int fd, char *stash, char *buffer)
{
    ssize_t bytes_read;

    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            free(buffer);
            free(stash);
            return NULL;
        }
        if (bytes_read == 0)
            break;
        buffer[bytes_read] = '\0';
        stash = ft_strjoin_free(stash, buffer);
    }
    free (buffer);
    return stash;
}

/* --- GNL --- */

char *get_next_line(int fd)
{
    static char *stash;
    char *buffer;

    buffer = malloc(BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
    {
        free(buffer);
        return NULL;
    }
    stash = read_file(fd, stash, buffer);
    return extract_line(&stash);
}

/* --- test --- */
// int main(void)
// {
//     int fd = open("foo.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("open");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return 0;
// }
