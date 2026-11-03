/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamaled <ojamaled@student.42beirut.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:03:00 by ojamaled          #+#    #+#             */
/*   Updated: 2026/08/09 22:15:00 by ojamaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				stop;
	unsigned int	nb;

	len = num_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	stop = 0;
	nb = (unsigned int)n;
	if (n < 0)
	{
		str[0] = '-';
		nb = (unsigned int)(-n);
		stop = 1;
	}
	while (len-- > stop)
	{
		str[len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}
