/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:03:51 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/20 19:16:50 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <unistd.h>
#include <stdlib.h>

/* Utils */
char	*ft_strchr_spc(char * str, char sep);
int		ft_strlen(char *str);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(char *str);


/* GetNextLine */
char	*get_next_line(int fd);
char	*extract_line(char **stash);

#endif