/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamaled <ojamaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:23:51 by ojamaled          #+#    #+#             */
/*   Updated: 2026/11/04 21:56:50 by ojamaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

static char *read_all(int fd)
{
    char    buf[BUF_SIZE + 1];
    char    *content;
    char    *tmp;
    int     n;

    content = ft_strdup("");
    n = 1;
    while (content && n > 0)
    {
        n = read(fd, buf, BUF_SIZE);
        if (n < 0)
        {
            free(content);
            return (NULL);
        }
        buf[n] = '\0';
        tmp = ft_strjoin(content, buf);
        free(content);
        content = tmp;
    }
    return (content);
} // whole file -> one string
