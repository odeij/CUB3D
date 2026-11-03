/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamaled <ojamaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:19:26 by ojamaled          #+#    #+#             */
/*   Updated: 2026/11/03 20:05:57 by ojamaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    free_split(char **arr)
{
    int i;

    i = 0;
    if (arr == NULL)
        return;

    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void    free_game(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        free(game->config.tex_path[i]);
        game->config.tex_path[i] = NULL;
        i++;
    }
    free_split(game->map.grid);
    game->map.grid = NULL;
    free_split(game->lines);
    game->lines = NULL;
}

void    error_exit(t_game *game, char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(msg, 2);
    free_game(game);
    exit(1);
}
