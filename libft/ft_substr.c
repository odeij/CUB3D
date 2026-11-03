/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamaled <ojamaled@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:03:00 by ojamaled          #+#    #+#             */
/*   Updated: 2026/08/09 22:15:00 by ojamaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	sublen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	sublen = slen - start;
	if (sublen > len)
		sublen = len;
	sub = malloc(sublen + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, sublen);
	sub[sublen] = '\0';
	return (sub);
}
