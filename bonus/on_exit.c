/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:27:29 by samjaabo          #+#    #+#             */
/*   Updated: 2023/03/04 22:13:39 by samjaabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char **map, int p_exit)
{
	if (map)
		ft_clear(map);
	exit(p_exit);
}

void	ft_error(const char *msg, char **map)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	ft_exit(map, 1);
}

char	*ft_clear(char **ar)
{
	char	**cp;

	if (!ar)
		return (NULL);
	cp = ar;
	while (*ar)
		free(*ar++);
	free(cp);
	return (NULL);
}

void	ft_is_not_null(t_widget *wid, int part)
{
	if (part == 1 && (!wid->collect_img || !wid->exit_img || !wid->ground_img
		|| !wid->wall_img || !wid->window || !wid->self))
		ft_error("mlx0 fail returns NULL", wid->map);
	else if (part == 0 && (!wid->collect_1 || !wid->exit_1 || !wid->enemy_0 || !wid->enemy_1
		|| !wid->player_to_left || !wid->player_to_right))
		ft_error("mlx1 fail returns NULL", wid->map);
}

int	ft_destroy(t_widget *wid)
{
	mlx_clear_window(wid->self, wid->window);
	mlx_destroy_window(wid->self, wid->window);
	ft_exit(wid->map, 0);
	return (0);
}
