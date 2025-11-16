/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:28:07 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/10 14:09:57 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int		i;
	int		count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	word_length(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		len++;
	}
	return (len);
}

static char	*extract(char const *s, int start, int len)
{
	char	*new_word;
	int		i;

	new_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_word[i] = s[start + i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

static void	ft_free(char **total, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(total[i]);
		i++;
	}
	free(total);
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**total;
	int		word;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	word = 0;
	count_words = count_word(s, c);
	total = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!total)
		return (NULL);
	while (word < count_words)
	{
		while (s[start] && s[start] == c)
			start++;
		total[word] = extract(s, start, word_length(s, c, start));
		if (!total[word])
			ft_free(total, word);
		start += word_length(s, c, start);
		word++;
	}
	total[word] = NULL;
	return (total);
}
