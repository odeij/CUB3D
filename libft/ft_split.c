/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamaled <ojamaled@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:03:00 by ojamaled          #+#    #+#             */
/*   Updated: 2026/08/09 22:15:00 by ojamaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, size_t *idx)
{
	size_t	start;

	while (s[*idx] == c)
		(*idx)++;
	start = *idx;
	while (s[*idx] && s[*idx] != c)
		(*idx)++;
	return (ft_substr(s, start, *idx - start));
}

static void	free_split(char **arr, int n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	idx;
	int		nw;
	int		i;

	if (!s)
		return (NULL);
	nw = count_words(s, c);
	arr = malloc(sizeof(char *) * (nw + 1));
	if (!arr)
		return (NULL);
	idx = 0;
	i = 0;
	while (i < nw)
	{
		arr[i] = get_word(s, c, &idx);
		if (!arr[i])
			return (free_split(arr, i), NULL);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
