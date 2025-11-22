#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 35
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


char *ft_strchr(const char *str, char sep);
size_t ft_strlen(const char *str);
char *ft_strdup(const char *s);
char *ft_strjoin_free(char *stash, const char *buffer);
char *extract_line(char **stash);
char *get_next_line(int fd);
void *ft_memcpy(void *dest, const void *src, size_t n);

#endif