/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamaled <ojamaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:21:10 by ojamaled          #+#    #+#             */
/*   Updated: 2026/11/04 21:31:56 by ojamaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_extension(char *path)
{
    char    *name;
    int     len;

    name = ft_strrchr(path, '/'); //searches path for the last /.
    if (name)
        name = name + 1;
    else
        name = path;

    len = ft_strlen(name);
    if (len <= 4)
        return (0);
    return (ft_strncmp(name + len - 4, ".cub", 4) == 0);
}//1 = ok, 0 = wrong
